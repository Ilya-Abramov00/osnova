#ifndef COMMON_DATA_H
#define COMMON_DATA_H



#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <random>




class MyException : public std::runtime_error {
public:
	 MyException();
	MyException(std::string const& msg);
};


int random_l(int N);

std::string geniration_string(int n, int N, std::string const & namefile);

std::vector<char> readfullfile(std::string const& namefile);

std::string read_string(std::string const& namefile);

void write_string(std::string& data, std::string const& namefile);





#endif
