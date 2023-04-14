
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


   // FileManeger<float>::SaveSignal(ad1,c1);



    //auto a=FileManeger<float>::SavedSignal(ud);


    //auto a1=DemodulatorFM::demodul(a);


    //auto a2=Recursiv::filsr(a1,8);


   // auto a3= downsample(a2,25);


   // FileManeger<float>::SaveSignal(ud1,a3);






    string ad3 = "/home/ilya/Загрузки/example.wav";
    ofstream f( ad3, ios::binary );
    // Write the file headers
    f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
    write_word( f,     16, 4 );  // no extension data
    write_word( f,      1, 2 );  // PCM - integer samples
    write_word( f,      1, 2);  // two channels (stereo file)
    write_word( f,  16000, 4 );  // samples per second (Hz)
    write_word( f, 32000, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
    write_word( f,      2, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
    write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)

    // Write the data chunk header
    size_t data_chunk_pos = f.tellp();
    f << "data----";  // (chunk size to be filled in later)


    int m = c1.size();
    for (int i = 0; i !=m; ++i)
    {

        write_word(f, int(c1.at(i)), 2);


    }

    // (We'll need the final file size to fix the chunk sizes above)
    size_t file_length = f.tellp();

    // Fix the data chunk header to contain the data size
    f.seekp( data_chunk_pos + 4 );
    write_word( f, file_length - data_chunk_pos + 8 );

    // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
    f.seekp( 0 + 4 );
    write_word( f, file_length - 8, 4 );






}
