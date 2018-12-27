
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

int algebra(int d, int e, int f)
{
	int t;
	if (f == 12 && d == 3)
		f -= 1;
	else if (f == 12 && d == 4)
		f -= 3;
	else if (f == 6 && d == 2)
		f += 1;
	else if (f == 6 && d == 3)
		f += 1;
	cout << f << " = " << d << "x - " << e << endl;
	cout << "x =  ";
	t = (f + e) / d;

	return t;
}

int first;
int second;
int correct;
int answer;
int incorrect1 = 0, correct1 = 0, incorrect2 = 0, correct2 = 0, bonusCorr = 0, bonusInc = 0; // each level
int incorrectCount = 0, correctCount = 0; // total correct
long startTime0 = time(0);
int main()
{
	cout << "**********************************************" << endl;
	cout << "Welcome to the best \"Math Game\" on the planet!" << endl;
	cout << "**********************************************" << endl;
	cout << "\n";

	// instructions
	cout << "Instructions: " << endl;
	cout << "I'll give you random math problems. \nTry to answer each one correctly. \nYou will have a certain amount of time to answer them." << endl;
	cout << "\n" << endl;
	cout << "Difficulty will only affect the amount of time you have in each level!" << endl;
	cout << endl;
	// play again here -------- 


	char player = 'y';
	
	while (player == 'y' || player == 'Y')
	{
		//set difficulty
		int difficulty;


		cout << "\nHow difficult would you like it? " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "0) : Extremely Easy : 180 seconds "
			<< " \n1) : Easy : 90 seconds"
			<< " \n2) : Medium : 60 seconds"
			<< " \n3) : Hard : 45 seconds"
			<< " \n4) : Extremely Hard : 30 seconds" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "~Enter the number~" << endl;
		cin >> difficulty;
		switch (difficulty)
		{
		case 180:
		case 0:
			difficulty = 180;
			break;
		case 90:
		case 1:
			difficulty = 90;
			break;
		case 60:
		case 2:
			difficulty = 60;
			break;
		case 45:
		case 3:
			difficulty = 45;
			break;
		case 30:
		case 4:
			difficulty = 5;  //test change
			break;
		}

		cout << "\nYOU WILL HAVE " << difficulty << " SECONDS TO DO AS MANY PROBLEMS AS POSSIBLE!" << endl;
		// should have a system pause after instructions
		// gives the user time to get ready
		cout << "\nLevel 1 : Addition only." << endl;
		cout << "Level 2 : Four basic Operations" << endl;
		cout << "Bonus Round: Top Secret. " << endl;

		cout << "\n\nContinue when you are ready!" << endl;
		system("Pause");
		//after they are ready the game begins here




		// randomly get the numbers and operation
		srand(time(0));
		cout << endl;
		// all levels inside while(game)
		int timeLeft = 0;
		int timeLeft2 = 0;
		int timeLeft3 = 0;
		int startTime = time(0);

		cout << "~Level 1~\n" << endl;
		cout << "Addition Only!" << endl;
		bool level1 = true;
		while (timeLeft >= 0 && level1)
		{

			for (int i = 0, l = 4, u = 10; i < 7; i++, correct == answer ? l += 9, u += 9 : l += 5)
			{
				first = (rand() % u) + 1;
				second = (rand() % l) + 1;
				if (second % 2)
					second *= -1;
				correct = first + second;
				cout << first << " + " << second << " =  ";
				cin >> answer;
				if (correct == answer)
				{
					cout << "Correct! Keep Going!" << endl;
					correctCount += 1;
					correct1++;
				}
				else if (answer == correct - 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;		//Show correct answers to each wrong answer
					incorrectCount += 1;
					incorrect1++;											// Add percentage for right answers
				}															// Get (total correct / total questions ) x 100
				else if (answer == correct + 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;
					incorrectCount += 1;
					incorrect1++;
				}
				else
				{
					cout << "Try Again." << "                        Answer: " << correct << endl;
					incorrectCount += 1;
					incorrect1++;
				}
				//timer
				long endTime = time(0);
				timeLeft = difficulty - (endTime - startTime);
				cout << timeLeft << " seconds left!" << endl;
				cout << endl;
				if (timeLeft < 0)
				{
					level1 = false;
					break;
				}
			}
		} // end "time..left1" while loop
		if (timeLeft < 0)
		{
			if (answer == correct)
			{
				cout << "You answered one correctly but after time expired." << endl;
				correctCount--;
				correct1--;
			}
			else
			{
				cout << "You answered a question incorrectly but after time expired." << endl;
				incorrectCount--;
				incorrect1--;
			}
		}
		cout << "\n****************" << endl;
		cout << "Level 1 Score: " << endl;
		cout << "****************" << endl;
		cout << "Correct: " << correct1 << endl;
		cout << "Incorrect: " << incorrect1 << endl;
		cout << "\n\nContinue on to Level 2!\n" << endl;
		system("Pause");
		// Level 2 start 
		long startTime2 = time(0);
		cout << "\n~Level 2~\n" << endl;
		cout << "Basic Operations\n" << endl;
		bool level2 = true;
		while (timeLeft2 >= 0 && level2)
		{
			for (int u = 0, y = 4; u < 4; u++, correct == answer ? y += 10 : y += 2)
			{
				int operation = rand() % 400 + 1;
				first = rand() % 30 + 1;
				second = rand() % y + 1;
				operation %= 4;
				// switch for operators
				switch (operation)
				{
				case 0:
					first = rand() % 12 + 1;
					second = rand() % 12 + 1;
					correct = first * second;
					cout << first << " * " << second << " =  ";
					cin >> answer;
					break;
				case 1:
					correct = first + second;
					cout << first << " + " << second << " =  ";
					cin >> answer;
					break;
				case 2:
					correct = first - second;
					cout << first << " - " << second << " =  ";
					cin >> answer;
					break;
				case 3:
					first = rand() % 15 + 1; // to get simple division
					second = (first * (rand() % 15 + 1));
					correct = second / first;
					cout << second << " / " << first << " =  ";
					cin >> answer;
					break;
				} // end operation switch
				if (correct == answer)
				{
					cout << "Correct! Keep Going!" << endl;
					correctCount += 1;
					correct2++;
				}
				else if (answer == correct - 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;
					incorrectCount += 1;
					incorrect2++;
				}
				else if (answer == correct + 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;
					incorrectCount += 1;
					incorrect2++;
				}
				else
				{
					cout << "Try Again." << "                             Answer: " << correct << endl;
					incorrectCount += 1;
					incorrect2++;
				}
				// timer
				long endTime = time(0);
				timeLeft2 = difficulty - (endTime - startTime2);
				cout << timeLeft2 << " seconds left!" << endl;
				cout << endl;
				if (timeLeft2 < 0)
				{
					level2 = false;
					break;
				}
			} // end of for loop

		} // end of timeLeft2 loop

		if (timeLeft2 < 0)
		{
			if (answer == correct)
			{
				cout << "You answered one correctly but after time expired." << endl;
				correctCount--;
				correct2--;
			}
			else
			{
				cout << "You answered a question incorrectly but after time expired." << endl;
				incorrect2--;
				incorrectCount--;
			}
		}
		cout << "\n***************" << endl;
		cout << "Level 2 Score: " << endl;
		cout << "***************" << endl;
		cout << "Correct: " << correct2 << endl;
		cout << "Incorrect: " << incorrect2 << endl;
		// Level 2 end

		////bonus start
		long startTime3 = time(0);
		cout << "\n~Bonus~\n" << endl;
		bool bonuslvl = true;
		while (timeLeft3 >= 0 && bonuslvl)
		{
			for (int u = 0, y = 4; u < 4; u++, correct == answer ? y += 10 : y += 2) //same for loop from previous level with more operations
			{
				int operation = rand() % 777 + 1;
				first = rand() % 30 + 1;
				second = rand() % y + 1;
				operation %= 6;
				// switch for operators
				switch (operation)
				{
				case 0:
					// multiplication
					first = rand() % 12 + 1;
					second = rand() % 12 + 1;
					correct = first * second;
					cout << first << " * " << second << " =  ";
					cin >> answer;
					break;
				case 1:
					//addition
					first -= 10;
					correct = first + second;
					cout << first << " + " << second << " =  ";
					cin >> answer;
					break;
				case 2:
					//subrtraction
					first *= 2;
					second -= 5;
					correct = first - second;
					cout << first << " - " << second << " =  ";
					cin >> answer;
					break;
				case 3:
					// harder division
					first = rand() % 25 + 1; // to get simple division
					second = (first * (rand() % 14 + 1));
					correct = second / first;
					cout << second << " / " << first << " =  ";
					cin >> answer;
					break;
				case 4:
					//simple modulus
					first = rand() % 20 + 1;
					second = rand() % y + 1;
					correct = first % second;
					cout << first << " % " << second << " =  ";
					cin >> answer;
					break;
				case 5:
					//algebra
					first = rand() % 3 + 1;
					second = rand() % 4 + 1;
					int third = first * second;
					correct = algebra(first, second, third);
					cin >> answer;
					break;
				} // end operation switch
				  // check
				if (correct == answer)
				{
					cout << "Correct! Keep Going!" << endl;
					correctCount += 1;
					bonusCorr++;
				}
				else if (answer == correct - 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;
					incorrectCount += 1;
					bonusInc++;
				}
				else if (answer == correct + 1)
				{
					cout << "So close! Try Again!" << "                   Answer: " << correct << endl;
					incorrectCount += 1;
					bonusInc++;
				}
				else
				{
					cout << "Try Again." << "                             Answer: " << correct << endl;
					incorrectCount += 1;
					bonusInc++;
				}
				long endTime = time(0);
				timeLeft3 = difficulty - (endTime - startTime3);
				cout << timeLeft3 << " seconds left!" << endl;
				cout << endl;
				if (timeLeft3 < 0)
				{
					bonuslvl = false;
					break;

				}
				if (timeLeft3 < 0)
				{
					if (answer == correct)
					{
						cout << "You answered one correctly but after time expired." << endl;
						correctCount--;
						bonusCorr--;
					}
					else
					{
						cout << "You answered a question incorrectly but after time expired." << endl;
						incorrect2--;
						bonusInc--;
					}
				}

			} //for end
		} //bonus end


			string lvl1 = "Level 1 ";
			string lvl2 = " Level 2 ";
			string bonus = " Bonus Round";
			//comment a out for bonus
			int a = 1;
			// score card
			cout << "\n---------------------------------------" << endl;
			cout << "               ~Score~" << endl;
			cout << "---------------------------------------" << endl;
			cout << setw(10) << " " << lvl1 << lvl2 << setw(5) << bonus << endl;
			cout << "***************************************" << endl;								// change bonus time
			cout << "Correct: " << setw(5) << correct1 << setw(10) << correct2 << setw(9) << " " << bonusCorr << endl;
			cout << "Incorrect:" << setw(4) << incorrect1 << setw(10) << incorrect2 << setw(9) << " " << bonusInc << endl;

			cout << "\nTotal Number Correct : " << correctCount << endl;			//Totals
			cout << "Total Number Incorrect : " << incorrectCount << endl;

			int sum = correctCount + incorrectCount;
			int perc = (correctCount * 100) / sum;
			cout << "Percentage : " << perc << "%" << endl;				//percentage correct
			cout << "\n\n" << endl;

			cout << "\nWould you like to play again? Y / N  ";
			cin >> player;
			
		} // end game loop

		  //Total Timer
		cout << endl;
		long endTime = time(0);
		cout << "You've played for " << endTime - startTime0 << " seconds!" << endl;
		cout << endl;
		// Total Timer

		system("Pause");
		return 0;
	}

	

