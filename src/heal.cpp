#include "heal.hpp"
#include <SFML/Graphics.hpp>
heal::heal()
{
    m_Position.x=(rand()%1070)+180;
    m_Position.y=rand()%690;
    m_Texture.loadFromFile("heal.png");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
    m_Add=15;
}


Sprite heal::getSprite()
{
    return m_Sprite;
}

int heal::addhp()
{
    return m_Add;
}

int heal::getxPosition()
{
    return m_Position.x;
}

int heal::getyPosition()
{
    return m_Position.y;
}
