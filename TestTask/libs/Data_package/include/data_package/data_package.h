//#ifndef DATA_PACKAGE_H
//#define DATA_PACKAGE_H

int a=2;

class Qw {

private:
    void clear()
    {
        stop= true; var= true;  q=0; k=0; //обнуляем глобальные переменные
    }

    int k = 0;//счетчик сообщений
    bool stop = true;//для остановки  потока записи
    bool var = true;//для остановки потока чтения
    int q = 0;//cчетчик max_bufer
};


//#endif
