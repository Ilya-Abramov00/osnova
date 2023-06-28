#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include<vector>
#include <list>
#include<fstream>
#include <algorithm>
#include <iterator>
#include<random>


#include<cstdint>

int random_l(int N);
int random_n();

void geniration_string(int N, std::string& str_1);


std::random_device rd;
std::mt19937 gen(rd());

template < size_t T>

struct Msg0{
public:
    Msg0( const std::string& data_s , int id) :id(id)
    {
          for( int i=0; i!=T; i++ )  {  data[i]=data_s[i] ;  }

    }


    int const& get_id() { return  id; }
    auto const& get_data() { return   data[T]; }


private:

    uint16_t id;
    char data[T];
};


template < size_t T>
using Messeges=std::list <Msg0<T>>;

template < size_t T>
class File_parser{
public:

    File_parser( std::string& file_s )
    {
        try
        {
            std::ifstream file;
            file.open(file_s);

            std::string bufer; bufer.reserve(T);
            char c;
            int i = 0;

            while ( file.get(c) )
            {


                if ( T - 1 != i ) { bufer.push_back(c); }
                else if ( T != i )
                {
                    bufer.push_back(c);
                    Messeges_data.emplace_back( Msg0<T>(bufer, ++id) );
                    bufer.clear();
                    i = -1;
                }
                i++;
            }

            Messeges_data.emplace_back( Msg0<T>(bufer, ++id) );
            bufer.clear();

        }
        catch (const std::exception& ex)
        {
            std::cout<<ex.what()<<"\n";
        }

    };

    Messeges<T> const &  get_Messeges(){
        return  Messeges_data;
    };

    Messeges<T>& shuffle(  Messeges<T> q  )
    {
       //
    }




private:
    Messeges<T> Messeges_data;
    int id=0;
};

template < size_t T>

class File_Pakage
        {
public:
    static void write(std::string& str_3,Messeges<T>& Messeges_data )
    {
        std::ifstream file;
        file.open(str_3);

        for (auto const& i : Messeges_data) {
            write_Msg_file(file,i);
        }
    }



    static Messeges<T>& read(){}
    static  uint16_t Head;


    static uint16_t Tail;

private:
    static void write_Msg_file(std::ofstream& file, Msg0<T> msg)
    {

        file.write((char *) &Head_l, sizeof(Head_l));
        file.write((char *) &Head_h, sizeof(Head_h));

        file.write((char *) &msg.get_id(), sizeof(int));

        int l_string=msg.get_string().length();
        file.write((char *) &l_string, sizeof(int) );

        for (int j = 0; j != l_string; j++)  { file.write((char*)&msg.get_string()[j], sizeof(msg.get_string()[j] ) ); }

        file.write((char *) &Tail_l, sizeof(Tail_l));
        file.write((char *) &Tail_h, sizeof(Tail_h));
    }

    static  Msg0<T>&   read_Msg_file(std::ifstream& file) {
        char c;
        bool flag = 0;
        bool flag_head = 0;
        bool flag_id = 0;

        uint16_t id;



        while (file.get(c))
        {
            if (c == Head_l) flag = 1;

            if (flag && Head_h==c ) flag_head=1;

            if(flag_head)
            {
                bufer
            }


                char atom_data_string;
                std::string data_string = "";
               // for (int j = 0; j != l_string; j++) {
                    file.read((char *) &atom_data_string, sizeof(atom_data_string));
                    data_string += atom_data_string;

            }
        }

        };
template < size_t T>
uint16_t File_Pakage<T>:: Head=0xBABA;


template < size_t T>
uint16_t File_Pakage<T>:: Tail=0xDEDA;



class Msg{
public:
    int const& get_nomer_string(){return  nomer_string;}
    std::string const& get_string() { return   string_data; }

    Msg(std::string str, int nomer):string_data(str), nomer_string(nomer) { }
private:
    int nomer_string;
    std::string string_data;
};




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


void logic_buf_2()





#endif
