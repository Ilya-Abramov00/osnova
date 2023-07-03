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
    for( int i=0;i!=10;i++)
    {
        ASSERT_TRUE(d.get_data()[i] == e.get_data()[i]);
    }
   }

}






TEST(data_package, write_one)
{
    std::string str_1="string_test/file_1.txt";


    string a("1234567");

    File_Package<6>::write_string(a,str_1);
    File_parser<6> q;

    File_Package<6> qw(q.get_File_parser(str_1) );

    auto e=qw.Data_Repoirter();
    ASSERT_TRUE(e==a);
}


TEST(data_package, 2) {

    std::string str_1="string_test/file_1.txt";
    std::string str_2="string_test/file_2.txt";
    std::string str_4="string_test/file_4.txt";

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
TEST(data_package, write_read)
{
    std::string str_1="string_test/file_1.txt";
    std::string str_2="string_test/file_2.txt";

    string a("absegegd");

    File_Package<3>::write_string(a,str_1);
   auto e=readfullfile(str_1);


  ASSERT_TRUE(a.size() == e.size() );
}