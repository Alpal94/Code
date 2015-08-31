#include<iostream>
#include<string>
using namespace std;

//Methods
string boardPositions [ 8 ][ 8 ];
void boardSetUp();
void drawChessBoard();
void moveKnight(int inX, int inY);

//Variables
int inX, inY, outX, outY;

int main() {
	boardSetUp();
	drawChessBoard();
	
	for (int i = 1;   ; i++) {	
		cin >> inY >> inX;
		cin >> outY >> outX;
		
		boardPositions [ outX- 1 ][ outY - 1 ] = boardPositions [ inX - 1 ][ inY - 1];
		boardPositions [ inX - 1 ][ inY - 1] = "   ";
		
		moveKnight( 7 , 1 );

		drawChessBoard();
	}
}

void boardSetUp() {
	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++) 
			boardPositions [ i ][ j ] = "   ";

	for(int i = 0; i < 8; i++) boardPositions [ 1 ][ i ] = "P  ";	
	for(int i = 0; i < 8; i++) boardPositions [ 6 ][ i ] = "bB ";

	for(int i = 0; i < 8; i=i+7) boardPositions [ 0 ][ i ] = "C  ";
	for(int i = 1; i < 8; i=i+5) boardPositions [ 0 ][ i ] = "kn ";
	for(int i = 2; i < 8; i=i+3) boardPositions [ 0 ][ i ] = "B  ";
	boardPositions [ 0 ][ 3 ] = "K  "; boardPositions [ 0 ][ 4 ] = "Q  "; 

	
	for(int i = 0; i < 8; i=i+7) boardPositions [ 7 ][ i ] = "bC ";
	for(int i = 1; i < 8; i=i+5) boardPositions [ 7 ][ i ] = "bkn";
	for(int i = 2; i < 8; i=i+3) boardPositions [ 7 ][ i ] = "bB ";
	boardPositions [ 7 ][ 3 ] = "bK "; boardPositions [ 7 ][ 4 ] = "bQ "; 
}

void drawChessBoard() {
	for (int i = 0; i < 8; i++ ) {
		for (int j = 0; j < 8; j++) {
			cout << boardPositions [ i ][ j ] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void moveKnight(int inX, int inY) {
	if( (boardPositions [ inX ][ inY ] == "bkn" ) && (boardPositions [ inX - 2 ][ inY + 1] == "   " )) {
		boardPositions [ inX ][ inY ] = "   ";
		boardPositions [ inX - 2][ inY + 1 ] = "bkn ";
	}
}
		 
