#include "data_package/data_package.h"

#include <algorithm>
#include <iterator>
#include<random>
#include<fstream>


std::random_device rd;
std::mt19937 gen(rd());


int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10*N );
     return dist(gen);
 }

int random_n()
{
    std::uniform_int_distribution<> dist(100, 150);
    return dist(gen);
}

void geniration_string(int N, std::string& str_1)
{
    try
    {
        std::ofstream fout;
        fout.open(str_1, std::ios::trunc);

        std::cout << "Файл_1 создан\n";
        int n = random_n();
        for (int i = 0; i != n; i++) { fout << std::string(random_l(N), '*') << "\n"; }
        fout.close();
    }
    catch (const std::exception& ex)
    {
        std::cout<<ex.what()<<"\n";
        std::cout << "Файл не может быть создан\n";
    }
}


void Socket::Packaging_Socket( int N , std::string& str_1, std::string& str_2 )
{

try{
        std::ifstream file;
        std::vector<Socket> q;
        q.reserve( N * 100);
        file.open(str_1);

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
                q.emplace_back(Socket(Msg(bufer, n_string), (n_string - n0_string + 1)));
                bufer.clear();
                n_N = -1;
                n0_string = n_string;
                }
            n_N++;
            }

        q.emplace_back(Socket(Msg(bufer, n_string), (n_string - n0_string + 1)));
        bufer.clear();

        std::ofstream fout;
        fout.open(str_2, std::ios::trunc);

        std::cout << "Файл_2 создан\n";


        for (int i = 0; i != q.size(); i++) { q.at(i).write_Socket_file(fout); }
        file.close();
        fout.close();

}


    catch (const std::exception& ex)
    {
        std::cout<<ex.what()<<"\n";
        std::cout << "Файл не может быть создан\n";
    }

}

void Socket::Random_Socket( std::string& str_2, std::string& str_3)
{
    try {
        std::vector<Socket> q;
        std::ifstream fout;
        fout.open(str_2);

        std::cout << "Файл_2 открыт \n";

        Socket::read_file_Socket(fout, q);
        std::shuffle(q.begin(), q.end(), gen);//поменяли рандомно местами

        std::ofstream file;
        file.open(str_3, std::ios::trunc);

        std::cout << "Файл_3 создан\n";

        for (int i = 0; i != q.size(); i++) { q.at(i).write_Socket_file(file); }

        file.close();
        fout.close();

    }

    catch (const std::exception& ex)
    {
        std::cout<<ex.what()<<"\n";
        std::cout << "Файл не может быть создан\n";
    }

}

void Socket::Sent_Socket( std::string& str_3, std::string& str_4){

    try {
        std::ifstream file;
        file.open(str_3);
        std::vector<Socket> q;

        std::cout << "Файл_3 открыт\n";

        read_file_Socket(file, q);
        file.close();

        sort(q.begin(), q.end());//сортировка


        std::ofstream fout;
        fout.open(str_4, std::ios::trunc);

        std::cout << "Файл_4 создан\n";
            for (int i = 0; i != q.size(); i++) { fout << q.at(i).data.get_string(); }

        fout.close();
        file.close();
        q.clear();
    }

    catch (const std::exception& ex)
    {
        std::cout<<ex.what()<<"\n";
        std::cout << "Файл не может быть создан\n";
    }
}

void Socket::write_Socket_file(std::ofstream& file)
{
 file.write((char *) &nomer_Socket, sizeof(int));
 file.write((char *) &data.get_nomer_string(), sizeof(int));
 file.write((char *) &n_string, sizeof(int));

 int n=data.get_string().length();
 file.write((char *) &n, sizeof(int) );

 for (int j = 0; j != n; j++)  { file.write((char*)&data.get_string()[j], sizeof(data.get_string()[j] ) ); }
}

std::vector<Socket>& Socket::read_file_Socket( std::ifstream& file ,std::vector<Socket>& q )
{
    int nomer_Socket;
    int n_string;
    int nomer_string;
    std::string data;
    char c;

    while (file) {
        file.read((char *) &nomer_Socket, sizeof(int));
        file.read((char *) &nomer_string, sizeof(int));
        file.read((char *) &n_string, sizeof(int));

        int n;
        file.read((char *) &n, sizeof(int));
        data = "";
        for (int i = 0; i != n; i++) {
            file.read((char *) &c, sizeof(c));
            data += c;
        }
        q.emplace_back(Socket(Msg(data, nomer_string), nomer_Socket, n_string));
    }
    q.pop_back(); //почему-то дублирует последний элемент вектора
    return q;
}

