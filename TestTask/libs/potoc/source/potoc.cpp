#include "potoc/potoc.h"


int  write_buf( std::vector <char> :: iterator it, int sdvig )//иммитация записи 1 мб данных
{
    char a='q';
    int data_size=1024*1024;
    for (int j = 0; j != data_size ; j++)
    {
        *(it+sdvig +j)=a ;
    }
    return data_size;
}



void Write_thread::  write(std::queue <Msg> & queue , std::vector <char> :: iterator it, std::mutex& mtx ,Qw &qw,  int const  time_ms)
{
    while ( stops(qw) )
    {
        int sdvig=1024*1024*qw.k; sdvig%=1024*1024*256;//уже записано столько (к мегабайт) циклический буффер

        auto start=std::chrono::high_resolution_clock::now();
        {
            int data_size = write_buf(it, sdvig);
            std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));//замедление

            Msg msg;
            msg.begin = it + sdvig;
            msg.end = msg.begin + data_size;
            std::unique_lock<std::mutex> mtx_0(mtx);
            queue.push(msg);
            mtx_0.unlock();
        }
        if (queue.size()>=qw.q ) qw.q=queue.size();

        if (queue.size()>=256 )
        {
            std::cout<<"\n Очередь переполнена, Ошибка \n";
            std::cout<<"\n Сообщений отправлено="<<qw.k+1<<std::endl;
            qw.stop=false;
        }
        qw.k++;

        auto end=std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration=end-start;
        std::cout<<"\n скорость записи мб/с= "<<int(1/duration.count())<<"\n";
    }
    qw.var = false;
    std::cout<<"\n Запись закончена \n";
}


void Read_thread::read( std::queue <Msg> & queue ,std::vector <char> :: iterator it,std::mutex& mtx,Qw &qw, const std::string& ptr, int const  time_ms )
{
    std::ofstream fout(ptr, std::ios_base::app | std::ios_base::out);
    if (!fout.is_open()) { std::cout << "Файл не может быть создан\n";  qw.clear(); }
    {
        while (ret(qw) ) {
            while (queue.size() != 0) {
                auto start = std::chrono::high_resolution_clock::now();
                Msg msg;
                {
                    std::unique_lock<std::mutex> mtx_0(mtx);
                    msg = queue.front();
                    queue.pop();
                    std::cout << "\n размер очереди= " << queue.size() << std::endl;
                    mtx_0.unlock();
                }
                for (; msg.begin != msg.end; msg.begin++) {
                    char data = *(msg.begin);
                    fout.write((char *) &data, 1);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(time_ms));//замедление

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> duration = end - start;
                std::cout << "\n скорость сохранения мб/с= " << int(1 / duration.count()) << "\n";

            }
        }
        std::cout << " \n\n\n сохранениe завершено\n ";
        std::cout << "\n максимальный размер очереди= " << qw.q << "\n ";
        std::cout << "\n Сообщений отправлено=" << qw.k << "\n ";;
        fout.close();
    };
    qw.clear();
}



