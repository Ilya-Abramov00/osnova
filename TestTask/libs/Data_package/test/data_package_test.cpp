#include <gtest/gtest.h>

#include "data_package/data_package.h"
#include<fstream>

TEST(data_package, 1) {

    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_2="/home/ilya/Загрузки/file_2.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";
    std::string str_4="/home/ilya/Загрузки/file_4.txt";

    int N=100;

    geniration_string( N, str_1);

    Socket::Packaging_Socket(N,str_1,str_2);

    Socket::Random_Socket(str_2,str_3);

    Socket::Sent_Socket (str_3,str_4);

    std::ifstream file1;
    file1.open(str_1);
    char c1;
    std::string str1="";

    while (file1.get(c1))
{
        str1+=c1;
}

    std::ifstream file2;
    file2.open(str_4);
    char c2;
    std::string str2="";


    while (file2.get(c2))
    {
        str2+=c2;
    }

    ASSERT_TRUE(str1 == str2); // данные до отправки и после одинаковы


    std::ifstream file3;
    file3.open(str_2);
    char c3;
    std::string str3="";


    while (file3.get(c3))
    {
        str3+=c3;
    }

    std::ifstream file4;
    file3.open(str_3);
    char c4;
    std::string str4="";


    while (file4.get(c4))
    {
        str4+=c4;
    }

    ASSERT_TRUE(str3 != str4); //проверка на то, что данные перемешались
}


