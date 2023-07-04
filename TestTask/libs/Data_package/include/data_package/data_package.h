#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <random>
#include <cstdint>

std::random_device rd;
std::mt19937 gen(rd());

int random_l(int N);

void geniration_string(int n, int N, std::string const& namefile);

std::vector<char> readfullfile(std::string const& namefile)
{
	std::ifstream file;
	file.open(namefile);

	if(!file.is_open()) {
		throw "файл не открылся";
	}

	file.seekg(0, std::ios::end);
	size_t sizefile = file.tellg();
	file.seekg(0);

	std::vector<char> bufferfile(sizefile);

	file.read(bufferfile.data(), sizefile);

	if(file.fail()) {
		throw "ошибка чтения данных";
	}

	file.close();

	return bufferfile;
}

template <size_t T>

struct Msg {
public:
	Msg(std::string const& data_string, uint16_t const id) : id(id)
	{
		for(int i = 0; i != T; i++) {
			if(i < data_string.size()) {
				data[i] = data_string[i];
			}
			else {
				data[i] = '^';
			}
		}
	}

	uint16_t const& get_id()
	{
		return id;
	}

	char const* get_data()
	{
		return data;
	}

private:
	uint16_t id;
	char data[T];
};

template <size_t T>
bool operator<(Msg<T>& x, Msg<T>& y)
{
	return x.get_id() < y.get_id();
}

template <size_t T>
using Messeges = std::list<Msg<T>>;

template <size_t T>

class File_parser {
public:
	Messeges<T> get_File_Messeges(std::string const& namefile)
	{
		Messeges<T> Messeges_data;
		uint16_t id     = 0;
		auto bufferfile = readfullfile(namefile);
		std::string buffer;
		buffer.reserve(T);

		for(int i = 1; i != bufferfile.size() + 1; i++) {
			buffer.push_back(bufferfile.at(i - 1));

			if(!(i % T)) {
				Messeges_data.emplace_back(Msg<T>(buffer, ++id));
				buffer.clear();
			}
		}
		Messeges_data.emplace_back(Msg<T>(buffer, ++id));
		buffer.clear();
		return Messeges_data;
	}

private:
};

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
	bool flag = 1;
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
class File_Package {
public:
	File_Package(Messeges<T> Messeges_data) : Messeges_data(Messeges_data)
	{}

	File_Package()
	{}

	void write(std::string& filename)
	{
		std::ofstream file;
		file.open(filename, std::ios::trunc);
		if(!file.is_open()) {
			throw "файл не открылся";
		}

		for(auto i: Messeges_data) {
			write_Msg_file(file, i);
		}
		file.close();
	}

	void read(std::string const& namefile)
	{
		StateMachine<T> statemachine(Head, Tail);
		statemachine.ReadMesseges(readfullfile(namefile), Messeges_data);
		if(statemachine.get_state() != State::Idle) {
			throw "ошибка состояния StateMachine";
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
			string_data.append(begin->get_data(),T);
			begin++;
		}

		char c='^';
		auto begin_string=string_data.end();
		begin_string-=T;
			string_data.erase(std::remove(begin_string, string_data.end(), c), string_data.end());

		return string_data;
	}

	void shuffle_write(std::string const& namefile)
	{
		std::vector<std::reference_wrapper<const Msg<T>>> v(Messeges_data.cbegin(), Messeges_data.cend());
		std::shuffle(v.begin(), v.end(), gen);

		std::ofstream file;
		file.open(namefile, std::ios::trunc);
		if(!file.is_open()) {
			throw "файл не открылся";
		}

		for(int i = 0; i != v.size(); i++) {
			write_Msg_file(file, v.at(i).get());
		}

		file.close();
	}

	Messeges<T> const& get_Messeges_data()
	{
		return Messeges_data;
	}

	void write_Msg_file(std::ofstream& file, Msg<T> msg)
	{
		file.write((char*)&Head, sizeof(Head));
		file.write((char*)&msg.get_id(), sizeof(msg.get_id()));
		file.write(msg.get_data(), T);
		file.write((char*)&Tail, sizeof(Tail));
	}

private:
	uint16_t Head = 0xBABA;
	uint16_t Tail = 0xDEDA;
	Messeges<T> Messeges_data;
};

std::string read_string(std::string const& namefile)
{
	std::ifstream file;
	file.open(namefile);
	if(!file.is_open()) {
		throw "файл не открылся";
	}
	char c;
	std::string data = "";

	while(file.get(c)) {
		data += c;
	}
	file.close();
	return data;
}
void write_string(std::string data, std::string const& namefile)
{
	std::ofstream file;
	file.open(namefile, std::ios::trunc);
	if(!file.is_open()) {
		throw "файл не открылся";
	}
	file << data;

	file.close();
}
#endif
