#include "potoc/potoc.h"

#include <QApplication>
#include "mainwindow.h"



template <typename T>
void q(T && d){};
int main()
{
    int a=3;
    q(a);
    q(2);
    return 0;

}
