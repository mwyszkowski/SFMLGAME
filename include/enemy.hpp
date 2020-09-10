#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
using namespace sf;

class enemy
{
private:
    Vector2f m_enemyPosition;
    Sprite m_enemySprite;
    Texture m_enemyTexture;
    float m_enemySpeed;
    float m_enemyAttack;
    float m_enemyHealth;
    bool m_Xory;
    int xpos;
    int ypos;
    int lor;
public:
    enemy();
    Sprite getSprite();
    float getHealth();
    void fight(float attack, float elapsedTime);
    void update(float elapsedTime);
    int getxPosition();
    int getyPosition();
    float getAttack();

};

#endif // ENEMY_H
