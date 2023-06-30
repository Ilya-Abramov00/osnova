#include <gtest/gtest.h>

#include "data_package/data_package.h"
#include<fstream>
using namespace std;



TEST(data_package,write_read_messeges) {

std::string str_1="string_test/file_1.txt";
std::string str_2="string_test/file_2.txt";


    File_parser<10> q;

    File_Package<10> qe( q.get_File_parser(str_1) );

    qe.write(str_2);

    File_Package<10> eq;
    eq.read(str_2);


    ASSERT_TRUE(eq.get_Messeges_data().size() == qe.get_Messeges_data().size());

auto a=eq.get_Messeges_data().begin();
auto b=qe.get_Messeges_data().begin();

auto c=eq.get_Messeges_data().end();

   for(;a!=c; )
   {
    auto d=*(a++);
    auto e=*(b++);
    ASSERT_TRUE(d.get_id()==e.get_id());
    ASSERT_TRUE(d.get_data()==e.get_data());
   }

}


/*
TEST(data_package,write_read_messeges2) {

    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_2="/home/ilya/Загрузки/file_2.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";
    std::string str_4="/home/ilya/Загрузки/file_4.txt";

    File_parser<10> q;

    File_Package<10> qe( q.get_File_parser(str_1) );

    qe.write(str_2);

    File_Package<10> eq;
    eq.read(str_2);


    ASSERT_TRUE(eq.get_Messeges_data().size() == qe.get_Messeges_data().size());

    auto a=eq.get_Messeges_data().begin();
    auto b=qe.get_Messeges_data().begin();

    auto c=eq.get_Messeges_data().end();

    for(;a!=c; )
    {
        auto d=*(a++);
        auto e=*(b++);
        ASSERT_TRUE(d.get_id()==e.get_id());
        ASSERT_TRUE(d.get_data()==e.get_data());
    }

}


/*
TEST(data_package, write_one)
{
    std::string str_1="/home/ilya/Загрузки/file_1.txt";

    string a("1234");

    File_Package<3>::write_string(a,str_1);
    File_parser<3> q;

    File_Package<3> qw(q.get_File_parser(str_1) );

    auto e=qw.Data_Repoirter();
    ASSERT_TRUE(e==a);
}


TEST(data_package, 2) {

    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_2="/home/ilya/Загрузки/file_2.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";
    std::string str_4="/home/ilya/Загрузки/file_4.txt";

    int N=32;

    geniration_string( 101,N, str_1);

    File_parser<20> q;

    File_Package<20> qe( q.get_File_parser(str_1) );

    qe.shuffle_write(str_2);

    File_Package<20> eq;
    eq.read(str_2);

     eq.sort_Messeges();

    File_Package<20>::write_string(eq.Data_Repoirter(), str_4);



    std::string str1=File_Package<20>::read_string(str_1);
    std::string str2=File_Package<20>::read_string(str_4);;


    ASSERT_TRUE( str1.size() == str2.size() );
    ASSERT_TRUE(str1 == str2); // данные до отправки и после одинаковы

}

*/
