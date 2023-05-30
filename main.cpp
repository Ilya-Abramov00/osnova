#include "potoc/potoc.h"

#include <QApplication>
#include "mainwindow.h"
int main()
{
    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];
     std::mutex mtx;
    Write_thread q1(queue,buf_0, mtx ,2);
    q1.CreateThr();

    Read_thread q2( queue, buf_0, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();

    delete [] buf_0;


    return 0;

}
