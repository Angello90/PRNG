#ifndef _XORTSHIFT32_H_
#define _XORTSHIFT32_H_

#include <iostream>
#include <chrono>
#include <windows.h>
#include <string.h>
#include <sstream>

class Xorshift32
{
public:
    Xorshift32();
    Xorshift32(uint32_t seed){_seed = seed;};
    ~Xorshift32(){};

    uint32_t next();
    void setSeed(uint32_t seed){_seed = seed;};

private:
    uint32_t _seed;
    void generateSeed();
};

#endif // _XORTSHIFT32_H_