#include <gtest/gtest.h>
#include "list/list.h"

TEST(list_test, 1) {
    List<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    ASSERT_TRUE(a[0]==1);
    ASSERT_TRUE(a[1]==2);
    ASSERT_TRUE(a[2]==2);
}

TEST(list_test, 2) {
    List<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(2);

    ASSERT_TRUE(a[0]==2);
    ASSERT_TRUE(a[1]==1);
    ASSERT_TRUE(a[2]==2);
}

TEST(list_test, 3) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.pop_back();
    a.push_back(3);

    ASSERT_TRUE(a[0]==1);
    ASSERT_TRUE(a[1]==3);

}
TEST(list_test, 4) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.erese(1);


    ASSERT_TRUE(a[0]==1);
    ASSERT_TRUE(a[1]==3);
}

TEST(list_test, 5) {
    List<int> a;
    a.push_back(1);
    a.insert(0,0);
    a.insert(2,4);

    ASSERT_TRUE(a[0]==0);
    ASSERT_TRUE(a[1]==1);
    ASSERT_TRUE(a[2]==4);

}
