
#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

bool var= true;//для остановки второго потока
bool ret() { return var;}

bool stop= true;//для остановки первого потока
int k=0;

bool stops(){
    if(k==1024){stop=false;}
    return stop;
};




    void read(std::queue <char>& buf1 , int time1)
    {
        char a = 'q';//иммитация записи данных
        while (stops())
        {
            std::unique_lock<std::mutex> mtx_0(mtx);
            while(buf1.size()!=0)
            {
                    cv.wait(mtx_0);//пока он занят, запись запрещена
            }

            for (int j = 0; j != 1024; j++) { buf1.push(a); }

            mtx_0.unlock();

            std::this_thread::sleep_for(std::chrono::microseconds(time1));
            k++;
        }
        var = false;
    }

void write(std::queue <char>& buf1 )
{
    std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::app | std::ios_base::out);
    while (ret())
    {
        while (buf1.size() != 0)
        {
            auto p = buf1.front();
            fout.write((char *) &p, 1);
            buf1.pop();
        }
        cv.notify_one();

    }
    fout.close();
}

int main()
{
        int time=20;
        std::queue <char> buf;

        std::thread q1(read, std::ref (buf) , time );

        std::thread q2(write, std::ref (buf) );

        q1.join();
        q2.join();

    if( buf.size()==0){ std::cout<<" \n Очередь пуста";}
    return 1;
}
