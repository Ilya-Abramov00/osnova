#include <gtest/gtest.h>
#include "include/complex/complex.h"
#include <iostream>
using namespace std;

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */
TEST(complex_test, inicializ) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re()==1);
      ASSERT_TRUE(a.Im()==0);
    
}

TEST(complex_test, read) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re()==1);
      ASSERT_TRUE(a.Im()==0);
      
}

TEST(complex_test, write) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re(2)==2);
      ASSERT_TRUE(a.Im(4)==4);
     
}

TEST(complex_test, abs) {
    complex<float >a(-3,4);
   ASSERT_TRUE(a.Abs()==5);


}

TEST(complex_test, Arg1)
  {
    complex<float >a(0,0);
      ASSERT_TRUE(a.Arg()==0);
        }



TEST(complex_test, conj) {

    complex<float >a(-3,4);
    a.conj();
   ASSERT_TRUE(a.Re()==-3);
      ASSERT_TRUE(a.Im()==-4);
}

TEST(complex_test, CreateComplexFromPhaseDeg) {

    auto a=complex<float>::Factory::CreateComplexFromPhaseDeg(PI);
  
  ASSERT_TRUE(a.Re()==-1);
      ASSERT_TRUE(a.Im()<0.01);
}


