#include <gtest/gtest.h>
#include "include/potoc/potoc.h"


/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */

TEST(potoc_test, write_buf) {

    std::queue <Msg> queue ;
    char buf[1024*1024]={0};
    char* buf_0=buf;

    int a=write_buf( buf_0, 0);

    ASSERT_TRUE(a == 1024);

      ASSERT_TRUE(buf[1023]== 'q');
}


TEST(potoc_test, write_read )
{
    std::queue <Msg> queue ;
    char buf[1024*1024];
    char* buf_0=buf;

    write( queue , buf_0 );
    ASSERT_TRUE(queue.size() == 256);

    var=true;
    read( queue , buf_0 );

    ASSERT_TRUE(queue.size() == 0);
    ASSERT_TRUE(buf[1024*256-1]== 'q');

}





