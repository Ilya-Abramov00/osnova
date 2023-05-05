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


std::mutex mtx;
std::condition_variable cv;
int k=0;

bool var= true;//для остановки второго потока

bool ret() { return var;}

bool stop= true;//для остановки первого потока

bool stops()
{
    if( k==1023 ) { stop=false; }
    return stop;
};


int  write_buf( char *buf_0, int sdvig )//иммитация записи данных с рандомной скоростью
{
    char a='q';
    int data_size=1024;
    auto start=std::chrono::high_resolution_clock::now();

    for (int j = 0; j != data_size ; j++)
    {
        *(buf_0+sdvig +j)=a ;
        std::this_thread::sleep_for(std::chrono::microseconds(GetRandomNumber(1,2)));
    }

    auto end=std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration=end-start;
    std::cout<<"\n количество операций записи данных в секунду= "<<int(1024/duration.count())<<"\n";

    return data_size;
}

struct Msg//сообщение
{
    char * begin;
    char * end;
};


void write(std::queue <Msg> & queue , char *buf_0 )
{

    while ( stops() )

    {
        int sdvig=1024*k;//уже записано столько мб

        int data_size= write_buf( buf_0, sdvig);
        Msg msg;
        msg.begin =buf_0+sdvig;
        msg.end =msg.begin+data_size;

       std::unique_lock <std::mutex> mtx_0 (mtx);

        queue.push( msg) ;

        mtx_0.unlock();


        if (queue.size()>255 )
        {
            std::cout<<"\n Очередь переполнена, Ошибка \n";
            stop=false;
        }
        k++;
    }
    var = false;
}


void read( std::queue <Msg> & queue ,char *buf_0 )
{

    std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::app | std::ios_base::out);

    while ( ret() )
    {
        while ( queue.size() != 0)
        {
            Msg msg;
            std::cout<<"\n количество элементов в очереди на сохрание= "<< queue.size();
            msg= queue.front();
            queue.pop();

            for( ;  msg.begin !=msg.end ;  msg.begin ++ )
            {
                char data=*( msg.begin );
                fout.write((char *) &data, 1);
                std::this_thread::sleep_for(std::chrono::microseconds(GetRandomNumber(15,25)));
            }

        }

    }
    std::cout<<"\n количество элементов в очереди на сохрание= "<< queue.size();
    fout.close();
}

#endif
