/*	This program solves a google CodeJam problem.

	We are given a description of a Bangladesh flag.  
	However, the red centre circle of the flag may be off center.  And the rectangle may not be perfect, and the radius of the circle may not be perfect.
  
	This is not good, because we want a perfect flag.
	The program will determine if the flag is perfect, and then return the result to stdout.
*/

#include<iostream>
using namespace std;

int main() {
	int T;
	double a, b, c, d, e, f, g;
	cin >> T;
	bool perfect;

	for (int i = 0; i < T; i++) {
		// a,b,c,d are the positions of the flag corners.
		// e, f are the position of the red circle centre.
		// g is the radius of our red circle.
		cin >> a >> b >> c >> d >> e >> f >> g;
		
		cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl;
			
		perfect = true;
		if ((a-c)/(b-d) != 10/6) { cout << "-1" << endl; perfect = false; }
		
		if ((a-c)/2 != (e-c) && (b-d)/2 != (f - d)/2) { cout << "-1" << endl; perfect = false; }
		
		if ((a-c)/g != 1/5) { cout << "-1" << endl; perfect = false; }
		

		if(perfect == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}	
		
	
