
using namespace std;
#include "TestTask/libs/signal/include/signal/signal.h"
#include <iostream>
#include <vector>

int main() {
vector<complex<float>> a={{1,2},{1,4}};
auto b= downsample(a,4);
cout<<b.at(0);

}
