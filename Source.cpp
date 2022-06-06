#include <iostream>
#include <windows.h>
#include <string>
#include <array>
#include <string.h>
#include <conio.h>

using namespace std;
#include "Config.h"
#include "Graphic.h"
#include "Logic.h"
#include "Input.h"


int main()
{
	Setup();
	while (!gameOver)
	{
		//Draw();
		Input();
		cout << endl;
	}
	return 0;
}