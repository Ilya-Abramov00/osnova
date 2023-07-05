#include <gtest/gtest.h>

#include "DataPackage/ReadPackage.h"
#include "DataPackage/WritePackage.h"
#include "DataPackage/CommonData.h"

using namespace std;
TEST(ReadDataPackage, write_messeges_data_1)
{
	std::string str_1 = "string_test/file_5.txt";
	std::string str_2 = "string_test/file_6.txt";

	string data_test("123");

	write_string(data_test, str_1);

	FilePackageWrite<3> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<3> filepackageread;
	filepackageread.read_messeges(str_2);
	auto dataMesseges = filepackageread.get_Messeges();
	for(auto i: dataMesseges) {
		ASSERT_TRUE(i.get_id() == 1);

		std::string data = i.get_data();
		ASSERT_TRUE(data == data_test);
	}
}

TEST(ReadDataPackage, write_messeges_data_2)
{
	std::string str_1 = "string_test/file_5.txt";
	std::string str_2 = "string_test/file_6.txt";

	string data_test("12345");

	write_string(data_test, str_1);

	FilePackageWrite<3> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<3> filepackageread;
	filepackageread.read_messeges(str_2);
	auto dataMesseges = filepackageread.get_Messeges();
	int count         = 1;

	auto begin = dataMesseges.begin();

	ASSERT_TRUE(begin->get_id() == 1);

	std::string data = begin->get_data();
	ASSERT_TRUE(data == "123");
	begin++;

	ASSERT_TRUE(begin->get_id() == 2);
	data = begin->get_data();
	ASSERT_TRUE(data == "45^");
}
