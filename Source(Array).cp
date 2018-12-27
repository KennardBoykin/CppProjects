#include <iostream>
#include <cmath> 

using namespace std;

//Create a function call sumArray which will return the sum of an array that is passed in.
//Note that a length of the array should also be specified.
//input: arr = { 1, 2, 3, 4 }, length = 3
//returns : 6 (because the 4 was ignored because it was past the length)

int sumArray(int arr[], int a)
{
	int sum = 0;
	for (int i = 0; i < a; i++)
		sum += arr[i];
	return sum;
}

//Create a function call convertToDecimal.
//This method will take an int array { 3, 2, 4 } and a length of the array, 
//and will return a single integer where each part of the array is a digit in the 
//new integer(324).

int convertToDecimal(int arr[], int a, int base =10)
{
	int u = a; int temp = 0;
	for (int i = 0; i < u; i++, a--)
		temp += pow(base, a - 1) * arr[i];
	return temp;
}

//Write a function printAccending, that will take an int array and the length as its 
//input and output each integer on a line that is greater than the last.
//If one is smaller it will drop to a new line and continue from there 


void printAccending(int arr[], int a)
{
	for (int i = 0; i < a; i++)
	{
		if (arr[i] < arr[i + 1])
			cout << arr[i] << " ";
		else
			cout << arr[i] << "\n";
	}
}


//Write a function reverseArrayEven which will loop through a 
//given array(with a size provided as well), and will reverse the digits 
//if they are even numbers.
//input: {1, 2, 4, 5, 6, 9, 10}
//returns: {10, 9, 4, 5, 6, 2, 1}

void reverseArrayEven(int arr[], int a)
{
	int temp;
	for (int i = 0; i < a/2; i++)
	{
		if (((arr[i] % 2) != 0 )&& (arr[a - i - 1] % 2 == 0))
		{
			//cout <<"BEFORE(odd)  "  << arr[i] << " " << arr[a - i - 1] << endl;
			temp = arr[i];
			arr[i] = arr[a - i - 1];
			arr[a - i - 1] = temp;
			//cout << arr[i] << " " << arr[a - i - 1] << endl;
			continue;
		}
		if (((arr[i] % 2) == 0) && (arr[a - i - 1] % 2 != 0))
		{
			//cout << "BEFORE(even)  " << arr[i] << " " << arr[a - i - 1] << endl;
			temp = arr[i];
			arr[i] = arr[a - i - 1];
			arr[a - i - 1] = temp;
			//cout << arr[i] << " " << arr[a - i - 1] << endl;
		}

	}
	return;
}

//Write a function to search a 2 - dimentional array for a value.
//The method should take a reference to a row and col integer, 
//and if the value is found then set the row and col variables accordingly.
//If the value is not found row and col should both equal - 1. 
//Note that lengths of the array should also be taken as input.
//input: { {1, 2, 3}, { 4,5,6 }, { 7,8,9 }}, 
//inputRow = 3, inputCol = 3, foundRow&, foundCol&, searchValue = 6
//after function completes : foundRow = 1, foundCol = 2


void Search2DArray(int arr[][3],int& foundRow, int& foundCol, int value,int inputRow = 3, int inputCol = 3)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//cout << i << j << ": Row and Column  are here" << endl;
			if ((arr[i][j]) == value)
			{
				foundRow = i;
				foundCol = j;
				//cout << "FOund " << i << " " << j;
				return;
			}	
			if (i == 2 && j == 2 && (arr[i][j]) != value)
			{
				foundRow = -1;
				foundCol = -1;
				return;
			}
		}
	}
}


int main()
{
	//int TestArr1[5] = { 2, 10, 10, 4, 5 };		
	//cout << sumArray(TestArr1, 5) << endl;


	//cout << "\n" <<endl;


	//int TestArr2[3] = { 1,0,1 };
	//cout << convertToDecimal(TestArr2,3, 10 ) << endl;


	//cout << "\n" <<endl;


	//int TestArr[1] = { 4};
	//printAccending(TestArr, 1);
	

	//cout << "\n" <<endl;


	/*int TestArr4[7] = { 1, 2, 4, 5, 6, 9, 10 };
	for (int i = 0; i < 7; i++)
		cout << TestArr4[i] << " ";
	reverseArrayEven(TestArr4, 7);
	cout << "\nAfter  ";
	for (int i = 0; i < 7; i++)
	cout << TestArr4[i] << " ";*/


	//cout << "\n" <<endl;


	//int testArr[3][3] = {
	//{ 1,2,3},
	//{ 4,5,6},
	//{ 7,8,9}};

	//int Row = 0; int Col = 0;
	//Search2DArray(testArr, Row, Col, 7, 3, 3);
	//cout << "Row: " << Row << "\nColumn: " << Col << endl;

	system("Pause");
	return 0;
}