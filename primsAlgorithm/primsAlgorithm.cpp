#include<iostream>
using namespace std;

int main() {
	for(int i = 0; ; i++) {
		int C, S, Q;
		cin >> C >> S >> Q;
		if (C == S == Q == 0) break;	
		
		int array[C][C];	
	
		for (int i = 0; i < S; i++) {
			int c1, c2, d;
			cin >> c1 >> c2 >> d;
			
			array[c1][c2] = d;
		}
		
		for (int i = 0; i < Q; i++) {
			int c11, c12;
			cin >> c11 >> c12;
			
			int c101 = c11;
			int c102;
			int min;
			

			for(int i = 0; i < C; i++) {
				cout << "..";
				min = array[c101][0];
				for(int i = 0; i < C; i++) {
					if(array[c101][i] <  min) {
						c102 = i;
						min = array[c101][i];
					}
					cout << endl << c102 << " " << c12 << " " << min << endl;
					if (c102 == c12) break;
					c101 = i;
				} cout << min;
				if (c102 == c12) break;
			}
					
		}
	}
}
