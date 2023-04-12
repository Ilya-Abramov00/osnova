#ifndef COMPLEX_H
#define COMPLEX_H

#include "complex.h"
#include <fstream>
#include <iostream>
#include <vector>


std::vector<complex<float>> downsample(std::vector<complex<float>> &vtr, unsigned int Fd);

std::vector<float> downsample(std::vector<float> &vtr, unsigned int Fd);


std::vector<float> diff(std::vector<float> &vec) ;


struct Filter {

    virtual std::vector<float> filsr1(std::vector<float> &c, int m) const = 0;

    virtual ~Filter() {}
};

struct Recursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m);
};

struct Norecursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m);
};
struct Demodulator {

    virtual std::vector<float> demodul1(std::vector<complex<float>> &sig) const = 0;

    virtual ~Demodulator() {}
};

struct DemodulatorAM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig);
};


struct DemodulatorFM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig);
};



template<class T> //в каком типе данных считывать

struct FileManeger {

    static std::vector<complex<float>> SavedSignal(std::string ad);
    void SaveSignal(std::string ad1, std::vector<complex<float>> c) {
        std::ofstream fout(ad1, std::ios_base::binary | std::ios_base::trunc);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else {
            int m = c.size();
            for (int i = 0; i != 2 * m; ++i) {
                float re;
                float im;
                if (i % 2 == 0) {
                    auto p = c.at(int(i / 2));
                    re = p.Re();
                    im = p.Im();
                    fout.write((char *) &re, sizeof(re));

                }
                if (i % 2 == 1) {
                    fout.write((char *) &im, sizeof(im));

                }

            }
        }
        fout.close();
        return;

    }

    static void SaveSignal(std::string ad1, std::vector<float> c) {
        std::ofstream fout(ad1, std::ios_base::binary | std::ios_base::trunc);
        if (!fout.is_open()) { std::cout << "Файл не может быть открыт\n"; }
        else {
            int m = c.size();
            for (int i = 0; i != m; ++i) {
                float sig = c.at(i);

                fout.write((char *) &sig, sizeof(sig));

            }
        }
        fout.close();
        return;

    }
};







#endif
