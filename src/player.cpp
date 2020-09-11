#include "player.hpp"


player::player()
{
    m_Speed=300;
    m_Texture.loadFromFile("player.png");
    m_Sprite.setTexture(m_Texture);
    m_Position.x=600;
    m_Position.y=310;
    m_maxHealth=50;
    m_Health=50;
    m_Attack=2;
}

Sprite player::getSprite()
{
    return m_Sprite;
}

void player::setMHealth(int sHealth)
{
    if (sHealth==50)
    {
        m_Health=sHealth;
        m_maxHealth=sHealth;
    }
    else
    {
        m_Health=m_maxHealth+sHealth;
        m_maxHealth=m_maxHealth+sHealth;
    }
}

void player::setSpeed (int sHealth)
{
    m_Speed=m_Speed+sHealth;
}

void player::setAttack (int sHealth)
{
    m_Attack=m_Attack+sHealth;
}

void player::setHealth(int sHealth)
{
    if (m_Health+sHealth>=m_maxHealth)
        m_Health=m_maxHealth;
    else
        m_Health=m_Health+sHealth;
}

float player::getHealth()
{
    return m_Health;
}

int player::getmaxHealth()
{
    return m_maxHealth;
}

float player::getAttack()
{
    return m_Attack;
}

float player::getSpeed()
{
    return m_Speed;
}

int player::getXPosition()
{
    return m_Position.x;
}

int player::getYPosition()
{
    return m_Position.y;
}

void player::moveLeft()
{
    m_LeftPressed=true;
}

void player::moveRight()
{
    m_RightPressed=true;
}

void player::stopLeft()
{
    m_LeftPressed=false;
}

void player::stopRight()
{
    m_RightPressed=false;
}

void player::moveUp()
{
    m_UpPressed=true;
}

void player::moveDown()
{
    m_DownPressed=true;
}

void player::stopUp()
{
    m_UpPressed=false;
}

void player::stopDown()
{
    m_DownPressed=false;
}

void player::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x +=m_Speed*elapsedTime;
    }
    if (m_LeftPressed)
    {
        m_Position.x-=m_Speed*elapsedTime;
    }
    if (m_UpPressed)
    {
        m_Position.y -=m_Speed*elapsedTime;
    }
    if (m_DownPressed)
    {
        m_Position.y+=m_Speed*elapsedTime;
    }
    m_Sprite.setPosition(m_Position);
}

int player::getxPosition()
{
    return m_Position.x;
}

int player::getyPosition()
{
    return m_Position.y;
}

void player::fight(float attack, float elapsedTime)
{
    m_Health=m_Health-attack*elapsedTime;
}
