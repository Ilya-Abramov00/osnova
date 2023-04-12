#include <gtest/gtest.h>
#include "signal.h"
using namespace std;



TEST(signal_test, downsample)
{
vector<float>a={1,2,3,4};
    auto b=downsample(a,2);
    auto m=a.size();
    ASSERT_TRUE(m==2);
    ASSERT_TRUE(b.at(0)==1);
    ASSERT_TRUE(b.at(1)==3);
    }

TEST(signal_test, diff)
{
vector<float>a={1,2,3,4};
auto b=diff(a);
auto m=a.size();
ASSERT_TRUE(m==3);
ASSERT_TRUE(b.at(0)==1);
ASSERT_TRUE(b.at(1)==1);
ASSERT_TRUE(b.at(2)==1);
}
TEST(signal_test, RECfil)
{
vector<float>a={1,2,3,4};
auto b=Recursiv::filsr(a,2);
auto m=a.size();
ASSERT_TRUE(m==4);
ASSERT_TRUE(b.at(0)==1);
ASSERT_TRUE(b.at(1)==1.5);
ASSERT_TRUE(b.at(2)==2.5);
ASSERT_TRUE(b.at(3)==3.5);
}

TEST(signal_test, NORECfil)
{
vector<float>a={1,2,3,4};
auto b=Norecursiv::filsr(a,2);
auto m=a.size();
ASSERT_TRUE(m==4);
ASSERT_TRUE(b.at(0)==1);
ASSERT_TRUE(b.at(1)==1.5);
ASSERT_TRUE(b.at(2)==2.5);
ASSERT_TRUE(b.at(3)==3.5);
}
