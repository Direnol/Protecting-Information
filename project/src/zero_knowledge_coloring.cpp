//
// Created by direnol on 26.11.18.
//

#include <ZeroColoring.h>
#include <fstream>

int main()
{
    std::ifstream in("../graph.txt");
    std::cout << "File open: " << std::boolalpha << in.is_open() << std::noboolalpha << std::endl;
    ZeroColoring zl(in);
    zl.print();
    std::cout << "Start zero" << std::endl;
    zl.zero_v();
    std::cout << std::boolalpha << zl.zero_g() << std::endl;
    return 0;
}