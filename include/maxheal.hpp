#ifndef MAXHEAL_HPP
#define MAXHEAL_HPP
#include "pack.hpp"

using namespace sf;

class maxheal : public pack
{
private:

public:
    maxheal();
    Sprite getSprite();
    int addhp();
    int getxPosition();
    int getyPosition();
};

#endif // HEAL_HPP
