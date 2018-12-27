#include <iostream>

using namespace std;

int main()
{
	// Lab 4// -------------------------------
	// Series 1://15, 14, 13, 12, 11, ... -1      
	cout <<"Series 1: "; 
	for (int s1 = 15; s1 >= 0; --s1)      
		cout << s1 <<" "; 

	 //----------------------
	//Series 2:
	//!!!!
	//1, 2, 5, 14, 41, ... 
	cout << "\n\nSeries 2: "; 
	for (int s2=1,j = 1; s2 < 150;){
	    
	      cout << s2  << " ";
		  s2 += j;
		  j *= 3;
	  }

	//---------------- 
	//Series 3: 
	//2, 3, 5, 8, 12, 17, ...  
	cout << "\n\nSeries 3: ";
	for (int s3 = 2, change = 1; s3 <= 40; change++) {
	
		cout << s3 << " ";
		s3 += change;
	}

	//------------------ 
	//Series 4: 
	//1, 2, 5, 26, 677, ... (x*x) + 1 
	cout << "\n\nSeries 4: ";
	for (double s4 = 1; s4 < 459000; s4 = (s4*s4) + 1)
		cout << s4 << " ";

	//--------------------------- 
	//Series 5: 
	//10, 5, 1, -2, -4, -5, -5, -4, -2, ... 
	cout << "\n\nSeries 5: ";
	for (int s5 = 10, chg = -5; s5 < 11; chg++) {
		if (s5 == 10) 
		{
			cout << s5 << " ";
			s5 += chg;
		}
		else {

			cout << s5 << " ";
			s5 += chg;
		}
	}

	//---------------- 
	//Series 6: 
	//1, 8, 27, 64, 125, 216, ... (n)^3 
	cout << "\n\nSeries 6: ";
	for (int s6 = 1, answer; s6 < 9; s6++) {
		answer = pow(s6, 3);
		cout << answer << " ";
	}

	//---------------- 
	//Series 7: 
	//!!!!!!
	//0, 1, 3, 7, 15, 31, 63, ... 
	cout << "\n\nSeries 7: ";
	for (int s7 = 0, chang = 1, add = 0; s7 < 140; )
	{
		cout << s7 << " ";
		s7 += chang;
		chang *= 2;
	}

	// ----------------------
	//Series 8:
	//0, 1, 4, 13, 40, 121, ...
	cout << "\n\nSeries 8: ";
	for (int s8 = 0, delta = 1; s8 < 400;)
	{
	     cout << s8 << " ";
		 s8 += delta;
		 delta *= 3;
	}

	////------------------
	///*series 9: if statement
	//  0, 1, 3, 6, 10, 10, 11, 13, 16, 16, 17, 19, 19, ...*/
	//cout << "\n\nSeries 9: ";
	//for (int s9 = 0; s9 < 100; ) {
	//  cout << << " ";
	//}

	///*series 10:      
	///*7, 9, 14, 20, 27, 33, 42, 52, 63, 73, 86, ...
	//*/     
	//cout <<"\n\nSeries 10: ";
	//int s10 = 7;
	//while (s10 < 150){

	//	cout << s10 << " ";


	//}*/



	system("Pause");
	return 0;
}