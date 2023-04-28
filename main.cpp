
using namespace std;
#include "signal/signal.h"
#include <iostream>
#include <math.h>

#include <vector>

int main() {
    float fas=0;
    float A=1;
    float f=0.1;
    float fas1=fas*180/PI;
    float div=0.01;

    vector<float> sig(0,0);

    for (int k=0; k<=100; k++)
    {
        sig.emplace_back(sin(f*k+fas1));
    }
    auto m=sig.size();

    for (int i = 0; i <= m - 1; i++ ) {
        cout<<sig.at(i)<<" ";
    }

    for (int k=0; k<=100; k++)
    {
        sig.emplace_back(sin((sin(div*k)*f)*k+fas1));
    }

    return 1;
}
