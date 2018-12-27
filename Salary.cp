
#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>

using namespace std;

//global variables


enum employeeTypes

{
	F1 = 1,
	F2,
	F3,
	F4
};

ifstream file;

int employeeFinder(string lineofStuff)
{
	//last character
	//cout << lineofStuff[lineofStuff.length() - 1] << endl;
	int i = lineofStuff[lineofStuff.length() - 1];
	//returns employee type
	switch (i)
	{
	case 49: //1
		return F1;
	case 50: //2
		return F2;
	case 51: //3
		return F3;
	case 52: //4 
		return F4;
	}
}

//functions
int f1(string lineOfStuff);
int f2(string lineOfStuff);
int f3(string lineOfStuff);
int f4(string lineOfStuff);
double Salf1(float a);
double Salf2(float a);
double Salf3(string lineOfStuff);
double Salf4(string lineOfStuff);

//checks if the line is a department line
bool DepartCheck(string lineOfStuff)
{
	string DepartmentList;
	if (lineOfStuff[lineOfStuff.length() - 1] == 't')
		return true;

	return false;
}

string NameofDepart(string Line)
{
	string delimiter = "#";
	int pos = 0;
	pos = Line.find(delimiter);
	Line.erase(0, pos + 1);
	Line.erase(Line.find(delimiter));
	return Line;
}

string LastDepart(string line)
{
	string delimiter = "#";
	line.erase(line.find(delimiter));
	return line;
}

int main()
{
	file.open("salary.txt");

	//collects all department names
	string DepartList;

	//lots of variables
	int EmployeeCount = 0;
	int f1Count = 0, f2Count = 0, f3Count = 0, f4Count = 0;
	int f1Hours = 0, f2Hours = 0, f3Hours = 0, f4Hours = 0;
	double f1Salary = 0, f2Salary = 0, f3Salary = 0, f4Salary = 0;
	double DepartMentSal = 0, DepartMentHours = 0;
	while (true)
	{
		//get the entire line
		string line;
		getline(file, line);

		if (DepartCheck(line))
		{
			DepartList = (line + '#') + DepartList;
		}

		if (DepartCheck(line) && EmployeeCount >= 1)
		{
			cout << "\n*********" << endl;
			cout << NameofDepart(DepartList) << endl;
			cout << "F1: " << f1Count << "  Salary: " << '$' << f1Salary << setw(10) << "  Hours: " << f1Hours << endl;
			cout << "F2: " << f2Count << "  Salary: " << '$' << f2Salary << setw(10) << "  Hours: " << f2Hours << endl;
			cout << "F3: " << f3Count << "  Salary: " << '$' << f3Salary << setw(10) << "  Hours: " << f3Hours << endl;
			cout << "F4: " << f4Count << "  Salary: " << '$' << f4Salary << setw(10) << "  Hours: " << f4Hours << endl;
			cout << "\nEmployee Count: " << EmployeeCount << "  Total Hours: " << DepartMentHours << endl;
			cout << "Total Department Salary:  " << "$" << DepartMentSal << endl;
			cout << "*********" << endl;

		}
		if (line == "EOF" && EmployeeCount >= 1)
		{
			cout << "\n*********" << endl;
			cout << LastDepart(DepartList) << endl;
			cout << "F1: " << f1Count << "  Salary: " << "$" << f1Salary << setw(10) << "  Hours: " << f1Hours << endl;
			cout << "F2: " << f2Count << "  Salary: " << "$" << f2Salary << setw(10) << "  Hours: " << f2Hours << endl;
			cout << "F3: " << f3Count << "  Salary: " << "$" << f3Salary << setw(10) << "  Hours: " << f3Hours << endl;
			cout << "F4: " << f4Count << "  Salary: " << "$" << f4Salary << setw(10) << "  Hours: " << f4Hours << endl;
			cout << "\nEmployee Count: " << EmployeeCount << "  Total Hours: " << DepartMentHours << endl;
			cout << "Total Department Salary:  " << "$" << DepartMentSal << endl;
			cout << "*********" << endl;
		}

		if (DepartCheck(line))
		{   //reset variables for each department
			f1Count = 0, f2Count = 0, f3Count = 0, f4Count = 0;
			f1Hours = 0, f2Hours = 0, f3Hours = 0, f4Hours = 0;
			f1Salary = 0, f2Salary = 0, f3Salary = 0, f4Salary = 0;
			DepartMentHours = 0; DepartMentSal = 0; EmployeeCount = 0;
		}

		//what to do with each employee
		switch (employeeFinder(line))
		{
			int a;
		case F1:
			f1Count++;
			EmployeeCount++;
			a = f1(line); //a is the hours for that specific employ.
			f1Hours += f1(line);
			DepartMentHours += f1(line);
			f1Salary += Salf1(a);
			DepartMentSal += Salf1(a);
			break;
		case F2:
			f2Count++;
			EmployeeCount++;
			a = f2(line);
			f2Hours += f2(line);
			DepartMentHours += f2(line);
			f2Salary += Salf2(a);
			DepartMentSal += Salf2(a);
			break;
		case F3:
			f3Count++;
			EmployeeCount++;
			f3Hours += f3(line);
			DepartMentHours += f3(line);
			f3Salary += Salf3(line);		
			DepartMentSal += Salf3(line);
			break;
		case F4:
			f4Count++;
			EmployeeCount++;
			f4Hours += f4(line);
			DepartMentHours += f4(line);
			f4Salary += Salf4(line);		
			DepartMentSal += Salf4(line);
			break;
		default:
			break;
		}
		//last line of the file
		if (line == "EOF")
			break;
	}
	system("Pause");
	return 0;
}
//********************************************
//Employee Functions
int f1(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);
	int hours = 0, pos = 0, h = 0;
	while ((pos = lineOfStuff.find(" ")) != string::npos)
	{
		h = stoi(lineOfStuff.substr(0, pos));
		hours += h;
		lineOfStuff.erase(0, pos + 1);
	}

	return hours;
}

double Salf1(float a)
{
	a *= 10.25;
	return a;
}

int f2(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);
	//add up the integers
	int hours = 0, pos = 0, h = 0;
	while ((pos = lineOfStuff.find(" ")) != string::npos)
	{
		h = stoi(lineOfStuff.substr(0, pos));
		hours += h;
		lineOfStuff.erase(0, pos + 1);
	}
	return hours;
}

double Salf2(float a)
{
	a = ((a - 35) * 18.95) + 400;
	return a;
}

int f3(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);

	//seperate string
	string token;
	int hours;
	float percent;
	token = lineOfStuff.substr(lineOfStuff.find(" "));
	percent = atof(token.c_str());
	if (percent > .1)
		hours = 40;
	else
		hours = 30;
	return hours;
}
double Salf3(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);

	string token;
	float sales;
	float rate;
	token = lineOfStuff.substr(lineOfStuff.find(" "));
	rate = stof(token);
	token = lineOfStuff.substr(0, lineOfStuff.find(" "));
	sales = stof(token);
	float b = sales * rate;
	return b;
}

int f4(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);

	//cout << lineOfStuff << endl;
	int hours = 0;
	int pos = 0;
	int h = 0;
	while ((pos = lineOfStuff.find(" ")) != string::npos)
	{
		h = stoi(lineOfStuff.substr(0, pos));
		hours += h;
		lineOfStuff.erase(0, pos + 1);
	}
	return hours;
}

double Salf4(string lineOfStuff)
{
	//getting rid of the name and employee type
	lineOfStuff.erase(0, lineOfStuff.find(" ") + 1);
	lineOfStuff.erase(lineOfStuff.length() - 2);
	int pos = 0, h = 0;
	float  hours1 = 0, hours2 = 0;
	//take the first five numbers
	for (int i = 0; i < 10; i++)
	{
		pos = lineOfStuff.find(" ");
		h = stoi(lineOfStuff.substr(0, pos));
		hours1 += h;
		lineOfStuff.erase(0, pos + 1);
		i++;
	}
	hours1 *= 22.55;
	for (int i = 0; i < 4; i++)
	{
		int pos = lineOfStuff.find(" ");
		int h = stoi(lineOfStuff.substr(0, pos));
		hours2 += h;
		lineOfStuff.erase(0, pos + 1);
		i++;
	}
	hours2 *= 48.75;
	double total = hours1 + hours2;
	return total;
}
