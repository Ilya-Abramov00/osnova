#include <gtest/gtest.h>
#include "include/potoc/potoc.h"





TEST(potoc_test, inicializ) {

    std::queue <char *> queue ;
    char buf[1024];
    char* buf_0=buf;
    int a=write_buf( buf_0, 0);
    ASSERT_TRUE(a == 1024);


}

