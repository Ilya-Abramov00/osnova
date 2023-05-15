#include "potoc/potoc.h"

int GetRandomNumber(int min, int max)
{
    // Установить генератор случайных чисел
    srand(time(NULL));

    // Получить случайное число - формула
    int num = min + rand() % (max - min + 1);

    return num;
}

int  write_buf( char *buf_0, int sdvig )//иммитация записи 1 мб данных( с рандомной скоростью)
{
    char a='q';
    int data_size=1024*1024;

    auto start=std::chrono::high_resolution_clock::now();

    for (int j = 0; j != data_size ; j++)
    {
        *(buf_0+sdvig +j)=a ;

    }
    std::this_thread::sleep_for(std::chrono::microseconds(GetRandomNumber(0,5000)));//искуственное рандомое замедление
    auto end=std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration=end-start;
    std::cout<<"\n скорость записи мб/с= "<<int(1/duration.count())<<"\n";

    return data_size;
}

void write(std::queue <Msg> & queue , char *buf_0 )
{

    while ( stops() )

    {
        int sdvig=1024*1024*k;//уже записано столько (к мегабайт)

        int data_size= write_buf( buf_0, sdvig);
        Msg msg;
        msg.begin =buf_0+sdvig;
        msg.end =msg.begin+data_size;

        std::unique_lock <std::mutex> mtx_0 (mtx);

        queue.push( msg) ;

        mtx_0.unlock();


        if (queue.size()>=256 )
        {
            std::cout<<"\n Очередь переполнена, Ошибка \n";
            std::cout<<"\n Сообщений отправлено="<<k;
            stop=false;
        }

        k++;
    }
    var = false;
    std::cout<<"\n Запись закончена \n";
}
void read( std::queue <Msg> & queue ,char *buf_0 )
{

    std::ofstream fout("/home/ilya/zad2.txt", std::ios_base::app | std::ios_base::out);

    while ( ret() )
    {
        while ( queue.size() != 0)
        {
            Msg msg;
            std::cout<<"\n размер очереди= "<< queue.size();
            msg= queue.front();
            queue.pop();

            auto start=std::chrono::high_resolution_clock::now();


            for( ;  msg.begin !=msg.end ;  msg.begin ++ )
            {
                char data=*( msg.begin );
                fout.write((char *) &data, 1);

            }

            auto end=std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration=end-start;
            std::cout<<"\n скорость сохранения мб/с= "<<int(1/duration.count())<<"\n";
        }

    }
    std::cout<<"\n размер очереди=  "<< queue.size();
    fout.close();
}



