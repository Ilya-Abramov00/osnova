#include <gtest/gtest.h>
#include "include/potoc/potoc.h"



/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */

TEST(potoc_test, inicializ) {

    std::queue <char *> queue ;
    char buf[1024];
    char* buf_0=buf;
    int a=write_buf( buf_0, 0);
    ASSERT_TRUE(a == 1024);
    ASSERT_TRUE(21 == 103);

}

