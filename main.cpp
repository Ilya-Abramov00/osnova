
using namespace std;
#include "signal/signal.h"
#include <iostream>
#include "AudioFile.h"
#include <vector>

int main() {
    string ad = "/home/ilya/Загрузки/am_sound.dat";
    string ad1 = "/home/ilya/Загрузки/pere_am_sound.dat";

    string ud = "/home/ilya/Загрузки/file1EuropaPlus.bin";
    string ud1 = "/home/ilya/Загрузки/pere_file1EuropaPlus.bin";

    auto c=FileManeger<int>::SavedSignal(ad);
   // auto c1=DemodulatorAM::demodul(c);


   //FileManeger<float>::SaveSignal(ad1,c1);



    auto a=FileManeger<float>::SavedSignal(ud);


    auto a1=DemodulatorFM::demodul(a);


    auto a2=Recursiv::filsr(a1,8);


    auto c1= downsample(a2,25);


   //FileManeger<float>::SaveSignal(ud1,a3);


    string ad3 = "/home/ilya/Загрузки/exampl";
AudioFile<float> audioFile;
    audioFile.setSampleRate(20000);
    audioFile.setAudioBufferSize(1,c1.size());
    audioFile.setBitDepth(32);
    audioFile.setNumChannels(1);
    for(int i=0;i<c1.size();i++)
    {
        audioFile.samples[0][i]=float(c1[i]);
    }
audioFile.save(ad3,AudioFileFormat::Wave);

}
