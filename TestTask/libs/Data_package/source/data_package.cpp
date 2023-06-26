#include "data_package/data_package.h"

#include <algorithm>
#include <iterator>
#include<random>
#include<fstream>


std::random_device rd;
std::mt19937 gen(rd());


int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 2*N );
     return dist(gen);
 }

int random_n()
{
    std::uniform_int_distribution<> dist(15, 20);
    return dist(gen);
}

void geniration(int N, std::string& str_1)
{
    std::ofstream fout;
    fout.open(str_1,std::ios::trunc);
    if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else
    {
        std::cout << "Файл_1 создан\n";
    int n=random_n();
    for(int i=0; i!=n; i++) fout<<std::string ( random_l(N) ,'*')<<"\n";
    }
    fout.close();
}


Packaging_Socket::Packaging_Socket( int N , std::string& str_1 ){

    std::ifstream file;
    q.reserve(10 * N);
    file.open(str_1);
    if (!file.is_open()) { std::cout << "Файл не может быть открыт\n"; }
    else {
        std::cout << "Файл_1 открыт\n";

        std::string bufer;
        char c;
        int n_N = 0;
        int n_string = 1;
        int n0_string = 1;
        while (file.get(c)) {
            if (c == '\n') { n_string++; } //новая строка

            if (N - 1 != n_N) { bufer.push_back(c); }
            else if (N != n_N) {
                bufer.push_back(c);
                q.push_back(Socket(Msg(bufer, n_string), (n_string - n0_string + 1)));
                bufer.clear();
                n_N = -1;
                n0_string = n_string;
            }
            n_N++;
        }

        q.push_back(Socket(Msg(bufer, n_string), (n_string - n0_string + 1)));
        bufer.clear();

        for (int i = 0; i != q.size(); i++)
        {
            //std::cout << "номер пакета: " << q.at(i).nomer_Socket << std::endl;
            //std::cout << "номер строки: " << q.at(i).data.nomer_string << std::endl;
            //std::cout << "данные: " << q.at(i).data.data << std::endl<< std::endl;
        }
        file.close();
    }
}

void Packaging_Socket::Random_Socket(int N, std::string& str_3){

    std::shuffle(q.begin(), q.end(), gen);//поменяли рандомно местами

    std::ofstream file;
    file.open(str_3,std::ios::trunc);
    if (!file.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else
    {
        std::cout << "Файл_3 создан\n";

        for(int i=0; i!=q.size(); i++)
        {
            file.write((char *) &q.at(i).nomer_Socket, sizeof(int));
            file.write((char *) &q.at(i).data.nomer_string, sizeof(int));
            file.write((char *) &q.at(i).n_string, sizeof(int));
            file.write((char *) &q.at(i).data.data,sizeof(std::string( std::move(N),'*')));
        }
    }
    file.close();
}

Sent_Socket::Sent_Socket(int N, std::string& str_3, std::string& str_4) {

    std::ifstream file;
    file.open(str_3);
    std::vector<Socket> q;

    if (!file.is_open()) { std::cout << "Файл не может быть открыт\n"; }
    else
    {
        std::cout << "Файл_3 открыт\n";


        int nomer_Socket;
        int n_string;
        int nomer_string;
           std::string data;

              while(file)
               {
                  file.read((char *) &nomer_Socket, sizeof(int));
                  file.read((char *) &nomer_string, sizeof(int));
                  file.read((char *) &n_string, sizeof(int));
                  file.read((char *) &data,sizeof(std::string(std::move(N),'*')));
                  q.push_back( Socket( Msg(data, nomer_string),nomer_Socket,n_string ) );
               }

              q.pop_back();//почему-то дублирует последний файл
        file.close();
        data.clear();
        std::cout << "Файлwfqf\n";
    }
    std::cout << "Файefwан_4\n";

                         sort(q.begin(), q.end() );//сортировка
                         std::ofstream fout;
                         fout.open("/home/ilya/Загрузки/file_4.txt",std::ios::trunc);
                         if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
                         else
                         {
                             std::cout << "Файл создан_4\n";
                             for(int i=0; i!=q.size(); i++)
                             {
                                 fout<<q.at(i).data.data;
                             }
                         }
                         fout.close();

        q.clear();
    }

