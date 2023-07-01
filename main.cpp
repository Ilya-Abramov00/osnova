
#include "data_package/data_package.h"
#include<random>


int main()
{

    std::string str_1="string_test/file_1.txt";
    std::string str_2="string_test/file_2.txt";


    File_parser<10> q;

    File_Package<10> qe( q.get_File_parser(str_1) );

   auto c= qe.get_Messeges_data();
   auto e=*c.begin();
   //std::cout<<e.get_data();
}
