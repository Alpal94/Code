#include<iostream>
#include<fstream>
#include<cmath>
#include<tgmath.h>
#include<sstream>
using namespace std;

int main() {
	int array[2];
	for (int i = 0; i < 100; i++) {	
		int C; int n;
		cin >> C >> n;
		int v[n + 1];
		int w[n + 1];
		int m[n + 1][C + 1];
		cout << "input " << n << " " << C << endl;
		v[0] = 0;	
		w[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> w[i] >> v[i];
			cout << w[i] << "  ddd   " << v[i] << endl;
		}
		cout << "..... :" << endl;
		for (int i = 1; i < n+1; i++ ) {
			for (int j = 0; j < C+1; j++) {
				if (w[i] <= j) {
					m[i][j] = fmax(m[i-1][j], m[i-1][j-w[i]] + v[i]);
				}
				else {
					m[i][ j] = m[i-1][ j ];
				}
			}
		} cout << m[C][n] << "KDKKDFDFJ" << endl;
		cout << "danger danger" << endl;
	}
}
				
