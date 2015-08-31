#include<iostream>
using namespace std;

int main() {
	int T;
	double a, b, c, d, e, f, g;
	cin >> T;
	bool perfect;

	for (int i = 0; i < T; i++) {
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
		
	
