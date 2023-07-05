#include <gtest/gtest.h>

#include "DataPackage/ReadPackage.h"
#include "DataPackage/WritePackage.h"
#include "DataPackage/CommonData.h"

using namespace std;

TEST(data_package, write_messeges_data_1)
{
	std::string str_1 = "string_test/file_5.txt";
	std::string str_2 = "string_test/file_6.txt";

	string data_test("123");

	write_string(data_test, str_1);


	FilePackageWrite<3> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

auto data_file= readfullfile(str_2);

ASSERT_TRUE((uint8_t) data_file[0]==0XBA);
ASSERT_TRUE((uint8_t) data_file[1]==0XBA);
ASSERT_TRUE( (uint8_t)data_file[2]==0x01);
ASSERT_TRUE( (uint8_t)data_file[3]==0x00);
ASSERT_TRUE( (char)data_file[4]==data_test[0]);
ASSERT_TRUE( (char)data_file[5]==data_test[1]);
ASSERT_TRUE( (char)data_file[6]==data_test[2]);
ASSERT_TRUE( (uint8_t)data_file[7]==0XDA);
ASSERT_TRUE( (uint8_t)data_file[8]==0XDE);
}

TEST(data_package, write_messeges_data_2)
{
std::string str_1 = "string_test/file_5.txt";
std::string str_2 = "string_test/file_6.txt";

string data_test("12345");

write_string(data_test, str_1);



FilePackageWrite<3> filepackagewrite;
filepackagewrite.get_File_Messeges(str_1);
filepackagewrite.write_messeges(str_2);

auto data_file= readfullfile(str_2);
ASSERT_TRUE((uint8_t) data_file[0]==0XBA);
ASSERT_TRUE((uint8_t) data_file[1]==0XBA);
ASSERT_TRUE( (uint8_t)data_file[2]==0x01);
ASSERT_TRUE( (uint8_t)data_file[3]==0x00);
ASSERT_TRUE( (char)data_file[4]==data_test[0]);
ASSERT_TRUE( (char)data_file[5]==data_test[1]);
ASSERT_TRUE( (char)data_file[6]==data_test[2]);
ASSERT_TRUE( (uint8_t)data_file[7]==0XDA);
ASSERT_TRUE( (uint8_t)data_file[8]==0XDE);

ASSERT_TRUE((uint8_t) data_file[9]==0XBA);
ASSERT_TRUE((uint8_t) data_file[10]==0XBA);
ASSERT_TRUE( (uint8_t)data_file[11]==0x02);
ASSERT_TRUE( (uint8_t)data_file[12]==0x00);
ASSERT_TRUE( (char)data_file[13]==data_test[3]);
ASSERT_TRUE( (char)data_file[14]==data_test[4]);
ASSERT_TRUE( (char)data_file[15]=='^');
ASSERT_TRUE( (uint8_t)data_file[16]==0XDA);
ASSERT_TRUE( (uint8_t)data_file[17]==0XDE);
}
TEST(data_package, write_read_messeges_data_1)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	string data_test("123456789abcde");

	write_string(data_test, str_1);



	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);
}

TEST(data_package, write_read_messeges_data_2)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	string data_test("1234");

	write_string(data_test, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);
}

TEST(data_package, write_read_messeges_data_3)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	string data_test("0123456789");

	write_string(data_test, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);
}

TEST(data_package, write_read_messeges_data_4)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	auto data_test=geniration_string(33, 100, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);
}

TEST(data_package, write_read_shuffle)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";
	std::string str_4 = "string_test/file_4.txt";

	auto data_test=geniration_string(33, 100, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.shuffle_write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() != data_test);

	filepackageread.sort_Messeges();

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);


}

TEST(data_package, writestring_readfullfile)
{
	std::string str_1 = "string_test/file_1.txt";

	string data_1("absegegd");

	write_string(data_1, str_1);

	auto data_2 = readfullfile(str_1);

	ASSERT_TRUE(data_1.size() == data_2.size());
	for(int i = 0; i != data_1.size(); i++) {
		ASSERT_TRUE(data_1[i] == data_2[i]);
	}
}
TEST(data_package, writestring_readstring)
{
	std::string str_1 = "string_test/file_1.txt";

	string data_1("absegegd");

	write_string(data_1, str_1);

	auto data_2 = read_string(str_1);

	ASSERT_TRUE(data_1 == data_2);
}
