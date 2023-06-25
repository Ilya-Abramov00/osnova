#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include<random>
#include<vector>

int random_l(int N);
int random_n();


class atom_string{
public:
    atom_string( std::string& determinir ):data (determinir ){ id++; };//если данные, которые мы передаем являются не случайными

    atom_string(int N)
    {
        this->data.append( random_l(N) , '*');
         id++; this->nomer=id;
    }

    std::string data;
    int  nomer;
private:
    static int id;
};
int atom_string::id=0;


std::vector<atom_string> genitation(int N);


#endif
