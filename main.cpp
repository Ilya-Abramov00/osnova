
using namespace std;
#include "signal/signal.h"
#include <iostream>
#include <vector>

int main() {
    string ad = "/home/ilya/Загрузки/am_sound.dat";
    string ad1 = "/home/ilya/Загрузки/pere_am_sound.dat";

    string ud = "/home/ilya/Загрузки/file1EuropaPlus.bin";
    string ud1 = "/home/ilya/Загрузки/pere_file1EuropaPlus.bin";

    auto c=FileManeger<int>::SavedSignal(ad);
    auto c1=DemodulatorAM::demodul(c);


    FileManeger<float>::SaveSignal(ad1,c1);



    auto a=FileManeger<float>::SavedSignal(ud);


    auto a1=DemodulatorFM::demodul(a);


    auto a2=Recursiv::filsr(a1,8);


    auto a3= downsample(a2,25);


    FileManeger<float>::SaveSignal(ud1,a3);


}
