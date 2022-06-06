#include <iostream>
#include <windows.h>
#include <string>
#include <array>
#include <string.h>
#include <conio.h>

using namespace std;
#include "Config.h"
#include "Map.h"
#include "Logic.h"
#include "Input.h"


int main()
{
	setup();
	while (!gameOver)
	{
		graphic();
		input();
		cout << endl;
	}
	return 0;
}