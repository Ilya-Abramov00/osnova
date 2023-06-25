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
    std::uniform_int_distribution<> dist(10, 20);
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
    fout.open("/home/ilya/Загрузки/file.txt",std::ios::trunc);
    if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else {
        std::cout << "Файл создан\n";

        for (int i = 0; i != big_data.size(); i++){
            std::string ::size_type lenght=big_data.at(i).data.size();
            fout.write(big_data.at(i).data.data(), big_data.at(i).data.size());
            fout.write("\n", 1);

    }
    }
    fout.close();
}