

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <chrono>

int main()
{

    std::queue <char> ad;
    std::ifstream fin;
    fin.open("/home/ilya/zad2.txt",  std::ios_base::in);
    std::thread qw;
    if (!fin.is_open()) { std::cout << "Файл не может быть открыт\n"; }
    else {
        char a;
        char &b=a;
        while (fin.get(a) )
        {
            ad.push(a);
            std::cout<<a;
std::this_thread::sleep_for(std::chrono::microseconds(200));
        }
        std::cout<<ad.size();
        std::cout << "Файл открыт\n";
        fin.close();
    }

    return 1;
}
