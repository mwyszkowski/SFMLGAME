#include "attack.hpp"

attack::attack()
{
    m_Position.x=(rand()%1070)+180;
    m_Position.y=rand()%690;
    m_Texture.loadFromFile("attack.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
    m_Add=5;
}


Sprite attack::getSprite()
{
    return m_Sprite;
}

int attack::addhp()
{
    return m_Add;
}

int attack::getxPosition()
{
    return m_Position.x;
}

int attack::getyPosition()
{
    return m_Position.y;
}
