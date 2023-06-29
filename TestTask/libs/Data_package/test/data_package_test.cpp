#include <gtest/gtest.h>

#include "data_package/data_package.h"
#include<fstream>
using namespace std;

std::string str_1="/home/ilya/Загрузки/file_1.txt";
std::string str_2="/home/ilya/Загрузки/file_2.txt";
std::string str_3="/home/ilya/Загрузки/file_3.txt";
std::string str_4="/home/ilya/Загрузки/file_4.txt";

int N=20;

TEST(data_package,write_read) {

    int N=random_n(30,40);

    geniration_string( N, str_1);

    File_parser<20> q;


    File_Package<20> qe( q.get_File_parser(str_1) );

    qe.write(str_2);

    File_Package<20> eq;
    eq.read(str_2);


    ASSERT_TRUE(eq.get_Messeges_data().size() == qe.get_Messeges_data().size());

auto a=eq.get_Messeges_data().begin();
auto b=qe.get_Messeges_data().begin();

auto c=eq.get_Messeges_data().end();

for(;a!=c; )
{
    auto d=*a;
    auto e=*b;
    ASSERT_TRUE(d.get_id()==e.get_id());
    ASSERT_TRUE(d.get_data()==e.get_data());
a++;
b++;
}
}





TEST(data_package, write_one)
{
    Msg0<8> a("a b c d ",1);
    Msg0<8> b("a b c d ",2);
    Msg0<8> c("a b c d ",3);
    Msg0<8> d("a b c d ",3);
Messeges<8> q{a,b,c,d};

    File_Package<8> qw(q);
    qw.write(str_2);
    qw.clear();
    qw.read(str_2);

    auto e=qw.Data_Repoirter();
    ASSERT_TRUE(e=="a b c d a b c d a b c d a b c d ");

}



TEST(data_package, 2) {

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


