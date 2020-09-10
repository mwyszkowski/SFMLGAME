#ifndef SPEED_HPP
#define SPEED_HPP
#include "pack.hpp"

using namespace sf;

class speed : public pack
{
private:

public:
    speed();
    Sprite getSprite();
    int addhp();
    int getxPosition();
    int getyPosition();
};

#endif // HEAL_HPP
