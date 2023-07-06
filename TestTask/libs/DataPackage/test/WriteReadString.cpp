#include <gtest/gtest.h>

#include "DataPackage/ReadPackage.h"
#include "DataPackage/WritePackage.h"
#include "DataPackage/CommonData.h"

using namespace std;

TEST(WriteReadString, writestring_readfullfile)
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
TEST(WriteReadString, writestring_readstring)
{
	std::string str_1 = "string_test/file_1.txt";

	string data_1("absegegd");

	write_string(data_1, str_1);

	auto data_2 = read_string(str_1);

	ASSERT_TRUE(data_1 == data_2);
}
TEST(WriteReadString, readstring)
{
	std::string str_1 = "string_test/file_1.txt";

	auto data_test = geniration_string(33, 100, str_1);

	write_string(data_test, str_1);

	auto data = read_string(str_1);

	ASSERT_TRUE(data_test== data);
}