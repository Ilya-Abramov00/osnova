#include "potoc/potoc.h"

#include <QApplication>
#include "mainwindow.h"




int main()
{

    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    Write_thread q1(queue,it, mtx ,0);
    q1.CreateThr();

    Read_thread q2( queue, it, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();
    std::this_thread::sleep_for(std::chrono::seconds(20));
    return 0;

}
