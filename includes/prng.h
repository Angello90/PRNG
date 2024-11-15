#ifndef _PRNG_H_
#define _PRNG_H_

#include <iostream>
#include <chrono>
#include <windows.h>
#include <string.h>
#include <sstream>

class PRNG {
public:
    PRNG();
    ~PRNG(){};
    uint64_t generate();
private:
    /*
    * seed: seed for the PRNG
    */
    uint64_t seed;
    /*
    * random_number: random number generated by the PRNG
    */
    uint64_t random_number;
    /*
    * generate_seed: generates a seed for the PRNG
    */
    uint64_t generate_seed();
};


#endif