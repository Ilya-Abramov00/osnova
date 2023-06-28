#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <iostream>
#include<vector>
#include <list>
#include<fstream>
#include <algorithm>
#include <iterator>
#include<random>
#include<array>

#include<cstdint>

int random_l(int N);
int random_n();

void geniration_string(int N, std::string& str_1);


std::random_device rd;
std::mt19937 gen(rd());

template < size_t T>

struct Msg0{
public:
    Msg0( const std::string& data_s , uint16_t id) :id(id)
    {
          for( int i=0; i!=data_s.size(); i++ )  {  data[i]=data_s[i] ;  }
    }

    uint16_t const& get_id() { return  id; }
    std::array <char,T>  const& get_data() { return   data; }

private:

    uint16_t id;
    std::array <char,T> data;
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
    uint16_t id=0;
};

template < size_t T>

class File_Pakage
        {
public:
    static void write(std::string& str_3, const  Messeges<T>&  Messeges_data )
    {
        try{
            std::ofstream file;
            file.open(str_3 );

            for (auto const& i : Messeges_data) {
                write_Msg_file(file,i);
            }
        }
        catch (const std::exception& ex)
        {
            std::cout<<ex.what()<<"\n";
        }

    }


    static   Messeges<T>&   read(std::string& str_3)
    {

        try
        {
            std::ifstream file;
            file.open(str_3);

            char c;
            bool flag = 1;
            bool flag_head = 0;
            bool flag_head_0 = 0;
            bool flag_data=0;
            bool flag_tail = 1;

            Messeges<T> msg;

            std::string data="";

            uint16_t id;

            uint16_t magic;

            uint8_t *magBuf = reinterpret_cast<uint8_t *>(&magic);

            while (file.get(c))
            {
                if (flag) {
                    magBuf[1] = c;
                    flag = 0;
                }
                else {
                    magBuf[0] = magBuf[1];
                    magBuf[1] = c;
                }

                 if ( magic==Tail ) { flag_data=0;  flag_tail=1; data.pop_back();data.clear(); msg.push_back( Msg0<T>(data ,id) ); }

                else if ( flag_data ) { data+=c; } //считываем данные до тех пор, пока не появится tail

                else if ( flag_head ) {   uint16_t id=magic; flag_head=0; flag_head_0=0; flag_data=1;  }//считали два символа id

                else if ( flag_head_0 ) { flag_head=1;  }

                else if ( magic == Head && flag_tail ) { flag_head_0 = 1;  } //появился head
                                       //смотреть cнизу-вверх
            }
        }
        catch (const std::exception& ex)
        {
            std::cout<<ex.what()<<"\n";
        }

    }
private:
    static void write_Msg_file(std::ofstream& file, Msg0<T> msg)
    {

        file.write((char *) &Head, sizeof(Head));

        file.write((char *) &msg.get_id(), sizeof( msg.get_id() ) );


        for (int j = 0; j != msg.get_data().size(); j++)  { file.write((char*)&msg.get_data().at(j), sizeof(msg.get_data().at(j) ) ); }

        file.write((char *) &Tail, sizeof(Tail));
    }

    static  uint16_t Head;
    static uint16_t Tail;

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








#endif
