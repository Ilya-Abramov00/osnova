


using namespace std;
#include "data_package/data_package.h"
#include<cstdint>


int main()
{


uint16_t magic;
uint8_t * magBuf=reinterpret_cast<uint8_t*>(&magic);

magic=0XFFFF;

    std::cout<<"[0]="<<std::hex<<+magBuf[0]<<"\n";
    std::cout<<"[1]="<<std::hex<<+magBuf[1] <<std::endl;

    std::cout<< std::dec<<"magic=" <<magic<<"\n";

std::string str_1="/home/ilya/Загрузки/file_1.txt";

    //File_parser<200> q(str_1);


}
