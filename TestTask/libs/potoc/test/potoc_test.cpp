#include <gtest/gtest.h>
#include "include/potoc/potoc.h"
#include <unistd.h>

TEST(potoc_test, write_buf) {

    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];

    int a=write_buf( buf_0, 0);

    ASSERT_TRUE(a == 1024*1024);
    ASSERT_TRUE(buf_0[1024*1024-1]== 'q');
delete [] buf_0;
}

TEST(potoc_test, write_th1 )
{
    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];
    std::mutex mtx;
    Write_thread q1(queue,buf_0, mtx ,0);
    q1.CreateThr();

    sleep(8);//здесь нужно время для выполнения потока

    ASSERT_TRUE(buf_0[1024*1024*256-1]== 'q');
    ASSERT_TRUE( queue.size() == 256);

    Read_thread q2( queue, buf_0, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();

    sleep(10);
    ASSERT_TRUE(buf_0[1024*1024*2-1]== 'q');
    ASSERT_TRUE(buf_0[1024*1024*256-1]== 'q');
    ASSERT_TRUE( queue.size() == 0);
    delete [] buf_0;
}

TEST(potoc_test, write_th2 )
{
    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];
    std::mutex mtx;
    Write_thread q1(queue,buf_0, mtx ,0);
    q1.CreateThr();

    Read_thread q2( queue, buf_0, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();

    sleep(9);

    ASSERT_TRUE( queue.size() == 0);

    ASSERT_TRUE(buf_0[1024*1024*256-1]== 'q');

    delete [] buf_0;
}



