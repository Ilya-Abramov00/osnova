
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
   auto c1=DemodulatorAM::demodul(c);
auto c2=normirovca(c1);

   FileManeger<float>::SaveSignal(ad1,c1);



    auto a=FileManeger<float>::SavedSignal(ud);


    auto a1=DemodulatorFM::demodul(a);


    auto a2=Recursiv::filsr(a1,8);


    auto a3= downsample(a2,25);


   FileManeger<float>::SaveSignal(ud1,a3);


    string ad3 = "/home/ilya/Загрузки/exampl";
AudioFile<float> audioFile;
    auto m=c2.size();
    audioFile.setSampleRate(16000);
    audioFile.setAudioBufferSize(1,m);

    audioFile.setBitDepth(16);
    audioFile.setNumChannels(1);
    for(int i=0;i<m;i++)
    {
        audioFile.samples[0][i]=(c2[i]);
    }
audioFile.save(ad3,AudioFileFormat::Wave);

}
