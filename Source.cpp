#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

#include "Config.h"
#include "Setup.h"
#include "PlayerClass.h"
#include "WallClass.h"

int main()
{
    float P_x = PLAYER_X;
    float P_y = PLAYER_Y;
    float W_x = WINDOW_X / 100;
    float W_y = WINDOW_X / 2;
    Player player(P_x, P_y);
    Wall wall(W_x, W_y);

    RenderWindow window{ VideoMode{WINDOW_X,WINDOW_Y},"Game" };
    window.setFramerateLimit(FRAMERATE);
    Event event;

    while (!gameOver)
    {
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == Event::Closed)
        {
            window.close();
            break;
        }

        player.update();

        window.draw(wall);
        window.draw(player);
        window.display();
    }

    return 0;
}