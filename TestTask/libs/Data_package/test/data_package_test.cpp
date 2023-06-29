#include <gtest/gtest.h>

#include "data_package/data_package.h"
#include<fstream>

TEST(data_package, 1) {

    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_2="/home/ilya/Загрузки/file_2.txt";

    std::string str_4="/home/ilya/Загрузки/file_4.txt";

    int N=10;

    geniration_string( N, str_1);


    File_parser<20> q;


    File_Package<20> qe( q.get_File_parser(str_1) );

    qe.write(str_2);

    //qe.shuffle_write(str_2);


    File_Package<20> eq;
    eq.read(str_2);

   // eq.sort_Messeges();

    File_Package<20>::write_string(eq.Data_Repoirter(), str_4);



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




    std::cout<<"было "<<str1.size()<<"\n";

    std::cout<<"стало "<<str2.size()<<"\n";

    ASSERT_TRUE(str1.size() == str2.size());
    ASSERT_TRUE(str1 == str2); // данные до отправки и после одинаковы



}


