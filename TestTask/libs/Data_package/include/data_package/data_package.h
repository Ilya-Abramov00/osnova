#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include<random>
#include<vector>
#include<fstream>
#include <iostream>
#include <algorithm>
#include <iterator>

int random_l(int N);
int random_n();

void geniration(int N);


class Msg{
public:
   Msg(std::string str, int nomer):data(str), nomer_string(nomer) { }

    int nomer_string;
    std::string data;
};
static int ide;
class Socet{
public:

   Socet(Msg str):data(str) { ide++; this->nomer_Socet=ide;}



   int nomer_Socet;
   Msg data;

};

bool operator<(const Socet& x, const Socet& y)
{
    return x.nomer_Socet < y.nomer_Socet;
}

std::random_device rd;
std::mt19937 gen(rd());


class Logic_Socet{
public:
    Logic_Socet( int N )
    {
        std::ifstream file;
        std::vector<Socet> q;
        q.reserve(10*N);
        file.open("/home/ilya/Загрузки/file.txt");
        if (!file.is_open() ) { std::cout << "Файл не может быть открыт\n";  }
        else
        {
            std::cout << "Файл открыт\n";

            std::string bufer;
            char c;  int n_N=0;
            int n_string=1;
            while (file.get(c))
            {
               if (c=='\n') { n_string++; } //новая строка

              if ( N-1 != n_N  ) { bufer.push_back(c);  }
                   else if (N != n_N  )
                   {
                       bufer.push_back(c);
                       q.push_back( Socet( Msg( bufer,n_string ) ) );
                       bufer.clear(); n_N=-1;
                   }

                n_N++;
            }

            for (int i = 0; i != q.size(); i++)
            {
                std::cout <<"номер пакета: "<< q.at(i).nomer_Socet << std::endl;
                std::cout << "номер строки: "<<q.at(i).data.nomer_string << std::endl;
                std::cout <<"данные: "<< q.at(i).data.data << std::endl;
            }

            std::shuffle(q.begin(), q.end(), gen);//поменяли рандомно местами


            sort(q.begin(), q.end() );//сортировка






        }
        file.close();

    }


};

/*
    while (a >=N)
    {

        q.push_back(Socet(str.substr(k*N, N)));
        a -= N;
        k++;
    };

    if ( (a<N)  )
    {
        bufer.push_back(str.substr(k*N, a));//реализовано разбиение, но нет нескольких строк в одном сокете
    }
}

for (int i = 0; i != q.size(); i++)
{
std::cout << q.at(i).nomer_Socet << std::endl;
std::cout << q.at(i).data << std::endl;
}

for (int i = q.size(); i != 0; i--)
{
q.pop_back();
}

 */
#endif
