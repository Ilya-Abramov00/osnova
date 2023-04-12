#include <gtest/gtest.h>
#include "signal.h"
#include "complex.h"
#include <iostream>
using namespace std;

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */
TEST(signal_test, downsample) {
complex<float>a={1,2,3,4};
    auto b=downsample(a,2);
    auto m=a.size();
    ASSERT_TRUE(m==2);
    ASSERT_TRUE(b.ap(0)==1);
    ASSERT_TRUE(b.ap(1)==3);
    }

TEST(signal_test, diff)
{
complex<float>a={1,2,3,4};
auto b=diff(a);
auto m=a.size();
ASSERT_TRUE(m==3);
ASSERT_TRUE(b.ap(0)==1);
ASSERT_TRUE(b.ap(1)==1);
ASSERT_TRUE(b.ap(2)==1);
}
TEST(signal_test, RECfil)
{
complex<float>a={1,2,3,4};
auto b=Recursiv::filstr(a,2);
auto m=a.size();
ASSERT_TRUE(m==4);
ASSERT_TRUE(b.ap(0)==1);
ASSERT_TRUE(b.ap(1)==1.5);
ASSERT_TRUE(b.ap(2)==2.5;
ASSERT_TRUE(b.ap(3)==3.5);
}

TEST(signal_test, NORECfil)
{
complex<float>a={1,2,3,4};
auto b=Norecursiv::filstr(a,2);
auto m=a.size();
ASSERT_TRUE(m==4);
ASSERT_TRUE(b.ap(0)==1);
ASSERT_TRUE(b.ap(1)==1.5);
ASSERT_TRUE(b.ap(2)==2.5;
ASSERT_TRUE(b.ap(3)==3.5);
}
