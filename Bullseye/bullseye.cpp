/*	In this Google CodeJam problem, Maria has to draw many concentric rings.
	But Maria only has a limited supply of paint.  
	Given a radius and t millimeters of paint, this program figures out how many rings Maria
	can draw.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int paintRing(int r, int n);

int main() 
{
	ifstream input;
	ofstream output;

	input.open("input.txt");
	output.open("A-small.out");
	
	// Get number of test cases
	int T;
	input >> T;
	
	// Variables
	int con[ 2 ];
	long paintUsed;
	long n;
	
	for (int i = 0; i < T; i++ ) {
		// Gather restraints for problem
		input >> con[ 0 ];
		input >> con[ 1 ];
		paintUsed = 0;
		n = 0;

		while (paintUsed <= (con[ 1 ] * M_PI )) {
			paintUsed += paintRing( con[ 0 ], n );
			n++;
		}
		output << "Case #" << i+1 << ": " << n-1 << endl;	
	}
}

int paintRing(int r, int n)
{
	return (long) (M_PI * ( pow(r + 2*n + 1, 2) - pow(r + 2*n, 2) ) ); 
}

		

		
