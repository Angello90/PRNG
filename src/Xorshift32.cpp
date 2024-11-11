#include "Xorshift32.h"



Xorshift32::Xorshift32()
{
    // Création d'une seed
    generateSeed();
    std::cout << "Seed: " << _seed << std::endl;
}

void Xorshift32::generateSeed()
{
    POINT cursorPos; // position du curseur
    uint32_t seed = 0;
    GetCursorPos(&cursorPos);

    auto now = std::chrono::steady_clock::now().time_since_epoch();
    auto timeSeed = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count(); // temps en nanosecondes

    if (cursorPos.x == 0 || cursorPos.y == 0)
    {
        seed = uint32_t(timeSeed);
        // std::cout << "Seed: " << seed << std::endl;
    }
    else
    {
        seed = ((cursorPos.x * cursorPos.y));
        // std::cout << "Seed: " << seed << std::endl;
    }

    // std::cout << "Seed: " << seed << std::endl;
    this->_seed = seed;
}

uint32_t Xorshift32::next()
{
    _seed ^= _seed << 13;
    _seed ^= _seed >> 17;
    _seed ^= _seed << 5;
    return _seed;
}
