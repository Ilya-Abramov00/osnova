
#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

int main()
{
    int time=20;
    std::queue <char> buf;




    std::thread qw1([&buf,&time]
    {
        char a = 1;//иммитация данных
        for(int i=0; i!=1024 ; i++)
        {
            std::unique_lock<std::mutex> mtx_0(mtx);
            for (int j = 0; j != 1024 * 8; j++)
            {
                buf.push(a);
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::microseconds(time));
        }
    });


    std::thread qw2([&buf]
    {
        std::cout <<"\n"<< buf.size()<<"\n";
        std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::app | std::ios_base::out);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else
        {
            int m =buf.size();
            while(buf.empty())
            {
                auto p = buf.front();
                fout.write((char *) &p, sizeof(p));
                buf.pop();
            }
        fout.close();
        }
    });

qw1.join();
qw2.join();
    return 1;
}
