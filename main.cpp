#include <iostream>
#include "Xorshift32.h"


Xorshift32 p;

int main(int, char**){
    std::cout << "Random: " << p.next() << std::endl;
    return EXIT_SUCCESS;
}
