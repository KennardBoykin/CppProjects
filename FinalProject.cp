
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib> //for rand
#include <ctime>
#include <Windows.h> //for Sleep

using namespace std;
HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
enum Colors
{
	Blue = 9, Green = 10, Red = 12, Purple = 13, Yellow = 14, White = 7, LightBlue = 11, Grey = 8,
};
enum CharacteTypes { GWizard = 1, GKnight, GWarrior };
enum MaxTypes
{
	HealthWizard = 20, MagicWizard = 30,            //wizard
	HealthKnight = 30, MagicKnight = 22,            //knight
	HealthWarrior = 25, MagicWarrior = 26,          //warrior
};


//functions
long timeTest(); // for the player attack
void startUp(int& a, int& health, int& magic, int& Count); //when the game startups
string characterFunc(int a, int& Health, int& Magic); // sets up player magic and health 
void missionFunc(int a); //red screen 
int EnemyDecide(int a);  //decides the enemy's health which increases over the number of rounds
int EnemyAttack(int& a); // the enemy randomly decides an attack choice
void fightFunc(int& eneHealth, int choice, int& health, int& magic, int max); //player attack
void Damage(int a, int& playerhealth); //depending on enemy attack choice, random number generator will decide to attack or not

									   //main*********
int main()
{
	int playCount = 1;
	bool playagain = true;
	while (playagain)
	{
		bool game = true, answer = true;
		int characterPick = 0, MaxHealth = 0, MaxMagic = 0, EneRound = 1;
		int PlayerHealth = 0, PlayerMagic = 0;
		string a;
		startUp(characterPick, MaxHealth, MaxMagic, playCount);
		system("cls");
		missionFunc(characterPick);
		int startUpTime = time(0);
		system("cls");
		cout << "Here are your beginning stats...\n\nHealth: " << MaxHealth << "  Magic: " << MaxMagic / 2 << endl;
		PlayerHealth = MaxHealth, PlayerMagic = (MaxMagic / 2);

		while (game)//  game loop after character is selected
		{
			int enemyHealth = EnemyDecide(EneRound);
			int AttackChoice, EnemyAttackChoice;
			//system("cls");

			while (true) // battle loop until player or enemy dies
			{
				AttackChoice = 0;
				while (answer)
				{
					Sleep(1000);

					SetConsoleTextAttribute(output, Purple);        //after the player and the computer move, it reprints this each time
					cout << "\nEnemy Number: " << EneRound << endl;
					if (EneRound == 50)
					{
						cout << "YOU HAVE REACHED VEXOR!!" << endl;
					}
					SetConsoleTextAttribute(output, White);
					cout << "\nThe enemy's health is: " << enemyHealth << endl;
					cout << "Your health is: " << PlayerHealth << endl;
					cout << "You have " << PlayerMagic << " magic orbs left" << endl;
					cout << "\nWhat would you like to do? Select the number.." << endl;
					SetConsoleTextAttribute(output, LightBlue);
					cout << "\n1: HEAVY ATTACK    2: MEDIUM ATTACK    3: LIGHT ATTACK    4: HEAL" << endl;
					SetConsoleTextAttribute(output, White);
					string decider;
					cin >> decider; //get the players decision

					if (decider == "1")//heavy
					{
						cout << "\nYOU CHOSE HEAVY!" << endl; AttackChoice = 1;
						answer = false; //jumps out of the loop once one of the decisions is met
					}
					else if (decider == "2")//medium
					{
						cout << "\nYOU CHOSE MEDIUM!" << endl; AttackChoice = 2;
						answer = false;
					}
					else if (decider == "3") // light
					{
						cout << "\nYOU CHOSE LIGHT!" << endl; AttackChoice = 3;
						answer = false;
					}
					else if (decider == "4") //HEAL
					{
						cout << "\nYOU CHOSE TO HEAL!" << endl; AttackChoice = 4;
						answer = false;
					}
					else // default decider error 
					{
						system("cls");
						SetConsoleTextAttribute(output, 4);
						cout << "Error.... Make sure to select the number only\n\n";
					}
				}    //****answer while****


					 //after players decision
				EnemyAttackChoice = EnemyAttack(EnemyAttackChoice);
				// if the enemy choose a lower or equal attack than the player then the player goes first
				// if the player heals, the player will always go second
				if (EnemyAttackChoice <= AttackChoice && AttackChoice != 4)
				{
					cout << "\nYour move goes first!" << endl;

					fightFunc(enemyHealth, AttackChoice, PlayerHealth, PlayerMagic, MaxHealth);
					if (enemyHealth > 0)
						Damage(EnemyAttackChoice, PlayerHealth); // opponents turn


				}
				else //enemy goes first
				{
					cout << "\nThe enemy's move goes first!" << endl;
					Damage(EnemyAttackChoice, PlayerHealth);
					if (PlayerHealth > 0)
						fightFunc(enemyHealth, AttackChoice, PlayerHealth, PlayerMagic, MaxHealth);

				}
				answer = true; //re-established the answer loop to keep the battle going 

				if (EneRound == 50 && enemyHealth <= 0) //Vexor dies, player wins the game
				{
					SetConsoleTextAttribute(output, LightBlue);
					cout << "\nYOU HAVE SAVED THE UNIVERSE!!" << endl;
					cout << "CONGRATULATIONS!!" << endl;
					game = false;
					break;
				}
				if (enemyHealth <= 0 && PlayerHealth > 0)
				{
					EneRound++; //increase players stats
					PlayerHealth++;
					MaxHealth++;
					PlayerMagic++;
					MaxMagic++;
					if (EneRound >= 10)
					{
					 //increase players stats
						PlayerHealth += 4;
						MaxHealth += 4;
						PlayerMagic += 4;
						MaxMagic += 4;
					}
					if (EneRound >= 25)
					{
					 //increase players stats
						PlayerHealth+=9;
						MaxHealth+=9;
						PlayerMagic+=9;
						MaxMagic+=9;
					}
					SetConsoleTextAttribute(output, Yellow);
					cout << "VICTORY!" << endl;
					Sleep(1000);
					cout << "A new enemy is approaching..." << endl;
					Sleep(2000);
					system("cls");
					break;
				}
				if (PlayerHealth <= 0) // if the enemy hits you and you die
				{
					SetConsoleTextAttribute(output, Red);
					cout << "\nDefeat.. You Died" << endl;

					cout << "You made it to enemy number " << EneRound << "...VEXOR still lives on.." << endl;

					game = false;
					break;
				}

				// if the players health is low, it will show a warning
				if (PlayerHealth <= 4 && PlayerHealth > 0)
				{
					SetConsoleTextAttribute(output, 4);
					cout << "Warning....your health is getting low! " << endl;
				}

			}// battle loop
		}
		//game over screen
		int EndTime = time(0);

		cout << "\nYou've played for " << EndTime - startUpTime << " seconds!" << endl;
		SetConsoleTextAttribute(output, LightBlue);
		string startover;
		cout << "\n\nWould you like to play again?  Y/N" << endl;

		cin >> startover;
		if (startover == "Y" || startover == "y" || startover == "yes" || startover == "Yes")
		{
			playCount++;
			playagain = true;
			system("cls");
		}
		else
			playagain = false;
	} //play again loop



	system("Pause");
	return 0;
}





void startUp(int& a, int& health, int& magic, int& Count)
{
	string character;
	SetConsoleTextAttribute(output, LightBlue);
	cout << "			*************************" << endl;
	cout << "			~~~ Galactic  Warrior ~~~" << endl;
	cout << "			*************************" << endl;

	cout << "\n                Your only mission... is to save the universe...\n\n" << endl;
	cout << "                        ";system("Pause");
	system("cls");

	while (true)
	{
		while (true)
		{
			SetConsoleTextAttribute(output, White);
			cout << "	Character 1:		Character 2:		 Character 3:" << endl;
			SetConsoleTextAttribute(output, LightBlue);
			cout << "	  Wizard		  Knight		   Warrior " << endl;
			SetConsoleTextAttribute(output, White);
			cout << "\n       Max Health: 20          Max Health: 30           Max Health: 25 " << endl;
			cout << "       Max Magic : 30          Max Magic : 22           Max Magic : 26 " << endl;
			string characterSelect;
			cout << "\n\n Pick the character you wish to use by selecting the number...\n\n" << endl;
			getline(cin, characterSelect);

			if (characterSelect == "1" || characterSelect == "wizard" || characterSelect == "Wizard")
			{
				a = GWizard; break;
			}
			else if (characterSelect == "2" || characterSelect == "knight" || characterSelect == "Knight")
			{
				a = GKnight; break;
			}
			else if (characterSelect == "3" || characterSelect == "warrior" || characterSelect == "Warrior")
			{
				a = GWarrior; break;
			}
			else
			{
				system("cls");
				SetConsoleTextAttribute(output, 4);
				if (Count < 1)
					cout << "Error.... Make sure to pick the number or type the character correctly\n\n";
			}
		} //character pick while
		cout << "\nYou chose to fight as the " << characterFunc(a, health, magic) << "!" << endl;
		cout << "\n\nAre you sure you want to fight as this character?  Y/N" << endl;
		string choice;
		getline(cin, choice);
		if (choice == "yes" || choice == "Yes" || choice == "Y" || choice == "y")
			break;
		else
			system("cls");
	}// are you sure? while

}


//-1 mean they were not successful
//any other positive time means that they were successful
long timeTest()
{
	//seed the random number generator
	srand(time(0));
	//rand will give a number between 0 and max integer value
	int waitTime = rand() % 5 + 1;
	for (int i = waitTime; i>0;i--)
	{
		cout << "*";
		Sleep(1000);//This is the windows specific line, for mac/linux it is usleep(1000)
	}
	char typeThis = rand() % 26 + 97; //these are the ascii values that will possibly be output by this function
	cout << typeThis << ":" << endl;
	string Letter = "";
	Letter += typeThis;
	string playerResponse; //store player response here, this could be changed to a string if you want multiple characters

						   //Gets a time
	auto startTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());

	cin >> playerResponse; //get the player input (it waits for the enter key)

						   //gets another time
	auto endTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());

	//checks if the character was right
	if (playerResponse != Letter)
		return 1000000;
	auto delta = endTime - startTime; //gets the difference in 
	return delta.count(); //returns the difference in time as a long long
}

string characterFunc(int a, int& Health, int& Magic)
{
	switch (a)
	{
	case 1:
		Health = HealthWizard;
		Magic = MagicWizard;
		return "Wizard";
	case 2:
		Health = HealthKnight;
		Magic = MagicKnight;
		return "Knight";
	case 3:
		Health = HealthWarrior;
		Magic = MagicWarrior;
		return "Warrior";
	}
}

void missionFunc(int a)
{
	//explains the mission to the player and final boss Vexor
	string chara;
	switch (a)
	{
	case 1:
		chara = "wizard";
		break;
	case 2:
		chara = "knight";
		break;
	case 3:
		chara = "warrior";
		break;
	}
	COORD top; top.X = 0; top.Y = 6; //tells the for loop where to start scrolling
	SetConsoleTextAttribute(output, Red);
	cout << "\n\n\n\n\n\nAs a " << chara << ", your job is to fight numerous galactic enemies in order to reach.. \n..VEXOR..   " << endl;
	Sleep(4000);
	SetConsoleCursorPosition(output, top);
	for (int i = 0; i < 200; i++)
	{
		cout << " "; Sleep(30);
	} //scrolls across the screen
	system("cls");
	SetConsoleTextAttribute(output, White);
}

//FIGHTING FUNCTIONS
//for the round the player is one decides the difficulty of the enemy
int EnemyDecide(int a)
{
	srand(time(0));
	int eneHealth = 10 + (rand() % a) + (2 * a);
	return eneHealth;
}

int EnemyAttack(int& a)
{
	srand(time(0));
	int t = rand() % 3 + 1;
	switch (t)
	{
	case 1:

		cout << "\nENEMY ATTACK CHOICE: HEAVY" << endl;
		return a = 1;
	case 2:
		cout << "\nENEMY ATTACK CHOICE: MEDIUM" << endl;
		return a = 2;
	case 3:
		cout << "\nENEMY ATTACK CHOICE: LIGHT" << endl;
		return a = 3;
	}
}

void fightFunc(int &eneHealth, int choice, int& health, int& magic, int max)
{
	int Attempt = 0, dmg;
	cout << endl;
	switch (choice)
	{
	case 1: //heavy     
		if (0 < (timeTest() <= 1000))
		{
			cout << "Hit!" << endl;
			dmg = 4 + (rand() % 4 + 1);
			eneHealth -= dmg;
			SetConsoleTextAttribute(output, Green);
			cout << "\nYOU DELT " << dmg << " DAMAGE TO THE ENEMY!" << endl;
			SetConsoleTextAttribute(output, White);
		}
		else
			cout << "Miss!" << endl;
		break;
	case 2:  //medium
		if (timeTest() < 1500)
		{
			cout << "Hit!" << endl;
			dmg = 2 + (rand() % 3 + 1);
			eneHealth -= dmg;
			SetConsoleTextAttribute(output, Green);
			cout << "\nYOU DELT " << dmg << " DAMAGE TO THE ENEMY!" << endl;
			SetConsoleTextAttribute(output, White);
		}
		else
			cout << "Miss!" << endl;
		break;
	case 3:  //light
		if (timeTest() < 2000)
		{
			cout << "Hit!" << endl;
			dmg = (rand() % 3 + 1);
			eneHealth -= dmg;
			SetConsoleTextAttribute(output, Green);
			cout << "\nYOU DELT " << dmg << " DAMAGE TO THE ENEMY!" << endl;
			SetConsoleTextAttribute(output, White);
		}
		else
			cout << "Miss!" << endl;
		break;
	case 4: //heal
		int k;
		if (magic >= 4 && health != max)
		{
			magic -= 4;
			if ((max - health) < 5)
			{
				k = max - health;
				health += k;
			}
			else
				k = 3 + (rand() % 3);
			health += k;
			SetConsoleTextAttribute(output, Green);
			cout << "YOU HEALED WITH " << k << " LIFE POINTS!" << endl;
			SetConsoleTextAttribute(output, White);
		}
		else
		{
			SetConsoleTextAttribute(output, Red);
			cout << "YOU CAN NOT HEAL!" << endl;
			SetConsoleTextAttribute(output, White);
		}
		break;
	}
}

void Damage(int a, int& playerhealth)
{
	int per;
	int dmg;
	per = rand() % 10 + 1;
	Sleep(2000);
	switch (a)
	{
	case 1: //heavy
		if (per <= 3)
		{
			dmg = 4 + (rand() % 4 + 1);
			playerhealth -= dmg;
			SetConsoleTextAttribute(output, Red);
			cout << "\nOPPONENT HIT!\n" << endl;
			cout << "\nYOU LOST " << dmg << " HEALTH" << endl;
			SetConsoleTextAttribute(output, White);

		}
		else
		{
			SetConsoleTextAttribute(output, Green);
			cout << "\nOPPONENT MISS!\n" << endl;
			SetConsoleTextAttribute(output, White);
		}

		return;
	case 2: //medium
		if (per <= 5)
		{
			dmg = 2 + (rand() % 4 + 1);
			playerhealth -= dmg;
			SetConsoleTextAttribute(output, Red);
			cout << "\nOPPONENT HIT!\n" << endl;
			cout << "\nYOU LOST " << dmg << " HEALTH" << endl;
			SetConsoleTextAttribute(output, White);

		}
		else
		{
			SetConsoleTextAttribute(output, Green);
			cout << "\nOPPONENT MISS!\n" << endl;
			SetConsoleTextAttribute(output, White);
		}
		return;
	case 3: //light
		if (per <= 7)
		{
			dmg = (rand() % 3 + 1);
			playerhealth -= dmg;
			SetConsoleTextAttribute(output, Red);
			cout << "\nOPPONENT HIT!\n" << endl;
			cout << "\nYOU LOST " << dmg << " HEALTH" << endl;
			SetConsoleTextAttribute(output, White);


		}
		else
		{
			SetConsoleTextAttribute(output, Green);
			cout << "\nOPPONENT MISS!\n" << endl;
			SetConsoleTextAttribute(output, White);
		}
		return;
	}
}