#include "gameManager.hpp"
#include <SFML/Graphics.hpp>
#include "heal.hpp"
#include "maxheal.hpp"
#include "speed.hpp"
#include <iomanip>
Event evencik;

gameManager::gameManager()
{
    Vector2f resolution;
    resolution.x=1280;
    resolution.y=720;
    m_Window.create(VideoMode(resolution.x, resolution.y), "Game");
    m_BackgroundTexture.loadFromFile("background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    font.loadFromFile("kidson.ttf");
    m_Hud.setFont(font);
    m_Hud.setString("");
    m_Hud.setCharacterSize(50);
    m_Hud.setFillColor(Color::White);
    sGO << "    GAME OVER" << endl << "Press enter to restart";
    m_GO.setFont(font);
    m_GO.setString(sGO.str());
    m_GO.setCharacterSize(150);
    m_GO.setFillColor(Color::White);
    m_GO.setPosition(350, 150);
}



void gameManager::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
    if (m_Player.getXPosition() < 180)
    {
        m_Player.stopLeft();
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Player.moveLeft();
    }

    else
    {
        m_Player.stopLeft();
    }
    if (m_Player.getXPosition()+50 > 1280)
    {
        m_Player.stopRight();
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Player.moveRight();
    }
    else
    {
        m_Player.stopRight();
    }

    if (m_Player.getYPosition() < 0)
    {
        m_Player.stopUp();
    }

    else if(Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Player.moveUp();
    }
    else
    {
        m_Player.stopUp();
    }

    if (m_Player.getYPosition()+50 > 720)
    {
        m_Player.stopDown();
    }

    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Player.moveDown();
    }
    else
    {
        m_Player.stopDown();
    }
}

void gameManager::update(float dtAsSeconds)
{
    m_Player.update(dtAsSeconds);
    for (int i=0; i<m_enemyAmount; i++)
    {
        m_Enemy[i]->update(dtAsSeconds);
    }
    hud();
}

void gameManager::draw()
{
    m_Window.clear(Color::White);
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Hud);
    m_Window.draw(m_Player.getSprite());
    for (int i=0; i<m_Pack.size(); i++)
    {
        m_Window.draw(m_Pack[i]->getSprite());
    }
    for (int i=0; i<m_enemyAmount; i++)
    {
        m_Window.draw(m_Enemy[i]->getSprite());
    }

    m_Window.display();
}

void gameManager::Generator()
{
    if (m_enemyAmount==0)
    {
        ++m_Round;
        if (m_Round < 4)
        {
            m_enemyAmount=m_Round+1;
        }
        else if (m_Round >=4 && m_Round<8)
        {
            m_enemyAmount=2*m_Round+1;
        }
        else
        {
            m_enemyAmount=3*m_Round+4;
        }
        for (int i=0; i<m_enemyAmount; i++)
        {
            m_Enemy.push_back (new enemy);
        }
    }

    if (m_Counter%5==0)
    {
        m_Pack.push_back (new heal);
        m_Counter=1;
    }

    if (m_Round%3!=0)
    {
        m_Speed=false;
    }

    if (m_Round%3==0 && m_Round!=0 && m_Speed==false)
    {
        m_Pack.push_back (new speed);
        m_Speed=true;
    }
    if (m_Round%5!=0)
    {
        m_Maxheal=false;
    }

    if (m_Round%5==0 && m_Round!=0 && m_Maxheal==false)
    {
        m_Pack.push_back (new maxheal);
        m_Maxheal=true;
    }
}



void gameManager::fight(float dtAsSeconds)
{
    for (int i=0; i<m_enemyAmount; i++)
    {
        if (m_Enemy[i]->getxPosition()>m_Player.getxPosition()-30 && m_Enemy[i]->getxPosition()<m_Player.getxPosition()+50
                && m_Enemy[i]->getyPosition()>m_Player.getyPosition()-30 && m_Enemy[i]->getyPosition()< m_Player.getyPosition()+50)
        {

            if (Keyboard::isKeyPressed(Keyboard::J) && Keyboard::isKeyPressed(Keyboard::K))
            {
                m_Enemy[i]->fight(m_Player.getAttack(), 2*dtAsSeconds);
                m_Player.fight(m_Enemy[i]->getAttack(), 1*dtAsSeconds);
            }
            if (Keyboard::isKeyPressed(Keyboard::J))
            {
                m_Enemy[i]->fight(m_Player.getAttack(), 4*dtAsSeconds);
                m_Player.fight(m_Enemy[i]->getAttack(), 4*dtAsSeconds);
            }

            else if (Keyboard::isKeyPressed(Keyboard::K))
            {
                m_Player.fight(m_Enemy[i]->getAttack(), 0.5*dtAsSeconds);
            }
            else
            {
                m_Player.fight(m_Enemy[i]->getAttack(), 4*dtAsSeconds);
            }


        }
    }

    for (int i=0; i<m_Pack.size(); i++)
    {
        if (m_Pack[i]->getxPosition()>m_Player.getxPosition()-30 && m_Pack[i]->getxPosition()<m_Player.getxPosition()+50
                && m_Pack[i]->getyPosition()>m_Player.getyPosition()-30 && m_Pack[i]->getyPosition()< m_Player.getyPosition()+50)
        {
            if (m_Pack[i]->addhp()==15)
                m_Player.setHealth(m_Pack[i]->addhp());
            else if (m_Pack[i]->addhp()==5)
            {
                if (m_Player.getSpeed()<350)
                    m_Player.setSpeed(m_Pack[i]->addhp());
            }
            else if (m_Pack[i]->addhp()==20)
                m_Player.setMHealth(m_Pack[i]->addhp());
            delete m_Pack[i];
            m_Pack.erase(m_Pack.begin()+i);
        }
    }


}

void gameManager::deleteenemy()
{
    for (int i=0; i<m_enemyAmount; i++)
    {
        if (m_Enemy[i]->getHealth()<=0)
        {
            delete m_Enemy[i];
            m_Enemy.erase(m_Enemy.begin()+i);
            m_enemyAmount--;
            m_Counter++;
        }
    }
}

void gameManager::hud()
{
    output.str("");
    output.clear();
    output << "Round: " << m_Round << endl << "Player: " << endl << "Health: " << setprecision(4) << m_Player.getHealth() << "/"
           << m_Player.getmaxHealth() << endl << "Attack: " << m_Player.getAttack() << endl
           << "Speed: " << m_Player.getSpeed()-299 << endl << "Enemy:" << endl << m_enemyAmount << " Remains" << endl
           << "Health: 4" << endl << "Attack: 2" << endl << "________" << endl << "Move: W S A D" << endl << "Attack: J" << endl << "Defense: K";
    m_Hud.setString(output.str());
}


void gameManager::start()
{
    Clock clock;
    while (m_Window.isOpen())
    {

        Time dt=clock.restart();
        float dtAsSeconds=dt.asSeconds();
        if (m_Player.getHealth()<=0)
        {
            for (int i=0; i<m_enemyAmount; i++)
            {
                delete m_Enemy[i];
                m_Enemy.erase(m_Enemy.begin()+i);
                --m_enemyAmount;
            }
            for (int i=0; i<m_Pack.size(); i++)
            {
                delete m_Pack[i];
                m_Pack.erase(m_Pack.begin()+i);
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }
            else if(Keyboard::isKeyPressed(Keyboard::Enter))
            {
                m_enemyAmount=0;
                m_Round=0;
                m_Player.setMHealth(50);
            }
            m_Window.clear(Color::White);
            m_Window.draw(m_BackgroundSprite);
            m_Window.draw(m_GO);
            m_Window.display();
        }
        else
        {
            Generator();
            input();
            fight(dtAsSeconds);
            deleteenemy();
            update(dtAsSeconds);
            draw();
        }
        while(m_Window.pollEvent(evencik))
        {
            float dtAsSeconds;
            if(evencik.type==Event::Closed)
            {
                m_Window.close();
            }
        }
    }
}
