


using namespace std;
#include "data_package/data_package.h"
#include<cstdint>


int main()
{
    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";
    std::string str_4="/home/ilya/Загрузки/file_4.txt";
    int N=100;

    geniration_string( N, str_1);


    File_parser<20> q(str_1);

    auto data=q.get_Messeges();
    //shuffle(data);
    File_Package<20> qe( data );

    qe.write(str_3);

Messeges<20> a;
    File_Package<20> eq(a);
    eq.read(str_3);

std::string  c;
    eq.Data_Repoirter(c);

    File_Package<20>::write_string(c, str_4);
    //std::cout<<e;

}
