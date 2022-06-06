int Xp = PLAYERX;
int Yp = PLAYERY;

void input()
{
	//wykrywa czy gracz wciska klawisz
	if (_kbhit())
	{
		//pobranie klawisza
		switch (_getch())
		{
		case 'w':
			Yp++;
			break;
		case 'a':
			Xp--;
			break;
		case 'd':
			Xp++;
			break;
		case 's':
			Yp--;
			break;
		}
	}
}