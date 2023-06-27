#include <gtest/gtest.h>

#include "data_package/data_package.h"

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


}

