#include "potoc/potoc.h"

int main()
{
    std::queue <char *> queue ;
    char buf[1024];
    char* buf_0=buf;

    std::thread q1 (write, std::ref (queue) , buf_0);

    std::thread q2 (read , std::ref (queue) , buf_0) ;

    q1.join();
    q2.join();

    if( queue.empty() ){ std::cout<<" \n Очередь пуста";}
    return 1;
}