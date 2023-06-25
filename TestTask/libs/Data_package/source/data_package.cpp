#include "data_package/data_package.h"

#include <algorithm>
#include <iterator>

std::random_device rd;
std::mt19937 gen(rd());

int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10 * N);
     return dist(gen);
 }

int random_n()
{
    std::uniform_int_distribution<> dist(100, 180);
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
    for(int i=1; i!=n+1; i++) fout<<std::string ( random_l(N) ,'*')<<"\n";

    }
    fout.close();
}




// std::shuffle(big_data.begin(), big_data.end(), gen);//поменяли рандомно местами