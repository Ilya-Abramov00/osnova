#include "potoc/potoc.h"

int main()
{
    std::queue <Msg> queue ;
    int v=1024*1024;
    char buf[v];
    char * buf_0=buf;

    std::thread q1 (write, std::ref (queue) , buf_0);

    std::thread q2 (read , std::ref (queue) , buf_0) ;

    q1.join();
    q2.join();

    if( queue.empty() ){ std::cout<<" \n работа закончена";}
    return 1;
}