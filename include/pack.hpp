#ifndef PACK_HPP
#define PACK_HPP
#include <SFML/Graphics.hpp>
using namespace sf;

class pack
{
protected:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    int m_Add;
public:
    virtual Sprite getSprite()=0;
    virtual int addhp()=0;
    virtual int getxPosition()=0;
    virtual int getyPosition()=0;


};

#endif // PACK_HPP
