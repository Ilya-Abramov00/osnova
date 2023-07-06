#include <gtest/gtest.h>

#include "DataPackageWrite/WritePackage.h"
#include "DataPackageRead/ReadPackage.h"


using namespace std;

TEST(DataPackage, write_read_messeges_data_1)
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

TEST(DataPackage, write_read_messeges_data_2)
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

TEST(DataPackage, write_read_messeges_data_3)
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

TEST(DataPackage, write_read_messeges_data_4)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";

	auto data_test = geniration_string(33, 100, str_1);

	FilePackageWrite<10> filepackagewrite;
	filepackagewrite.get_File_Messeges(str_1);
	filepackagewrite.write_messeges(str_2);

	FilePackageRead<10> filepackageread;
	filepackageread.read_messeges(str_2);

	ASSERT_TRUE(filepackageread.get_Messeges().size() == filepackagewrite.get_Messeges().size());

	ASSERT_TRUE(filepackageread.Data_Repoirter() == data_test);
}

TEST(DataPackage, write_read_shuffle)
{
	std::string str_1 = "string_test/file_1.txt";
	std::string str_2 = "string_test/file_2.txt";
	std::string str_4 = "string_test/file_4.txt";

	auto data_test = geniration_string(33, 100, str_1);

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

