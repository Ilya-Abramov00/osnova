#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>


int k=0;//счетчик сообщений
bool stop= true;//для остановки  потока записи
bool var= true;//для остановки потока чтения

struct Msg//сообщение
{
    char * begin;
    char * end;
};

int  write_buf( char *buf_0, int sdvig );//функция реализуящая запись


class Write_thread
{
public:

    Write_thread(std::queue <Msg> & queue , char *&buf_0, std::mutex &mtx, int time_ms=0):queue(queue), buf_0(buf_0), mtx(mtx), time_ms(time_ms) {}

    void CreateThr()
    {
        std::thread thr(MyFunc, this);
        thr.detach();
    }
private:
    static void write(std::queue <Msg> & queue , char *buf_0, std::mutex& mtx ,  int time_ms);

    static void MyFunc(Write_thread *p){
        write( p->queue , p->buf_0, p->mtx, p->time_ms);
    }
   static bool stops()
    {
        if( k==512 ) { stop=false; }
        return stop;
    };

    std::mutex& mtx;
    int time_ms;
    std::queue <Msg> & queue;
    char *&buf_0;
};



class Read_thread
{
public:

    Read_thread(std::queue <Msg> & queue , char *&buf_0,std::mutex &mtx, std::string ptr, int time_ms=0) : queue(queue), buf_0(buf_0), mtx(mtx), ptr(ptr) ,time_ms(time_ms) {}

    void CreateThr(){
        std::thread thr(MyFunc, this);
        thr.join();
    }

private:
    static void MyFunc(Read_thread *p)
    {
        read( p->queue ,  p->buf_0, p->mtx, p->ptr,p->time_ms);
    }
    static void read( std::queue <Msg> & queue ,char *buf_0, std::mutex &mtx, std::string ptr, int time_ms );


   static bool ret() { return var;}

    std::mutex& mtx;
    int time_ms;
    std::queue <Msg> & queue;
    char *&buf_0;
    std::string ptr;
};


#endif
