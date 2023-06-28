


using namespace std;
#include "data_package/data_package.h"
#include<cstdint>


int main()
{


uint16_t magic;
uint8_t * magBuf=reinterpret_cast<uint8_t * >(&magic);

magBuf[0]=0x00;
magBuf[1]=0x00;

std::cout<<magic;

std::string str_1="/home/ilya/Загрузки/file_1.txt";

    //File_parser<200> q(str_1);


}
