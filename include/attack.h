#ifndef ATTACK_H
#define ATTACK_H
#include "pack.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class attack : public pack
{
private:

public:
    attack();
    Sprite getSprite();
    int addhp();
    int getxPosition();
    int getyPosition();
};

#endif // HEAL_H
