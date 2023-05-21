#include "potoc/potoc.h"


int main()
{
    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];


// /*
    Write q1(queue,buf_0);
    Read q2( queue,buf_0);

    q1.CreateThr();
    q2.CreateThr();


  std::cout<<" \n \n работа закончена";

   delete [] buf_0;
// */

 /*


    std::thread q1 (write, std::ref (queue) , buf_0);

    std::thread q2 (read , std::ref (queue) , buf_0) ;

    q1.join();
    q2.join();
    delete [] buf_0;
    */
    return 1;
}