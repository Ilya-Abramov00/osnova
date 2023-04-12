#include "complex.h"
using namespace std;
#include "signal.h"
#include <iostream>
#include <vector>

int main() {
vector<complex<float>> a={{1,2},{1,4}};
auto b= downsample(a,4);
cout<<b.at(0);

}
