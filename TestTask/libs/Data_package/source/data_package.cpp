#include "data_package/data_package.h"




int random_l(int N)
{
     std::uniform_int_distribution<> dist(1, 10*N );
     return dist(gen);
 }


 void geniration_string(int n, int N, std::string const & namefile)
{

        std::ofstream file;
	    file.open(namefile, std::ios::trunc);

	    if(!file.is_open()) {
		    throw FileException("файл не открылся");
	    }
        for (int i = 0; i != n; i++) { file << std::string(random_l(N), '*') << "\n"; }
	    file.close();

}