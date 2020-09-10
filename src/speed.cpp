#include "speed.hpp"
#include <SFML/Graphics.hpp>
speed::speed()
{
    m_Position.x=(rand()%1070)+180;
    m_Position.y=rand()%690;
    m_Texture.loadFromFile("speed.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
    m_Add=5;
}


Sprite speed::getSprite()
{
    return m_Sprite;
}

int speed::addhp()
{
    return m_Add;
}

int speed::getxPosition()
{
    return m_Position.x;
}

int speed::getyPosition()
{
    return m_Position.y;
}
