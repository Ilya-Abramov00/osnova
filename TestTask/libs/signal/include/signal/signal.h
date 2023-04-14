#ifndef SIGNAL_H
#define SIGNAL_H

#include "complex/complex.h"
#include <fstream>
#include <iostream>
#include <vector>


std::vector<complex<float>> downsample(std::vector<complex<float>> &vtr, unsigned int Fd);

std::vector<float> downsample(std::vector<float> &vtr, unsigned int Fd);


std::vector<float> diff(std::vector<float> &vec) ;


struct Filter {

    virtual ~Filter() {}
};

struct Recursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m);
};

struct Norecursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m);
};

struct Demodulator {

    virtual ~Demodulator() {}
};

struct DemodulatorAM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig);
};


struct DemodulatorFM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig);
};




template <class T> //в каком типе данных считывать
struct FileManeger{

    static std::vector<complex<float>>  SavedSignal(std::string ad)
    {
        static std::vector<complex<float>> c;
        std::ifstream fin;
        fin.open(ad, std::ios_base::binary | std::ios_base::in);
        if (!fin.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else {
            int a = 0;
            int i = 0;

            float RE, IM;
            while (fin.read((char *) &a, sizeof(T))) {

                if (i % 2 == 0) { RE = float(a); }
                if (i % 2 != 0) {
                    IM = float(a);
                    c.push_back(complex<float>(RE, IM));
                }
                i++;

            }
            std::cout << "Файл открыт\n";
            fin.close();

        }
        return c;
    }

    void SaveSignal(std::string ad1, std::vector<complex<float>> c){
        std::ofstream fout(ad1, std::ios_base::binary | std::ios_base::trunc);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else {
            int m = c.size();
            for (int i = 0; i !=2*m; ++i)
            {
                float re;
                float im;
                if (i % 2 == 0)
                {
                    auto p = c.at(int(i/2));
                    re = p.Re();
                    im = p.Im();
                    fout.write((char *) &re, sizeof(re));

                }
                if ( i%2 ==1){
                    fout.write((char *) &im, sizeof(im));

                }


            }
        }
        fout.close();
        return;

    }

    static void SaveSignal(std::string ad1, std::vector<float> c){
        std::ofstream fout(ad1, std::ios_base::binary | std::ios_base::trunc);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else {
            int m = c.size();
            for (int i = 0; i !=m; ++i)
            {
                float sig=c.at(i);

                fout.write((char *) &sig, sizeof(sig));

            }
        }
        fout.close();
        return;

    }
};

namespace little_endian_io
{
    template <typename Word>
    std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
    {
        for (; size; --size, value >>= 8)
            outs.put( static_cast <char> (value & 0xFF) );
        return outs;
    }
}
using namespace little_endian_io;

 std::vector<float> normirovca(std::vector<float>& v);



#endif
