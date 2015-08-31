#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double smallestNumber1;
	double smallestNumber2;
	double N;
	double Y;

	N = 10;
	for (double i = 0; i < 200; i++) {
	
		Y = N;


		
		//N = Y - 0.0001; 
		smallestNumber1 = N - 4.83;




		N = Y + 0.0001;
		smallestNumber2 = N - 4.83;



		if(abs(smallestNumber1) < 0.00001) break;
		if(abs(smallestNumber2) < 0.00001) break;
		//if(Y/(4*pow(2,i)) < 0.00001) {
		//	cout << "  " << Y/(4*pow(2,i)) << endl;
		////	break;
	//	}


		cout << N << endl;

		N = Y;		
		if(abs(smallestNumber1) < abs(smallestNumber2)) N += -N/(2*pow(2,i));	
		else N += N/(2*pow(2,i));
 
	}
	cout << N << endl;
}
