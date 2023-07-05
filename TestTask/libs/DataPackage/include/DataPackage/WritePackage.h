#ifndef WRITE_PACKAGE_H
#define WRITE_PACKAGE_H

#include "DataPackage/CommonData.h"

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>

std::random_device static rd;
std::mt19937 static gen(rd());

template <size_t T>
class FilePackageWrite {
	public:
	FilePackageWrite()
	{}

	void get_File_Messeges(std::string const& namefile)
	{
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
		if(buffer.size() != 0) {
			Messeges_data.emplace_back(Msg<T>(buffer, ++id));
			buffer.clear();
		}
	}

	void shuffle_write_messeges(std::string const& namefile)
	{
		std::vector<std::reference_wrapper<const Msg<T>>> v(Messeges_data.cbegin(), Messeges_data.cend());
		std::shuffle(v.begin(), v.end(), gen);

		std::ofstream file;
		file.open(namefile, std::ios::trunc);
		if(!file.is_open()) {
			throw MyException("файл не открылся");
		}

		for(int i = 0; i != v.size(); i++) {
			write_Msg_file(v.at(i).get(), file);
		}

		file.close();
	}

	void write_messeges(std::string& filename)
	{
		std::ofstream file;
		file.open(filename, std::ios::trunc);
		if(!file.is_open()) {
			throw MyException("файл не открылся");
		}

		for(auto i: Messeges_data) {
			write_Msg_file(i, file);
		}
		file.close();
	}

	void clear()
	{
		Messeges_data.clear();
	}

	Messeges<T> const& get_Messeges()
	{
		return Messeges_data;
	}

private:

	void write_Msg_file(Msg<T> msg, std::ofstream& file)
	{
		file.write((char*)&Head, sizeof(Head));
		file.write((char*)&(msg.get_id()), sizeof(msg.get_id()));
		file.write(msg.get_data(), T);
		file.write((char*)&Tail, sizeof(Tail));
	}

	uint16_t Head = 0xBABA;
	uint16_t Tail = 0xDEDA;
	Messeges<T> Messeges_data;
};



#endif
