#include <iostream>
#include <windows.h>
#include <string>
#include <array>
#include <string.h>
#include <conio.h>

using namespace std;
#include "Graphic.h"
#include "Logic.h"
#include "Input.h"
#include "Config.h"


int main()
{
	//
	Setup();
	while (!gameOver)
	{
		Draw();
		//	Input(s);
			//Logic();
		cout << endl;
	}
	return 0;
}