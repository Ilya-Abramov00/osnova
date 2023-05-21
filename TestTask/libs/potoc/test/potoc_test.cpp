#include <gtest/gtest.h>
#include "include/potoc/potoc.h"


/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 *///пока что ничего не менял

TEST(potoc_test, write_buf) {

    std::queue <Msg> queue ;
    char buf[1024*1024]={0};
    char* buf_0=buf;

    int a=write_buf( buf_0, 0);

    ASSERT_TRUE(a == 1024*1024);

    ASSERT_TRUE(buf[1023*1024-1]== 'q');
}


TEST(potoc_test, write_read )
{
    std::queue <Msg> queue ;
    char * buf_0=new char[1024*1024*256];

    write( queue , buf_0 );

    ASSERT_TRUE(queue.size() == 256);
}




