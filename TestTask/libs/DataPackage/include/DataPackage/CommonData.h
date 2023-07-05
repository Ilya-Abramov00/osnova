#ifndef COMMON_DATA_H
#define COMMON_DATA_H



#include <iostream>
#include <list>



class MyException : public std::runtime_error {
public:
	MyException() : runtime_error("File not found")
	{}
	MyException(std::string const& msg) : runtime_error(msg.c_str())
	{}
};

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

#endif
