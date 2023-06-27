


using namespace std;
#include "data_package/data_package.h"



int main()
{
   std::string str_1="/home/ilya/Загрузки/file_1.txt";
   std::string str_2="/home/ilya/Загрузки/file_2.txt";
   std::string str_3="/home/ilya/Загрузки/file_3.txt";
   std::string str_4="/home/ilya/Загрузки/file_4.txt";

   int N=100;

    geniration( N, str_1);

    Packaging_Socket q(N,str_1,str_2);

    q.Random_Socket(str_3);

    Socket::sent_Socket (str_3,str_4);


    return 0;
}
