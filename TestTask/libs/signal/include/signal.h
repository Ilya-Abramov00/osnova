#ifndef COMPLEX_H
#define COMPLEX_H

#include "complex.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<complex<float>> downsample(std::vector<complex<float>> &vtr, unsigned int Fd) {
    auto m = vtr.size();

    std::vector<complex<float>> x(0, 0);
    x.reserve(m);
    for (int i = 0; i <= m - 1; i = i + Fd) {
        x.push_back(vtr.at(i));
    }
    return x;
}

std::vector<float> downsample(std::vector<float> &vtr, unsigned int Fd) {
    auto m = vtr.size();

    std::vector<float> x(0, 0);
    x.reserve(m);
    for (int i = 0; i <= m - 1; i = i + Fd) {
        x.emplace_back(vtr.at(i));
    }
    return x;
}


std::vector<float> diff(std::vector<float> &vec) {
    auto m = vec.size();
    std::vector<float> d(0, 0);
    d.reserve(m + 1);
    for (int i = 1; i != m; i++) {
        auto p = vec.at(i) - vec.at(i - 1);
        d.push_back(p);
    }
    return d;
}


struct Filter {

    virtual std::vector<float> filsr1(std::vector<float> &c, int m) const = 0;

    virtual ~Filter() {}
};

struct Recursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m) {
        size_t N = c.size();
        std::vector<float> rez(0, 0);
        rez.reserve(m);
        for (int i = 0; i != N; ++i) {
            if (i < m) {
                if (i == 0) { rez.push_back(c.at(0) / m); }
                else { rez.emplace_back(rez.at(i - 1) + c.at(i) / m); }

            }
            if (i >= m) {
                rez.emplace_back(rez.at(i - 1) + (c.at(i) - c.at(i - m)) / m);
            }
        }
        return rez;
    }
};

struct norecursiv : Filter {
    static std::vector<float> filsr(std::vector<float> &c, int m) {
        size_t N = c.size();
        std::vector<float> rez(0, 0);
        rez.reserve(N);
        --m;
        float y = 0;
        for (int n = 0; n != N; ++n) {
            y = 0;
            for (int i = 0; i <= m; ++i) {
                if (i <= n) {
                    float q = c.at(n - i);
                    y = y + q;
                }
            }
            y = y / (m + 1);
            rez.push_back(y);
        }
        return rez;
    }
};

struct Demodulator {

    virtual std::vector<float> demodul1(std::vector<complex<float>> &sig) const = 0;

    virtual ~Demodulator() {}
};

struct DemodulatorAM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig) {
        size_t m = sig.size();
        std::vector<float> demo(0, 0);
        demo.reserve(m);

        for (int i = 0; i != m; i++) {

            demo.emplace_back(sig.at(i).Abs());
        }
        return demo;
    }

};

struct DemodulatorFM : Demodulator {
    static std::vector<float> demodul(std::vector<complex<float>> &sig) {
        size_t m = sig.size();
        std::vector<float> im(0, 0);
        im.reserve(m);
        std::vector<float> re(0, 0);
        re.reserve(m);
        std::vector<float> abs(0, 0);
        abs.reserve(m);
        for (int i = 0; i != sig.size(); ++i) {
            re.emplace_back(sig.at(i).Re());
            im.emplace_back(sig.at(i).Im());
            {
                if (sig.at(i).Abs2() != 0) { abs.emplace_back(sig.at(i).Abs2()); }
                else { abs.push_back(0.001); }

            }
        }

        auto red = diff(re);
        red.push_back(0);

        auto imd = diff(im);
        imd.push_back(0);

        std::vector<float> sigINF(0, 0);
        sig.reserve(m);

        for (int i = 0; i != sig.size(); ++i) {
            sigINF.emplace_back((imd.at(i) * re.at(i) - red.at(i) * im.at(i)) / abs.at(i));
        }

        return sigINF;


    }
};

template<class T> //в каком типе данных считывать
struct FileManeger {

    static std::vector<complex<float>> SavedSignal(std::string ad) {
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
                    c.push_back( complex<float>(RE, IM));
                }
                i++;

            }
            std::cout << "Файл открыт\n";
            fin.close();

        }
        return c;
    }

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





/*vector<float> normirovca(vector<float>& v)
{
    cout<<"2";
    float max = 1;
    cout<<max;
    auto m=v.size();
    vector<float> sig(0,0);
    sig.reserve(m);
    for (int i = 0; i != m; ++i)
    {
        sig.push_back(sig.at(i) / max);
    }
    return sig;
}
*/

#endif
