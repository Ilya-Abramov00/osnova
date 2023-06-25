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


#endif
