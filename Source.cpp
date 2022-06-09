#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

#include "Config.h"
#include "Setup.h"
#include "PlayerClass.h"
#include "WallClass.h"
#include"Block.h"

int main()
{
    float P_x = PLAYER_X;
    float P_y = PLAYER_Y;
    float W_x = WINDOW_X / 100;
    float W_y = WINDOW_Y / 2;
    Player player(P_x, P_y);
    Wall wall(W_x, W_y);
   

    RenderWindow window{ VideoMode{WINDOW_X,WINDOW_Y},"Game" };
    window.setFramerateLimit(FRAMERATE);
    Event event;
	/*template<class T1, class T2.bool isIntersecting(T!&a, T2& b)
	{

	}*/
	
    unsigned blockX{ 8 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 70 };

    vector<Block> blocks;
	for (int i = 0; i < WINDOW_Y; i++)
	{
		if (WINDOW_Y==1 || WINDOW_Y==1000)
		{
			for (int j = 0; j < WINDOW_X; j++)
			{
				blocks.emplace_back(j + 1)* (blockWidth), (j + 2)* (blockHeight), blockWidth, blockHeight;

			}
		}
		for (int i = 0; i < WINDOW_X ;i++)
		{
			if (WINDOW_X==1|| WINDOW_X==1000)
			{
				blocks.emplace_back(i + 1)* (blockHeight), (i + 2)* (blockWidth), blockWidth, blockHeight;
			}
		}
	}
	
	/*cout << endl;
	for (int i = 0; i < WINDOW_X ; i++)
	{
		if (i == OPPONENT_HEIGHT1)
		{
			for (int j = 0; j < WINDOW_Y; j++)
			{
				if (j == 0 || j == WINDOW_Y - 1 || j == OPPONENT_WIDTH2 || j == OPPONENT_WIDTH3)
				{
					cout << WALL;
				}
				else if (j == OPPONENT_WIDTH1)
				{
					cout << OPPONENT;
				}
				else
				{
					cout << SPACE;
				}
			}
		}
		else if (i == OPPONENT_HEIGHT2)
		{
			for (int j = 0; j < WINDOW_Y; j++)
			{
				if (j == 0 || j == WINDOW_Y - 1 || j == OPPONENT_WIDTH1 || j == OPPONENT_WIDTH3)
				{
					cout << WALL;
				}
				else if (j == OPPONENT_WIDTH2)
				{
					cout << OPPONENT;
				}
				else
				{
					cout << SPACE;
				}
			}
		}
		else if (i == OPPONENT_HEIGHT3)
		{
			for (int j = 0; j < WINDOW_Y; j++)
			{
				if (j == 0 || j == WINDOW_Y - 1 || j == OPPONENT_WIDTH1 || j == OPPONENT_WIDTH2)
				{
					cout << WALL;
				}
				else if (j == OPPONENT_WIDTH3)
				{
					cout << OPPONENT;
				}
				else
				{
					cout << SPACE;
				}
			}
		}
		else
		{
			for (int j = 0; j < WINDOW_Y; j++)
			{
				if (j == 0 || j == WINDOW_X - 1 || j == OPPONENT_WIDTH1 || j == OPPONENT_WIDTH2 || j == OPPONENT_WIDTH3)
				{
					cout << WALL;
				}
				else
				{
					cout << SPACE;
				}
			}
		}

		cout << endl;
	}
	for (int i = 0; i < WINDOW_X; i++)
	{
		cout << WALL;
	}*/


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
        for (int i = 0; i < WINDOW_X; i++)
        {
            window.draw(wall);
            W_x+=100;
            W_y+=100;

        }
        //window.draw(wall);
        window.draw(player);
		for (auto& block : blocks)
			window.draw(block);

		
        window.display();
    }

    return 0;
}