#ifndef ATTACK_HPP
#define ATTACK_HPP
#include "pack.hpp"

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

#endif // HEAL_HPP
