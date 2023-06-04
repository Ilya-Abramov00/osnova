#include <gtest/gtest.h>
#include "include/potoc/potoc.h"
#include <unistd.h>

TEST(potoc_test, write_buf) {

    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    int c=write_buf( it, 0);

    ASSERT_TRUE(c == 1024*1024);
    ASSERT_TRUE(it[1024*1024-1]== 'q');

}

TEST(potoc_test, write_th1 )
{
    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    Write_thread q1(queue,it, mtx ,0);
    q1.CreateThr();

    sleep(8);//здесь нужно время для выполнения потока

    ASSERT_TRUE(it[1024*1024*256-1]== 'q');
    ASSERT_TRUE(it[1024*256-1]== 'q');
    ASSERT_TRUE(it[0]== 'q');
    ASSERT_TRUE( queue.size() == 256);

    Read_thread q2( queue, it, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();

    sleep(10);

    ASSERT_TRUE( queue.size() == 0);

}

TEST(potoc_test, write_th2 )
{
    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    Write_thread q1(queue,it, mtx ,0);
    q1.CreateThr();

    Read_thread q2( queue, it, mtx , "/home/ilya/zad2.txt" );
    q2.CreateThr();

    sleep(9);

    ASSERT_TRUE( queue.size() == 0);

    ASSERT_TRUE(it[1024*1024*256-1]== 'q');
    ASSERT_TRUE(it[1024*256-1]== 'q');
    ASSERT_TRUE(it[0]== 'q');

}



