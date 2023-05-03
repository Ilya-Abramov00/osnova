

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
    std::queue <char> ad1;



    std::thread qw1([&ad1,&time]
    {
        char a = 1;//иммитация данных

        for(int i=0; i!=1024 ; i++)
        {
            std::unique_lock<std::mutex> mtx_0(mtx);
            for (int j = 0; j != 1024 * 8; j++)
            {

                ad1.push(a);
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::microseconds(time));
        }
    });



    std::cout <<"\n"<< ad1.size()<<"\n";

        std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::trunc);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else
        {

            int m = ad1.size();
            while(ad1.empty())
            {
                auto p = ad1.front();
                fout.write((char *) &p, sizeof(p));
                ad1.pop();
            }
        fout.close();

        }

qw1.join();
    return 1;
}
