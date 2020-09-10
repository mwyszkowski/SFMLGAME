#ifndef HEAL_HPP
#define HEAL_HPP
#include "pack.hpp"

using namespace sf;

class heal : public pack
{
private:

public:
    heal();
    Sprite getSprite();
    int addhp();
    int getxPosition();
    int getyPosition();
};

#endif // HEAL_HPP
