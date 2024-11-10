#include "prng.h"


PRNG::PRNG()
{
    seed = generate_seed();
    std::cout << "Seed: " << seed << std::endl;
}

uint64_t PRNG::generate_seed()
{
    POINT cursorPos;
    uint64_t seed_ = 0;
    GetCursorPos(&cursorPos);

    auto now = std::chrono::steady_clock::now().time_since_epoch();
    auto timeSeed = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();

    if (cursorPos.x == 0 || cursorPos.y == 0)
        seed_ = timeSeed;
    else
        seed_ = ((cursorPos.x * cursorPos.y) >> 8) & (timeSeed >> 8);

    for (int i = 0; i < 8; i++)
    {
        seed_ <<= 4;
        seed_ += uint64_t(rand() % 256);
        seed >>= 4;
        seed_ ^= seed;
    }
    return seed_;
}

uint64_t  PRNG::generate()
{
    seed ^= seed << 21;
    seed ^= seed >> 35;
    seed ^= seed << 4;
    seed ^= 2685821657736338717LL;
    seed <<= 4;

    std::stringstream ss;
    ss << seed;

    for(int i = 0; i < ss.str().length(); i++)
    {
        ss.str()[i] = (ss.str()[i] & ss.str()[i + 1]) ^ ss.str()[i + 1];
        seed ^= ss.str()[i];
    }

    seed /= 0xFFD8FF;
    seed >>= 4;
    seed *= seed << 21;
    seed *= 0xFFD8FF;
    
    random_number = seed;
    return random_number;
}