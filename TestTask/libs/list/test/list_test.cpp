#include <gtest/gtest.h>
#include "list/list.h"

TEST(list_test, 1) {
    List<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==2);
    ASSERT_TRUE(a.getAt(2)->data==2);
}

TEST(list_test, 2) {
    List<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(2);

    ASSERT_TRUE(a.getAt(0)->data==2);
    ASSERT_TRUE(a.getAt(1)->data==1);
    ASSERT_TRUE(a.getAt(2)->data==2);
}

TEST(list_test, 3) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.pop_back();
    a.push_back(3);

    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==3);

}
TEST(list_test, 4) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.erese(1);


    ASSERT_TRUE(a.getAt(0)->data==1);
    ASSERT_TRUE(a.getAt(1)->data==3);
}

TEST(list_test, 5) {
    List<int> a;
    a.push_back(1);
    a.insert(0,0);
    a.insert(2,4);

    ASSERT_TRUE(a.getAt(0)->data==0);
    ASSERT_TRUE(a.getAt(1)->data==1);
    ASSERT_TRUE(a.getAt(2)->data==4);

}
