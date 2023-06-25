#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include<random>
#include<vector>
#include<fstream>
#include <iostream>

int random_l(int N);
int random_n();

void geniration(int N);


class Socet{
public:
   Socet()
   {
       id++; nomer_Socet=id;
   }

   int nomer_Socet;
   int n_Atom_string;
   static int id;
};

class Logoc_Socet{
public:
    Logoc_Socet(){

        std::ifstream file;
        file.open("/home/ilya/Загрузки/file.txt");
        if (!file.is_open() ) { std::cout << "Файл не может быть создан\n";  }
        else
        {
            std::cout << "Файл открыт\n";
            while(file) {
                std::string str;
                std::getline(file, str);

                //std::cout<<str<<std::endl;
            }

        }
        file.close();
    }
};

#endif
