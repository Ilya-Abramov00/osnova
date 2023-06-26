#include "data_package/data_package.h"

#include <algorithm>
#include <iterator>



int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10 * N);
     return dist(gen);
 }

int random_n()
{
    std::uniform_int_distribution<> dist(10, 10);
    return dist(gen);
}

void geniration(int N)
{
    std::ofstream fout;
    fout.open("/home/ilya/Загрузки/file.txt",std::ios::trunc);
    if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else
    {
        std::cout << "Файл создан\n";
    int n=random_n();
    for(int i=0; i!=n; i++) fout<<std::string ( random_l(N) ,'*')<<"\n";
    }
    fout.close();
}


