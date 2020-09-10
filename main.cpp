#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameManager.hpp"
#include "player.hpp"
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
