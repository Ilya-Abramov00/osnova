#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include<vector>

int random_l(int N);
int random_n();

void geniration(int N, std::string& str_1);

class Packaging_Socket;
class Socket;
class Sent_Socket;

class Msg{
    friend  Packaging_Socket;
    friend Sent_Socket;
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
    void Random_Socket(int& N , std::string& str_3 );
private:
    std::vector<Socket> q;
    static int ide;
};
int Packaging_Socket::ide=0;



class Socket{
    friend  Packaging_Socket;
    friend  bool operator<(const Socket& x, const Socket& y);
    friend Sent_Socket;
public:
void static clear(){
    Packaging_Socket::ide=0;
}
    Socket(Msg str , int n_string):data(str) ,n_string(n_string) { Packaging_Socket::ide++; this->nomer_Socket=Packaging_Socket::ide;}
    Socket(Msg str ,int nomer_Socket ,int n_string):data(str) ,n_string(n_string),nomer_Socket(nomer_Socket) { }
private:
    int nomer_Socket;
    Msg data;
    int n_string;
};


bool operator<(const Socket& x, const Socket& y)
{
    return x.nomer_Socket < y.nomer_Socket;
}


class Sent_Socket{
public:
    Sent_Socket(int N,std::string& str_3, std::string& str_4);
};






#endif
