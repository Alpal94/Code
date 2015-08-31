#include <iostream>
using namespace std;

int main()
{
	int array[2];
	
	for (int i = 0; ; i++) {
		for (int i = 0; i < 2; i++ ) cin >> array[i];
			for (int i = 0; i < 2; i++ ) cout << array[i];
			cout << endl;
		
		if (array[0] == 0 && array[1] == 0) break;
		
		int count = array[0];
		while (count >= array[1]) {
			count++;
		}
	}
}	
