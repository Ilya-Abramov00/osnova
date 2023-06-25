#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include<random>
#include<vector>
#include<fstream>
#include <iostream>

int random_l(int N);
int random_n();

void geniration(int N);

static int id=0;
class Socet{
public:
   Socet(std::string str):data(str) { id++; this->nomer_Socet=id;}



   int nomer_Socet;
   std::string data;

};
int N=1;
class Logic_Socet{
public:
    Logic_Socet(){
        std::ifstream file;

        file.open("/home/ilya/Загрузки/file.txt");
        if (!file.is_open() ) { std::cout << "Файл не может быть открыт\n";  }
        else
        {
            std::cout << "Файл открыт\n";
            std::vector<Socet> q;q.reserve(10*N);

            while(file) {
                int k=0;
                std::string str;
                std::getline(file, str);
                std::cout <<str<< std::endl;
                if (str != "\n") {

                    int a = str.size();
                    while (a > N) {

                        q.push_back(Socet(str.substr(k*N, N)));
                        a -= N;
                        k++;
                    };

                    for (int i = 0; i != q.size(); i++) {
                        std::cout << q.at(i).data << std::endl;
                        std::cout << q.at(i).nomer_Socet << std::endl;
                    }
                }
            }
        }
        file.close();
    }


};

#endif
