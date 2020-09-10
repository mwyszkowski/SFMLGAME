#ifndef SPEED_H
#define SPEED_H
#include "pack.hpp"
#include <SFML/Graphics.hpp>
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

#endif // HEAL_H
