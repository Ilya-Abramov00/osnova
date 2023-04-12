#include <gtest/gtest.h>
#include "complex.h"

/**
 * @brief этот тест ничего не тестирует. это стартовый тест, который был написан до написания кода свомого принтера.
 * если этот тест проходит успешно, то конструкторы этого класса реализованны и с созданием объекта всё ок.
 */
TEST(complex_test, inicializ) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re()==1);
      ASSERT_TRUE(a.Im()==0);
      cout<<a;
}

TEST(complex_test, read) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re()==1);
      ASSERT_TRUE(a.Im()==0);
        cout<<a;
}

TEST(complex_test, write) {
    complex<int >a(1);
   ASSERT_TRUE(a.Re(2)==2);
      ASSERT_TRUE(a.Im(4)==4);
       cout<<a;
}

TEST(complex_test, abs) {
    complex<float >a(-3,4);
   ASSERT_TRUE(a.Abs()==5);


}
TEST(complex_test, Arg) {
    complex<float >a(-2,0);

   cout<<a.Arg()<<endl;
   }

TEST(complex_test, Arg1)
  {
    complex<float >b(0,0);

        cout<<b.Arg()<<endl;
        }

TEST(complex_test, ArgDeg)
 {
    complex<float >a(-2,2);

      cout<<a.ArgDeg()<<endl;

}

TEST(complex_test, conj) {

    complex<float >a(-3,4);
    a.conj();
   ASSERT_TRUE(a.Re()==-3);
      ASSERT_TRUE(a.Im()==-4);
}

TEST(complex_test, CreateComplexFromPhaseDeg) {

    auto a=complex<float>::Factory::CreateComplexFromPhaseDeg(PI);
  cout<<a;
  ASSERT_TRUE(a.Re()==-1);
      ASSERT_TRUE(a.Im()<0.01);
}


