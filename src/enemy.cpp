#include "enemy.h"

enemy::enemy()
{
    xpos=(rand()%1070)+180;
    ypos=rand()%690;
    if (rand()%2==0)
        lor=true;
    else
        lor=false;
    if (rand()%2==0)
        m_Xory=true;
    else
        m_Xory=false;
    m_enemySpeed=350;
    m_enemyTexture.loadFromFile("enemy.png");
    m_enemySprite.setTexture(m_enemyTexture);
    m_enemyPosition.x=xpos;
    m_enemyPosition.y=ypos;
    m_enemyHealth=4;
    m_enemyAttack=2;
}

Sprite enemy::getSprite()
{
    return m_enemySprite;
}

void enemy::update(float elapsedTime)
{

    if (m_Xory==true)
    {
        if(m_enemyPosition.x>xpos-80 && lor==false && m_enemyPosition.x>=180)
        {
            --m_enemyPosition.x;
        }
        else
            lor=true;
        if(m_enemyPosition.x<xpos+80 && lor==true && m_enemyPosition.x<=1250)
        {
            ++m_enemyPosition.x;
        }
        else
            lor=false;
    }
    else
    {
        if(m_enemyPosition.y>ypos-80 && lor==false && m_enemyPosition.y>=0)
        {
            --m_enemyPosition.y;
        }
        else
            lor=true;
        if(m_enemyPosition.y<ypos+80 && lor==true && m_enemyPosition.y<=690)
        {
            ++m_enemyPosition.y;
        }
        else
            lor=false;
    }
    m_enemySprite.setPosition(m_enemyPosition);
}

void enemy::fight(float attack, float elapsedTime)
{
    m_enemyHealth=m_enemyHealth-attack*elapsedTime;
}

float enemy::getHealth()
{
    return m_enemyHealth;
}

int enemy::getxPosition()
{
    return m_enemyPosition.x;
}

int enemy::getyPosition()
{
    return m_enemyPosition.y;
}

float enemy::getAttack()
{
    return m_enemyAttack;
}
