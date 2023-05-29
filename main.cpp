#include "potoc/potoc.h"


int main()
{
    auto start=std::chrono::high_resolution_clock::now();

    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];


    Write_thread q1(queue,buf_0);
    Read_thread q2( queue,buf_0,"/home/ilya/zad2.txt" );
    q1.CreateThr();
    q2.CreateThr();


    delete [] buf_0;

    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration=end-start;
    std::cout<<"\n время заняло= "<<duration.count()<<"\n";
    return 1;
}