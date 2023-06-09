#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <iterator>
#include <vector>

int  write_buf( std::vector <char> :: iterator it, int sdvig );//функция реализуящая запись

class Qw {
    friend class Write_thread;
    friend class Read_thread;
private:
    void clear()
    {
        stop= true; var= true;  q=0; k=0; //обнуляем глобальные переменные
    }

    int k = 0;//счетчик сообщений
    bool stop = true;//для остановки  потока записи
    bool var = true;//для остановки потока чтения
    int q = 0;//cчетчик max_bufer
};

class Msg//сообщение
{
    friend class Write_thread;
    friend class Read_thread;
private:
    std::vector <char> :: iterator begin;
    std::vector <char> :: iterator  end;
};


class Write_thread
{
    friend class Protocol;
private:

    Write_thread(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex &mtx, Qw &qw,int const  time_ms=0 ):queue(queue), it(it), mtx(mtx),  qw(qw),time_ms(time_ms) {}

    static void write(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex& mtx ,Qw &qw,  int const time_ms);

    static void MyFunc(Write_thread *p)
    {
        write( p->queue , p-> it, p->mtx,p->qw, p->time_ms);
    }

  static bool stops(Qw &qw)
    {
        if( qw.k==512 ) { qw.stop=false; }
        return qw.stop;
    };

    Write_thread (Write_thread const& a );
    Write_thread& operator= (Write_thread const& a );

    std::mutex& mtx;
    int const time_ms;
    std::queue <Msg> & queue;
    std::vector <char> :: iterator it;
    Qw &qw;
};



class Read_thread
{
    friend class Protocol;
private:

    Read_thread(std::queue <Msg> & queue , std::vector <char> :: iterator const it, std::mutex &mtx, const std::string& ptr, Qw &qw, int const time_ms=0) : queue(queue), it(it), mtx(mtx), ptr(ptr) ,qw(qw),time_ms(time_ms) {}

    static void MyFunc(Read_thread *p)
    {
        read( p->queue ,  p->it, p->mtx,p->qw, p->ptr, p->time_ms );
    }

    static void read( std::queue <Msg> & queue ,std::vector <char> :: iterator const it, std::mutex &mtx, Qw& qw, const std::string& ptr, int const time_ms );

    static  bool ret( Qw &qw) { return qw.var;}

    Read_thread (Read_thread const& a );
    Read_thread& operator= (Read_thread const& a );

    Qw &qw;
    std::mutex& mtx;
    int time_ms;
    std::queue <Msg> & queue;
    std::vector <char> :: iterator const it;
    const std::string& ptr;
};


class Protocol{
public:
    Protocol(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex &mtx, const std::string& ptr, int time_ms_write=0, int time_ms_read=0 ):queue(queue), it(it), mtx(mtx),ptr(ptr), time_ms_write(time_ms_write),time_ms_read(time_ms_read) {};

       void start()
       {
       auto* a=new Write_thread (this->queue,this->it,this-> mtx ,this->qw,this->time_ms_write);
       auto* b=new  Read_thread( this->queue, this->it,this-> mtx , this->ptr,this->qw,this->time_ms_read );

       std::thread t1(&Write_thread::MyFunc ,a );
       std::thread t2(& Read_thread::MyFunc, b );

       t1.join(); t2.join();
       delete a; delete b;
    }
private:
    Protocol( Protocol const& a );
    Protocol& operator= ( Protocol const& a );

    Qw qw;
    std::queue <Msg> & queue;
    std::vector <char> :: iterator it;
    std::mutex& mtx;
    const std::string& ptr;
    int time_ms_write;
    int time_ms_read;
};


#endif
