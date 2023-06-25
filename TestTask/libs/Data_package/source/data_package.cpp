#include "data_package/data_package.h"
std::random_device rd;
std::mt19937 gen(rd());

int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10 * N);
     return dist(gen);
 }

int random_n()
{
    std::uniform_int_distribution<> dist(100, 150);
    return dist(gen);
}

std::vector<atom_string> genitation(int N)
{
    int n=random_n();
    std::vector<atom_string> big_data;
    big_data.reserve(n*6*N);
    for(int i=0; i!=n; i++)
    {
big_data.push_back( atom_string(N) );
    }
return big_data;
}
