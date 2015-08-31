/*	This is a simple program, which could be used in a game.
	It's main use is to experiment with structs, it is a demonstration.
	The program creates a struct, which could be an enemy ship.  The program
	then creates an enemy ship and "moves" it.
*/
	
#include<iostream>
using namespace std;

struct enemyShip {
    int x_coordinate;
    int y_coordinate;
};

enemyShip newEnemy()
{
    enemyShip ship;
    ship.x_coordinate = 0;
    ship.y_coordinate = 0;
    return ship;
}

enemyShip move(enemyShip ship) {
    ship.x_coordinate += 1;
    ship.y_coordinate += 1;
}

int main() {
    enemyShip daEnemy[100];
    for (int i = 0; i<10; i++) {
        enemyShip enemy = newEnemy();
        enemy = move( enemy );
        cout << enemy.x_coordinate;
    }
    
}
