#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class player
{
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
    float m_Speed;
    int m_maxHealth;
    float m_Attack;
    float m_Health;
public:
    player();
    Sprite getSprite();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    void update(float elapsedTime);
    int getXPosition();
    int getYPosition();
    float getHealth();
    int getmaxHealth();
    float getAttack();
    float getSpeed();
    int getxPosition();
    int getyPosition();
    void setMHealth(int sHealth);
    void setHealth(int sHealth);
    void setSpeed(int sHealth);
    void fight(float attack, float elapsedTime);
};

#endif // PLAYER_H
