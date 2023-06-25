

#include <QApplication>
#include "mainwindow.h"

using namespace std;
#include "data_package/data_package.h"



int main()
{
int N=1;

    std::vector<atom_string> big_data=genitation(N);

    for(int i=0; i!=big_data.size(); i++)
    {
        cout<<big_data[i].nomer<<endl;
        cout<<big_data[i].data<<endl;
    }
    return 0;
}
