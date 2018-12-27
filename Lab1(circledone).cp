#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Loop Structures:" << endl;
	cout << "----------------" << endl;
	//1
	/*Original:*/
	cout << "Original #1: ";
	for (int i = 6; i < 10; i++)
		cout << i << " ";
	cout << endl;
	// my loop
	cout << "Loop 1a : ";
	int s = 6;
	while (s < 10)
	{
		cout << s << " ";
		s++;
	}
	// my loop
	cout << "\n";
	cout << "Loop 1b : ";
	int k = 6;
	do {
		cout << k << " ";
		k++;

	} while (k < 10);
	cout << "\n" << endl;
	// 2
	// Original: 
	cout << "Original #2: ";
	  int w = 35;
	while (--w>0)
	{
	if (w > 5)
	w -= 4;
	cout << "T-" << w << ", ";
	}
	cout << "Lift-off" << endl;
	// my loop
	cout << "Loop 2 : ";
	for (int x = 35; --x > 0;)
	{
		if (x > 5)
			x -= 4;
		cout << "T-" << x << ", ";
	}
	cout << "Lift-off";

	cout << "\n" << endl;

	// 3
	//Original:
	cout << "Original #3: ";
	  int loop = 10;
	do{
	cout << --loop << " ";
	} while (loop > 5);
	cout << endl;
	// my loop
	cout << "Loop 3 : ";
	int oop = 10;
	while (oop > 5)
		cout << --oop << " ";
	cout << "\n" << endl;

	// 4
	// Original:
	cout << "Original #4: ";
	int j = 17;
	for (int i = 0; i<j;)
	{
	cout << i << " ";
	if (j-- % ++i == 0)
	i += j / 2;
	}
	cout << endl;
	// my loop
	cout << "Loop 4 : ";
	int p = 17;
	int q = 0;
	while (q < p)
	{
		cout << q << " ";
		if (p-- % ++q == 0)
			q += p / 2;
	}

	// Part 2 
	// Multiplication 
	cout << endl << "\n\n\n";
	cout << "Multiplication Table: " << endl;
	cout << "----------------------" << endl;
	cout << endl;
	int o = 1;
	cout << "MULTI:";
	while (o < 13) {
		cout << setw(4) << o << " ";
		o++;
	}
	cout << endl;
	cout << "...................................................................." << endl;
	for (int y = 1; y < 13; y++)
	{
		cout << endl;
		cout << setw(4) << y << "| ";
		
		for (int l = 1; l < 13; l++) 
			cout << setw(4) << 
			(y*l) << " ";

			
	}
	cout << endl;
	cout << " \n" << endl;

	// Diamond Shape (fun)

	cout << "My Diamond: " << endl;
	cout << "-----------" << endl;
	// top
	int v, b;
	for (b = 10; b >= 0; b--)
	{
		cout << endl;
		for (v = 10; v > (10 - b); v--)
			cout << "* ";
		for (v = 0; v < (10 - b); v++)
			cout << "  ";
		for (v = 9; v > b - 1; v--)
			cout << "  ";
		for (v = 0; v < b; v++)
			cout << "* ";
	}

	//bottom
	int f, g;
	for (g = 0; g <= 10; g++)
	{
		cout << endl;
		for (f = 0; f > ( -g) ; f--)
			cout << "* ";
		for (f = 10; f > g; f--)
			cout << "  ";
		for (f = 0; f < 10-g; f++)
			cout << "  ";
		for (f = 0; f < g ; f++)
			cout << "* ";

	}

	cout << "\n\n" << endl;
	//My attempt at a cirle
	cout << "Circle" << endl;
	cout << "------" << endl;

	int rad = 13; // works when  7 <= rad <= 19

	for (int x = 0; x <= rad*2 ;x++) //rows
	{
		for (int y = 0; y <= rad*2; y++) 
		{
			float length = sqrt(pow((x - rad), 2) + pow((y - rad), 2));
			if (length - .15 >= rad && rad <= length + .15)
			{
				cout << "  " ;
				
			}
			else
				cout << setw(1.3) << "* " ; //larger circle
		} // looks  kind of like an oval
		cout << endl; // new line
	}


	cout << endl;
	system("Pause");
	return 0;
}