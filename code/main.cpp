#include "player.h"
#include "Engine.h"
#include "enemy.h"
#include <SFML/Graphics.hpp>

int main()
{
    //Create engine object and use run function
    Player player;
    Engine engine;
    engine.run();
    return 0;
}