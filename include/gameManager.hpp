#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include "player.hpp"
#include "enemy.hpp"
#include "pack.hpp"
#include <sstream>
using namespace sf;
using namespace std;

class gameManager
{
private:
    RenderWindow  m_Window;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    vector <enemy*> m_Enemy;
    vector <pack*> m_Pack;
    Font font;
    void input();
    void update(float dtAsSeconds);
    void draw();
    int m_enemyAmount=0;
    int m_Round=0;
    int m_Counter=1;
    bool m_Speed=false;
    bool m_Maxheal=false;
    player m_Player;
    Text m_Hud;
    std::ostringstream output;
    std::ostringstream sGO;
    Text m_GO;

public:

    void hudupdate(float elapsedTime);
    gameManager();
    void start();
    void deleteenemy();
    void Generator();
    void fight(float elapsedTime);
    void hud();
    void soundonoff();


protected:
};

#endif // GAMEMANAGER_HPP
