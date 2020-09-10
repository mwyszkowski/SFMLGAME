#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"
#include "enemy.h"
#include "pack.h"
#include "heal.h"
#include "maxheal.h"
#include "speed.h"
#include <vector>
#include <sstream>
#include <iomanip>
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

#endif // GAMEMANAGER_H
