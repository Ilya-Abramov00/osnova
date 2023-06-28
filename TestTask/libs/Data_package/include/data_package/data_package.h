#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include<vector>


int random_l(int N);
int random_n();

void geniration_string(int N, std::string& str_1);



template < size_t T>
struct Msg{
public:
    Msg(std::string str, int nomer):string_data(str), nomer_string(nomer) { }

    int const& get_id(){ return  id;}
    std::string const& get_data() { return   data[T]; }


private:

    int id;
    char data[T];
};


/*
class Msg{
public:
    int const& get_nomer_string(){return  nomer_string;}
    std::string const& get_string() { return   string_data; }

    Msg(std::string str, int nomer):string_data(str), nomer_string(nomer) { }
private:
    int nomer_string;
    std::string string_data;
};
*/


class Socket_id {
public:
    static int const& get_id(){ return id;}
    static void clear (){ id=0; }
    static void id_plus (){ id++; }
private:
    static int  id ;
};
int Socket_id:: id=0;

//file_parser
class Socket{
public:

    void  write_Socket_file(std::ofstream& file);

    static       std::vector<Socket>& read_file_Socket( std::ifstream& file ,std::vector<Socket>& q ) ;


    static void  Packaging_Socket( int N , std::string& str_1, std::string& str_2 );

    static void  Random_Socket( std::string& str_2, std::string& str_3);

    static void  Sent_Socket ( std::string& str_3, std::string& str_4);


    Socket(Msg str , int n_string):data(str) ,n_string(n_string) {Socket_id::id_plus(); this->nomer_Socket=Socket_id::get_id();}

    Socket(Msg str ,int nomer_Socket ,int n_string):data(str) ,n_string(n_string),nomer_Socket(nomer_Socket) { }


    int const& get_nomer_Socket(){
        return nomer_Socket;
    }

private:
    int nomer_Socket;
    Msg data;
    int n_string;
};



bool operator<( Socket& x, Socket& y)
{
    return x.get_nomer_Socket() < y.get_nomer_Socket();
}








#endif
