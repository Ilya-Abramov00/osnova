#ifndef READ_PACKAGE_H
#define READ_PACKAGE_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <random>
#include <cstdint>

#include "DataPackage/CommonData.h"

enum class State { Idle, Magicbegin, Idcollecting, Datacollecting, Magicend };

template <size_t T>
class StateMachine {
public:
	StateMachine(uint16_t Head, uint16_t Tail) : state(State::Idle), Head(Head), Tail(Tail)
	{}

	void ReadMesseges(std::vector<char> const& bufferfile, Messeges<T>& Messeges_data)
	{
		state = State::Magicbegin;

		std::string data;
		data.reserve(T + 2);

		for(int i = 0; i != bufferfile.size(); i++) {
			write_magic(bufferfile.at(i));

			switch(state) {
			case(State::Magicbegin):

				func_Magicbegin();

				break;

			case(State::Idcollecting):
				func_Idcollecting();

				break;

			case(State::Datacollecting):
				func_Datacollecting(data, bufferfile.at(i), Messeges_data);
				break;

			case(State::Magicend):
				state = State::Magicbegin;
				break;
			}
		}
		if(state == State::Magicend) {
			state = State::Idle;
		}
		return;
	}

	State get_state()
	{
		return state;
	}

private:
	State state;
	uint16_t Head;
	uint16_t Tail;
	uint16_t magic;
	uint8_t* magBuf = reinterpret_cast<uint8_t*>(&magic);
	bool flag       = 1;
	uint16_t id     = 0;
	char count_id   = 0;

	void func_Datacollecting(std::string& data, char const& data_is_bufferfile, Messeges<T>& Messeges_data)
	{
		data += data_is_bufferfile;
		if(magic == Tail) {
			state = State::Magicend;
			data.pop_back();
			data.pop_back();
			Messeges_data.push_back(Msg<T>(data, id));
			data.clear();
		}
	}
	void func_Idcollecting()
	{
		count_id++;
		if(count_id == 2) {
			id       = magic;
			state    = State::Datacollecting;
			count_id = 0;
		}
	}
	void func_Magicbegin()
	{
		if(magic == Head) {
			state = State::Idcollecting;
		}
	}
	void write_magic(char const data_is_bufferfile)
	{
		if(flag) {
			magBuf[1] = data_is_bufferfile;
			flag      = 0;
		}
		else {
			magBuf[0] = magBuf[1];
			magBuf[1] = data_is_bufferfile;
		}
	}
};

template <size_t T>
class FilePackageRead {
public:
	FilePackageRead(Messeges<T> Messeges_data) : Messeges_data(Messeges_data)
	{}

	FilePackageRead()
	{}

	void read_messeges(std::string const& namefile)
	{
		StateMachine<T> statemachine(Head, Tail);
		statemachine.ReadMesseges(readfullfile(namefile), Messeges_data);
		if(statemachine.get_state() != State::Idle) {
			throw MyException("ошибка состояния StateMachine");
		}
	}

	void sort_Messeges()
	{
		Messeges_data.sort();
	}

	void clear()
	{
		Messeges_data.clear();
	}

	std::string Data_Repoirter()
	{
		std::string string_data = "";
		auto end                = Messeges_data.end();
		auto begin              = Messeges_data.begin();

		while(begin != end) {
			string_data.append(begin->get_data(), T);
			begin++;
		}

		char c     = '^';
		auto anEnd = string_data.end();
		anEnd -= T;
		string_data.erase(std::remove(anEnd, string_data.end(), c), string_data.end());

		return string_data;
	}

	Messeges<T> const& get_Messeges()
	{
		return Messeges_data;
	}

private:
	uint16_t Head = 0xBABA;
	uint16_t Tail = 0xDEDA;
	Messeges<T> Messeges_data;
};

#endif
