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

std::random_device rd;
std::mt19937 gen(rd());

int random_n(int a, int b);
int random_l(int N);
int random_n();

void geniration_string(int n, int N, std::string& str_1);


std::vector<char> readfullfile(std::string& namefile){

  std::ifstream file;
  file.open(namefile);

  if(!file. is_open() ) {std::cout<<"не открылся";}

  file.seekg(0, std::ios::end);
  size_t sizefile = file.tellg();
  file.seekg(0);

  std::vector<char> bufferfile(sizefile);
  auto data=bufferfile.data();

  file.read(data,sizefile);

  if (file.fail()) {std::cout<<"искл";}

  file.close();

  return bufferfile;
}


template < size_t T>

struct Msg{
public:
    Msg( const std::string& data_s , uint16_t id) :id(id)
    {
          for( int i=0; i!=data_s.size(); i++ )  {  data[i]=data_s[i] ;  }
    }
    Msg( const std::string& data_s , uint16_t id, size_t N) :id(id)
    {
        for( int i=0; i!=N; i++ )
        {
            if (i< data_s.size() ) { data[i]=data_s[i] ;}
            else {data[i]='^';}
        }
    }
    uint16_t const& get_id() { return  id; }

    char const *  get_data() {   return data; }

private:
    uint16_t id;
    char  data[T];
};

template < size_t T>
bool operator<( Msg<T>& x, Msg<T>& y)
{
    return x.get_id() < y.get_id();
}


template < size_t T>
using Messeges=std::list <Msg<T>>;

template < size_t T>

class File_parser{
public:

    Messeges<T> get_File_parser( std::string& filename )
    {
            Messeges<T> Messeges_data;

            auto bufferfile= readfullfile(filename);
            std::string buffer; buffer.reserve(T);

            for(int k=1; k!=bufferfile.size()+1; k++)
            {
                  buffer.push_back(bufferfile.at(k-1));
                if ( !(k % T) )
                {
                    Messeges_data.emplace_back( Msg<T>(buffer, ++id) );
                    buffer.clear();
                }
            }
            Messeges_data.emplace_back( Msg<T>(buffer, ++id, T) );
            buffer.clear();
            return  Messeges_data;
    }
private:
    uint16_t id=0;
};



enum class State{Idle,Magicbegin,Idcollecting,Datacollecting,Magicend};
template < size_t T>

class StateMachine
{
  public:
    StateMachine(): state(State::Idle) {}
    void  ReadMesseges (std::vector<char>& bufferfile , Messeges<T>& Messeges_data, uint16_t Head=0xBABA, uint16_t Tail=0xDEDA)
    {

            state=State::Magicbegin;
            uint16_t magic;
            uint16_t id = 0;
            uint8_t *magBuf = reinterpret_cast<uint8_t *>(&magic);
            std::string data="";

            int k=0;

            for(int i=0;i!=bufferfile.size();i++)
            {

               if ( i%2==0 )
                {
                    magBuf[1] = bufferfile.at(i);
                } else
                {
                    magBuf[0] = magBuf[1];
                    magBuf[1] = bufferfile.at(i);
                }

                switch (state)
                {

                case (State::Magicbegin):
                    if ( magic==Head )
                    { state=State::Idcollecting;}
                    break;

                case (State::Idcollecting):
                    k++;
                    if (k==2)
                    { id=magic; state=State::Datacollecting; k=0;}

                    break;

                case (State::Datacollecting):
                    data.push_back( bufferfile.at(i)  );
                    if ( magic==Tail )
                    { state=State::Magicend;
                      data.pop_back();
                    Messeges_data.push_back(Msg<T>(data, id));
                     data.clear();
                    }

                    break;

                case (State::Magicend):
                    state=State::Magicbegin;
                  break;

                }
            }

            if(state==State::Magicend) { state=State::Idle;}
            return ;
    }
    State get(){
            return state;
    }
  private:

    State state;
};


template < size_t T>
class File_Package{
public:

    File_Package(Messeges<T> Messeges_data) :Messeges_data(Messeges_data){}

    File_Package() { }


     void write(std::string& str_3 )
    {
        try
        {
            std::ofstream file;
            file.open(str_3 ,std::ios::trunc);
            //проверка

            for (auto const& i :  this->Messeges_data) {
                write_Msg_file(file,i);
            }
        }
        catch (const std::exception& ex)
        {
            std::cout<<ex.what()<<"\n";
        }
    }

      void   read(std::string& namefile)
    {

            auto bufferfile= readfullfile(namefile);

StateMachine<T> a;
a.ReadMesseges(bufferfile,this->Messeges_data);


/*
            bool flag = 1;
            bool flag_head = 0;
            bool flag_head_0 = 0;
            bool flag_data = 0;
            bool flag_tail = 1;

            std::string data = "";

            uint16_t id = 0;

            uint16_t magic;

            uint8_t *magBuf = reinterpret_cast<uint8_t *>(&magic);

           for(int i=0; i!=bufferfile.size(); i++) {
            if ( i%2==0 )
            {
                magBuf[1] = bufferfile.at(i);
            } else
            {
                magBuf[0] = magBuf[1];
                magBuf[1] = bufferfile.at(i);
            }

            if (magic == Tail) {
                flag_data = 0;
                flag_tail = 1;
                data.pop_back();

                this->Messeges_data.push_back(Msg<T>(data, id));
                data.clear();
            } else if (flag_data) {
                data += bufferfile.at(i);
            } // считываем данные до тех пор, пока не появится tail

            else if (flag_head) {
                id = magic;
                flag_head = 0;
                flag_head_0 = 0;
                flag_data = 1;
            } // считали два символа id

            else if (flag_head_0) {
                flag_head = 1;
            }

            else if (magic == Head && flag_tail) {
                flag_head_0 = 1;
            } // появился head
            // смотреть cнизу-вверх
            }
            */
      }
    void sort_Messeges(){
        Messeges_data.sort();
    }
    void clear(){
        Messeges_data.clear();
    }
      std::string Data_Repoirter( )
       {
           std::string str;
           auto end =Messeges_data.end();
           auto begin = this->Messeges_data.begin();
           --end;
           while(begin != end)
           {
               for(int j=0; j!=T; j++  )
               {
                   str.push_back(begin->get_data()[j] ) ;
               }
               begin++;
           }

           int k=0;
           while( ( k!=T ) && (end->get_data()[k]!='^') )
           {
               str.push_back(end->get_data()[k++] ) ;
           }
           return str;
        }
     static void write_string(std::string data, std::string& str_3)
     {
         try
         {
             std::ofstream file;
             file.open(str_3 ,std::ios::trunc);
             file<<data;
         }
         catch (const std::exception& ex)
         {
             std::cout<<ex.what()<<"\n";
         }
     }
    static std::string read_string( std::string& str_3)
    {
        try
        {
            std::ifstream file2;
            file2.open(str_3);
            char c2;
            std::string str2="";

            while (file2.get(c2))
            {
                str2+=c2;
            }
            return  str2;
        }
        catch (const std::exception& ex)
        {
            std::cout<<ex.what()<<"\n";
        }
    }

    void shuffle_write(std::string& str_2  )
    {
try
{
    std::vector<std::reference_wrapper<const Msg<T> >>v(Messeges_data.cbegin(), Messeges_data.cend());
    std::shuffle(v.begin(), v.end(), gen);

    std::ofstream file;
    file.open(str_2,std::ios::trunc);

    for(int  i=0; i!=v.size(); i++){
        write_Msg_file(file, v.at(i).get() );
    }
    file.close();
}

 catch (const std::exception& ex)
 {
    std::cout<<ex.what()<<"\n";
 }
    }
    Messeges<T> const & get_Messeges_data()
    {
        return Messeges_data;
    }


     void write_Msg_file(std::ofstream& file, Msg<T> msg)
    {
        file.write((char *) &Head, sizeof(Head));
        file.write((char *) &msg.get_id(), sizeof( msg.get_id() ) );
        file.write ( msg.get_data(), T );
        file.write((char *) &Tail, sizeof(Tail));
    }


private:
      uint16_t Head=0xBABA;
      uint16_t Tail=0xDEDA;
    Messeges<T> Messeges_data;
};



#endif
