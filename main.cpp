


using namespace std;
#include "data_package/data_package.h"
#include<cstdint>


int main()
{
    std::string str_1="/home/ilya/Загрузки/file_1.txt";
    std::string str_3="/home/ilya/Загрузки/file_3.txt";

    int N=100;

    geniration_string( N, str_1);
uint16_t i=1;

Messeges<20>a;
a.push_back(Msg0<20>("1sfdfs",i));
uint16_t magic;
uint8_t * magBuf=reinterpret_cast<uint8_t*>(&magic);

magic=0XFFFF;

    std::cout<<"[0]="<<std::hex<<+magBuf[0]<<"\n";
    std::cout<<"[1]="<<std::hex<<+magBuf[1] <<std::endl;

    std::cout<< std::dec<<"magic=" <<magic<<"\n";



    File_parser<20> q(str_1);
    //for(auto i:q.get_Messeges()){
   // for(int j=0; j!=i.get_data().size(); j++) {
      //  std::cout << i.get_data().at(j);
   // }
//}

    File_Pakage<20>::write( str_3 , q.get_Messeges() );
    auto b=File_Pakage<20>::read( str_3  );
    File_Pakage<20>::Data_Repoirter(b);

}
