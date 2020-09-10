#ifndef HEAL_H
#define HEAL_H
#include "pack.h"
#include <SFML/Graphics.hpp>
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

#endif // HEAL_H
