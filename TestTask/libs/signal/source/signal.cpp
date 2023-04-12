#include "signal.h"
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
        x.emplace_back(vtr.at(i));
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

 std::vector<float> Recursiv:: filsr(std::vector<float> &c, int m)
{
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

std::vector<float> Norecursiv::filsr(std::vector<float> &c, int m){

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
};


std::vector<float> DemodulatorAM::demodul(std::vector<complex<float>> &sig) {
    size_t m = sig.size();
    std::vector<float> demo(0, 0);
    demo.reserve(m);

    for (int i = 0; i != m; i++) {

        demo.emplace_back(sig.at(i).Abs());
    }
    return demo;
}




    std::vector<float>  DemodulatorFM ::demodul(std::vector<complex<float>> &sig) {
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





