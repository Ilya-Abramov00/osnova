#include <gtest/gtest.h>
#include "signal.h"
#include "complex.h"
#include <iostream>
using namespace std;

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */
TEST(signal_test, inicializ) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re()==1);
      ASSERT_TRUE(a.Im()==0);
      cout<<a;
}
