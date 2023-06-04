#include <gtest/gtest.h>
#include "include/potoc/potoc.h"


TEST(potoc_test, write_buf) {

    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    int c=write_buf( it, 0);

    ASSERT_TRUE(c == 1024*1024);
    ASSERT_TRUE(it[1024*1024-1]== 'q');
    ASSERT_TRUE(it[1024]== 'q');
    ASSERT_TRUE(it[0]== 'q');
}

TEST(potoc_test, write_th1 )
{
    std::queue <Msg> queue ;
    std::vector<char> a;
    a.reserve(1024*1024*256);
    std::vector <char> :: iterator it=a.begin();
    std::mutex mtx;

    Protocol q(queue, it, mtx, "/home/ilya/zad2.txt");
    q.start();

    ASSERT_TRUE(it[1024*1024*256-1]== 'q');
    ASSERT_TRUE(it[1024*256-1]== 'q');
    ASSERT_TRUE(it[0]== 'q');
    ASSERT_TRUE( queue.size() == 0);

}




