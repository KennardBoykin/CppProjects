#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;



HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

COORD back, platform;
void Background()
{
	srand(time(0));
	//platforms
		platform.X = (rand() % 35) + 11;
		platform.Y = 10 + (rand() % 13);

		SetConsoleCursorPosition(output, platform);
		int j = 0;
		while (j < 10)
		{
			j++;
			cout << '#';
		}



	//grass
	SetConsoleTextAttribute(output, 10);
	back.Y = 24;
	back.X = 0;
	SetConsoleCursorPosition(output, back);
	int i = 0;
	while (i < 80)
	{
		i++;
		cout << ((char)240);
	}

}

void Gravity();
bool HitDetect(short a, short b, short c, short d);

COORD Enemy;
void Enemys()
{
	// enemy one
	static int RIGHT_SIDE = 79;
	srand(time(0));
	int height;
	height = 3 + rand() % 15;
	Enemy.X = RIGHT_SIDE;
	Enemy.Y = height;
	if (Enemy.Y == platform.Y)
	{
		Enemy.Y -= 1;
	}
	SetConsoleCursorPosition(output, Enemy);
	cout << ((char)174)<< ((char)182);
	RIGHT_SIDE--;
	if ((RIGHT_SIDE - 1) == 0)
	{
		RIGHT_SIDE = 79;
	}
	Enemy.X += 2;
	SetConsoleCursorPosition(output, Enemy);
	cout << " ";

	Sleep(50);
	//blanks
	Enemy.X -= 1;
	SetConsoleCursorPosition(output, Enemy);
	cout << " ";
	Enemy.X -= 1;
	SetConsoleCursorPosition(output, Enemy);
	cout << " ";
	
	Enemy.X += 2;
}

COORD PlayerPos;
void handleKeys()
{
	
	if (GetAsyncKeyState(VK_RIGHT))
	{
		PlayerPos.X += 1;
	}
	if (GetAsyncKeyState(VK_LEFT) && PlayerPos.X > 0)
	{
		PlayerPos.X -= 1;
	}
	if (GetAsyncKeyState(VK_DOWN) && PlayerPos.Y < 23)
	{
		PlayerPos.Y += 1;
	}
	if (GetAsyncKeyState(VK_UP) && PlayerPos.Y> 1)
	{
		PlayerPos.Y -= 3;
			
	}
	
	Gravity();
}

bool PlatformCheck();

int main()
{
	
	Background();
	int StartTime = time(0);

	while (true)
	{
	
		
	
		//player
		SetConsoleCursorPosition(output, PlayerPos);
		cout << "  ";
		handleKeys();
		
		SetConsoleTextAttribute(output, 5);
		SetConsoleCursorPosition(output, PlayerPos);
		cout << ((char)206);

		//ENEMY
		SetConsoleTextAttribute(output, 6);
		cout << " ";
		Enemys();
		

		//if ((HitDetect(Enemy.Y, PlayerPos.Y, Enemy.X, PlayerPos.X)));
				//break;

		Sleep(5);
	}
	//system("cls");
	cout << "\nGAME OVER\n";

	system("Pause");
	return 0;
}


void Gravity()
{
	const int gravity = -1;
	//enable player on gravity for y direction
	
	if (PlayerPos.Y < 23 && !(PlatformCheck()))
		PlayerPos.Y -= gravity;
	else
		PlayerPos.Y += 0;

	
}

bool PlatformCheck()
{
			//platform									//left side					//right side
	if (PlayerPos.Y  == platform.Y -1 && PlayerPos.X >= platform.X-1 && PlayerPos.X <= platform.X + 10)
		return true;
	else
		return false;

}
		//	   enemy-y, player-y, enemy-x ,player-x		
bool HitDetect(short a, short b, short c, short d)
{
	if (a == b && c == d)
		return true;
	else
		return false;
}
