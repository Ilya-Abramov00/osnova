#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>


std::mutex mtx;
std::condition_variable cv;
int k=0;

bool var= true;//для остановки второго потока

bool ret() { return var;}

bool stop= true;//для остановки первого потока

bool stops()
{
    if( k==256 ) { stop=false; }
    return stop;
};


int  write_buf( char *buf_0, int sdvig );

struct Msg//сообщение
{
    char * begin;
    char * end;
};


void write(std::queue <Msg> & queue , char *buf_0 );


void read( std::queue <Msg> & queue ,char *buf_0, std::string ptr );


class Write_thread
{
public:

    Write_thread(std::queue <Msg> & queue , char *&buf_0):queue(queue), buf_0(buf_0) {}

    void CreateThr()
    {
        std::thread thr(MyFunc, this);
        thr.detach();
    }

private:
    static void MyFunc(Write_thread *p){
        write( p->queue ,  p->buf_0);
    }
    std::queue <Msg> & queue;
    char *&buf_0;
};

class Read_thread
{
public:

    Read_thread(std::queue <Msg> & queue , char *&buf_0, std::string ptr) : queue(queue), buf_0(buf_0), ptr(ptr) {}

    void CreateThr(){
        std::thread thr(MyFunc, this);
        thr.join();
    }

private:
    static void MyFunc(Read_thread *p)
    {
        read( p->queue ,  p->buf_0, p->ptr);
    }
    std::queue <Msg> & queue;
    char *&buf_0;
    std::string ptr;
};


#endif
