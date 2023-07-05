#include <gtest/gtest.h>

#include "DataPackage/ReadPackage.h"
#include "DataPackage/WritePackage.h"
#include "DataPackage/CommonData.h"

using namespace std;

TEST(WriteDataPackage, write_messeges_data_1)
{
	std::string str_1 = "string_test/file_5.txt";
	std::string str_2 = "string_test/file_6.txt";

	string data_test("123");

	write_string(data_test, str_1);

	FilePackageWrite<3> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	auto data_file = readfullfile(str_2);

	ASSERT_TRUE((uint8_t)data_file[0] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[1] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[2] == 0x01);
	ASSERT_TRUE((uint8_t)data_file[3] == 0x00);
	ASSERT_TRUE((char)data_file[4] == data_test[0]);
	ASSERT_TRUE((char)data_file[5] == data_test[1]);
	ASSERT_TRUE((char)data_file[6] == data_test[2]);
	ASSERT_TRUE((uint8_t)data_file[7] == 0XDA);
	ASSERT_TRUE((uint8_t)data_file[8] == 0XDE);
}

TEST(WriteDataPackage, write_messeges_data_2)
{
	std::string str_1 = "string_test/file_5.txt";
	std::string str_2 = "string_test/file_6.txt";

	string data_test("12345");

	write_string(data_test, str_1);

	FilePackageWrite<3> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	auto data_file = readfullfile(str_2);
	ASSERT_TRUE((uint8_t)data_file[0] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[1] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[2] == 0x01);
	ASSERT_TRUE((uint8_t)data_file[3] == 0x00);
	ASSERT_TRUE((char)data_file[4] == data_test[0]);
	ASSERT_TRUE((char)data_file[5] == data_test[1]);
	ASSERT_TRUE((char)data_file[6] == data_test[2]);
	ASSERT_TRUE((uint8_t)data_file[7] == 0XDA);
	ASSERT_TRUE((uint8_t)data_file[8] == 0XDE);

	ASSERT_TRUE((uint8_t)data_file[9] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[10] == 0XBA);
	ASSERT_TRUE((uint8_t)data_file[11] == 0x02);
	ASSERT_TRUE((uint8_t)data_file[12] == 0x00);
	ASSERT_TRUE((char)data_file[13] == data_test[3]);
	ASSERT_TRUE((char)data_file[14] == data_test[4]);
	ASSERT_TRUE((char)data_file[15] == '^');
	ASSERT_TRUE((uint8_t)data_file[16] == 0XDA);
	ASSERT_TRUE((uint8_t)data_file[17] == 0XDE);
}
