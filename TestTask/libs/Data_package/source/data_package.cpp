#include "data_package/data_package.h"


int random_n(int a, int b)
{
    std::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10*N );
     return dist(gen);
 }


 void geniration_string(int n, int N, std::string const & namefile)
{
    try
    {
        std::ofstream fout;
        fout.open(namefile, std::ios::trunc);


        for (int i = 0; i != n; i++) { fout << std::string(random_l(N), '*') << "\n"; }
        fout.close();
    }
    catch (const std::exception& ex)
    {
        std::cout<<ex.what()<<"\n";

    }
}