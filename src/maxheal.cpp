#include "maxheal.hpp"

maxheal::maxheal()
{
    m_Position.x=(rand()%1070)+180;
    m_Position.y=rand()%690;
    m_Texture.loadFromFile("maxheal.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
    m_Add=20;
}


Sprite maxheal::getSprite()
{
    return m_Sprite;
}

int maxheal::addhp()
{
    return m_Add;
}

int maxheal::getxPosition()
{
    return m_Position.x;
}

int maxheal::getyPosition()
{
    return m_Position.y;
}
