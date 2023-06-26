#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include<vector>

int random_l(int N);
int random_n();

void geniration(int N, std::string& str_1);

class Packaging_Socket;
class Socket;


class Msg{
    friend  Packaging_Socket;
public:
   Msg(std::string str, int nomer):data(str), nomer_string(nomer) { }
private:
    int nomer_string;
    std::string data;
};



class Packaging_Socket{
    friend class Socket;
public:

    Packaging_Socket( int N , std::string& str_1 );
    void Random_Socket( std::string& str_3 );
private:
    std::vector<Socket> q;
    static int ide;
};
int Packaging_Socket::ide=0;



class Socket{
    friend  Packaging_Socket;
    friend  bool operator<(const Socket& x, const Socket& y);
public:

    Socket(Msg str , int n_string):data(str) ,n_string(n_string) { Packaging_Socket::ide++; this->nomer_Socket=Packaging_Socket::ide;}
private:
    int nomer_Socket;
    Msg data;
    int n_string;
};


bool operator<(const Socket& x, const Socket& y)
{
    return x.nomer_Socket < y.nomer_Socket;
}







/*
    std::shuffle(q.begin(), q.end(), gen);//поменяли рандомно местами


    sort(q.begin(), q.end() );//сортировка

    for (int i = 0; i != q.size(); i++)
    {
        std::cout <<"номер пакета: "<< q.at(i).nomer_Socet << std::endl;
        std::cout << "номер строки: "<<q.at(i).data.nomer_string << std::endl;
        std::cout <<"данные: "<< q.at(i).data.data << std::endl;
    }







//запись данных в файл
    std::ofstream fout;
    fout.open("/home/ilya/Загрузки/file_4.txt",std::ios::trunc);
    if (!fout.is_open() ) { std::cout << "Файл не может быть создан\n";  }
    else
    {
        std::cout << "Файл создан\n";
        for(int i=0; i!=q.size(); i++)
        {
            fout<<q.at(i).data.data;
        }
    }

    fout.close();
}
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
