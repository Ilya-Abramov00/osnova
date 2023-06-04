#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iterator>
#include <vector>



class Qw {
    friend class Write_thread;
    friend class Read_thread;
    void clear()
   {
       stop= true; var= true;  q=0; k=0; //обнуляем глобальные переменные
   }
    int k = 0;//счетчик сообщений
    bool stop = true;//для остановки  потока записи
    bool var = true;//для остановки потока чтения
    int q = 1;//cчетчик max_bufer

};Qw qw;

struct Msg//сообщение
{
    friend class Write_thread;
    friend class Read_thread;
private:
    std::vector <char> :: iterator begin;
    std::vector <char> :: iterator  end;

};

int  write_buf( std::vector <char> :: iterator it, int sdvig );//функция реализуящая запись

class Write_thread
{
public:

    Write_thread(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex &mtx, int time_ms=0):queue(queue), it(it), mtx(mtx), time_ms(time_ms) {}

    void CreateThr()
    {
        std::thread thr(MyFunc, this);
        thr.detach();
    }

private:
    static void write(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex& mtx ,  int time_ms);

    static void MyFunc(Write_thread *p){
        write( p->queue , p-> it, p->mtx, p->time_ms);
    }
   static bool stops()
    {
        if( qw.k==512 ) { qw.stop=false; }
        return qw.stop;
    };
    Write_thread (Write_thread const& a );
    Write_thread& operator= (Write_thread const& a );
    std::mutex& mtx;
    int time_ms;
    std::queue <Msg> & queue;
    std::vector <char> :: iterator it;
};



class Read_thread
{
public:

    Read_thread(std::queue <Msg> & queue , std::vector <char> :: iterator const it,std::mutex &mtx, std::string ptr, int time_ms=0) : queue(queue), it(it), mtx(mtx), ptr(ptr) ,time_ms(time_ms) {}

    void CreateThr(){
        (MyFunc, this);

    }

private:
    static void MyFunc(Read_thread *p)
    {
        read( p->queue ,  p->it, p->mtx, p->ptr,p->time_ms);
    }
    static void read( std::queue <Msg> & queue ,std::vector <char> :: iterator const it, std::mutex &mtx, std::string ptr, int time_ms );

   static bool ret() { return qw.var;}

    Read_thread (Read_thread const& a );
    Read_thread& operator= (Read_thread const& a );

    std::mutex& mtx;
    int time_ms;
    std::queue <Msg> & queue;
    std::vector <char> :: iterator const it;
    std::string ptr;
};



#endif
