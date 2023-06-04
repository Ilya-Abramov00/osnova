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

    Protocol q(queue, it, mtx, "/home/ilya/potoc.txt",0.2,0);
    q.start();

    return 0;
}
