#include "DataPackage/CommonData.h"

int random_l(int N)
{
	std::uniform_int_distribution<> dist(1, 10 * N);
	return dist(gen);
}
std::string geniration_string(int n, int N, std::string const& namefile)
{
	std::ofstream file;
	file.open(namefile, std::ios::trunc);
	std::string data = "";

	if(!file.is_open()) {
		throw MyException("файл не открылся");
	}
	for(int i = 0; i != n; i++) {
		data.append(std::string(random_l(N), '*'));
		data.push_back('\n');
	}
	file << data;
	file.close();

	return data;
}

std::vector<char> readfullfile(std::string const& namefile)
{
	std::ifstream file;
	file.open(namefile);

	if(!file.is_open()) {
		throw MyException("файл не открылся");
	}

	file.seekg(0, std::ios::end);
	size_t sizefile = file.tellg();
	file.seekg(0);

	std::vector<char> bufferfile(sizefile);

	file.read(bufferfile.data(), sizefile);

	if(file.fail()) {
		throw MyException("ошибка чтения данных");
	}

	file.close();

	return bufferfile;
}

std::string read_string(std::string const& namefile)
{
	auto data = readfullfile(namefile);
	std::string data_string(data.begin(), data.end());

	return data_string;
}

void write_string(std::string& data, std::string const& namefile)
{
	std::ofstream file;
	file.open(namefile, std::ios::trunc);
	if(!file.is_open()) {
		throw MyException("файл не открылся");
	}
	file << data;

	file.close();
}
