#include <gtest/gtest.h>

#include "DataPackageWrite/WritePackage.h"
#include "DataPackageRead/ReadPackage.h"

using namespace std;

TEST(DataPackageExeption, 1)
{
	ASSERT_THROW(readfullfile("qdq"), MyException);
}

TEST(DataPackageExeption, 2)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	auto data_test = geniration_string(33, 100, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);
	auto data = read_string(str_2);
	string data_1("мусор");

	data += data_1;
	write_string(data, str_2);

	FilePackageRead<10> filepackageread;

	ASSERT_NO_THROW(
	    filepackageread.read_messeges(str_2)); // при добавке мусора после head исключений не возникает, все ок
}

TEST(DataPackageExeption, 3)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	auto data_test = geniration_string(33, 100, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	auto data = read_string(str_2);

	string musor("musor");

	data.insert(2, musor);

	write_string(data, str_2);

	FilePackageRead<10> filepackageread;

	ASSERT_NO_THROW(
	    filepackageread.read_messeges(str_2)); // при добавлении к полезным данных мусора исключений не возникает, это уязвимость
}