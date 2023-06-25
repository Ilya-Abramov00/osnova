

#include <QApplication>
#include "mainwindow.h"

using namespace std;
#include "data_package/data_package.h"



int main()
{
int N=10;

    std::vector<atom_string> big_data=genitation(N);

    for(int i=0; i!=big_data.size(); i++)
    {
        cout<<big_data[i].data<<endl;
        cout<<big_data[i].nomer<<endl;
    }
    return 0;
}
