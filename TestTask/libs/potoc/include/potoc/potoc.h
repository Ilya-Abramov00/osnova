#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

int GetRandomNumber(int min, int max)
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
}

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

    Write_thread(std::queue <Msg> & queue , char *&buf_0):queue(queue), buf_0(buf_0) {}

    void CreateThr()
    {
        std::thread thr(MyFunc, this);
        thr.detach();
    }


private:
    static void write(std::queue <Msg> & queue , char *buf_0 );

    static void MyFunc(Write_thread *p){
        write( p->queue ,  p->buf_0);
    }

   static bool stops()
    {
        if( k==256 ) { stop=false; }
        return stop;
    };

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
    static void read( std::queue <Msg> & queue ,char *buf_0, std::string ptr );


   static bool ret() { return var;}

    std::queue <Msg> & queue;
    char *&buf_0;
    std::string ptr;

};


#endif
