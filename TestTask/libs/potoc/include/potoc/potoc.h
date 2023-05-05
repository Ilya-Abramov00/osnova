#ifndef POTOC_H
#define POTOC_H

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>//12

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

int  write_buf( char *buf_0, int sdvig )//иммитация записи данных
{
    char a='q';
    int data_size=1024;
    for (int j = 0; j != data_size ; j++)
    {
        *(buf_0+sdvig +j)=a ;
        std::this_thread::sleep_for(std::chrono::microseconds(20));
    }
    return data_size;
}


void write(std::queue <char*> & queue , char *buf_0 )
{
    while ( stops() )

    {
        int sdvig=1024*k;//уже записано столько мб


       if (queue.size()>253 )
        {
            std::cout<<"\n Очередь переполнена, Ошибка \n";
            stop=false;
        }

        int data_size= write_buf( buf_0, sdvig);

        auto buf_begin=buf_0+sdvig;
        auto buf_end=buf_begin+data_size;

        queue.push(buf_begin ) ;
        queue.push(buf_end );



        k++;
    }
    var = false;
}

void read( std::queue <char *> & queue ,char *buf_0 )
{

    std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::app | std::ios_base::out);
int e=1;//механизм на случай, не сработки функции ret()
    while ( ret() && e<1024)
    {
        while ( queue.size() != 0)
        {
            auto p_begin = queue.front();
            queue.pop();
            auto p_end = queue.front();
            queue.pop();

            for( ; p_begin != p_end ; p_begin++ )
            {
                char data=*(p_begin);
                fout.write((char *) &data, 1);
            }

        }
        e++;
    }
    fout.close();
}

#endif
