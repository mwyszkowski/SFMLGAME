#ifndef MAXHEAL_H
#define MAXHEAL_H
#include "pack.hpp"
#include <SFML/Graphics.hpp>
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

#endif // HEAL_H
