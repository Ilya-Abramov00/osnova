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
    for(int i=0; i!=n; i++) big_data.push_back( atom_string(N) );
    write_do_otpavki(big_data);
return std::move(big_data);
}

void write_do_otpavki(std::vector<atom_string>& big_data){
    std::ofstream fout;
    fout.open("/home/MYFile.txt",std::ofstream::app);
    if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else {
        std::cout << "Файл создан\n";

        for (int i = 0; i != big_data.size(); i++){
            fout.write((char *) &big_data.at(i), sizeof(atom_string) );
    }
    }
    fout.close();
}