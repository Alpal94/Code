/*	This program will create N nested loops, which can be used in any program to do work.  
	For example, if N = 3 and we want to iterate from i = 0 to i = 5, the equivalent is:
	
	for(int i = 0; i < 6; i++) {
		for (int i = 0; i < 6; i++) {
			for (int i = 0; i < 6; i++) {
			}
		}
	}

	The traditional approach to this program is to use recursion, but recursion is relatively slow.
	I use goto statements to create a more efficient solution.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[] ) {
	//Number of loops
	//int N = atoi(argv[1]);
	//How wide you want your loop
	//int I = atoi(argv[2]);

	//To demonstrate use N = 4, I = 4.  Four nested loops, and I-1 = 3 "wide":
	// for(int i = 0; i < I-1; i++) 
	int N = 4, I = 4;

	int loop[N];
	int errorMsg = 0;	
	int count = 0;
	int a = 0;
	for (int i = 0; i < N; i++ ) loop[ i ] = 0;


	// "nested", where we want to jump back to using goto
	nested:

	//The main loop.  All work done in main loop.	
	for (int i = a; i < I; i++) {	
		//Loop control.  Ensure loop is in correct state.
		if( count != N-1) {
			loop[ count ]++;
			count++;
			goto nested;
		}
		loop[ count ]++;



		//Do work here.  Print state of loop, to show program is working.
		for(int i = 0; i < N; i++) printf("%i ", loop[ i ]);
		printf("\n");	
	}	

    
    
    
    

	//Loop control.  Determine loop state, and whether to go back to main loop.
	//Needs fine tuning but demonstrates concept works.
	for(int i = 0; i < N; i++) {
		if(loop[ 0 ] == I) break; 
		if(loop[ i ] == I) {
			loop[ i ] = 0;
			count = i - 1;
			for(int j = i; j < N; j++) loop[ j ] = 0; 
			//for(int i = 0; i < N; i++) printf("%i ", loop[ i ]);
			goto nested;
		}
	}	
}
