#include <iostream>
#include "prng.h"


PRNG p;

int main(int, char**){
    uint64_t r[10];

    for (int i = 0; i < 10; i++)
    {
        r[i] = p.generate();
        std::cout << i;
        std::cout << ": ";
        std::cout << r[i] << std::endl;
    }

    // std::cout << "Seed: " << p.generate() << std::endl;
    return EXIT_SUCCESS;
}
