#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameManager.h"
#include "player.h"
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
    srand(time(0));
    gameManager engine;
    engine.start();
    return 0;
}
