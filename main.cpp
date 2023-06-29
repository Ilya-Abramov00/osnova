


using namespace std;
#include "data_package/data_package.h"
#include<cstdint>


int main()
{
    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";

    int N=100;

    geniration_string( N, str_1);


    File_parser<20> q(str_1);

    File_Pakage<20> q;

    q.write( str_3 , q.get_Messeges() );
    auto Messeges_data=File_Pakage<20>::read( str_3  );

    auto e=File_Pakage<20>::Data_Repoirter(Messeges_data);
    //std::cout<<e;

}
