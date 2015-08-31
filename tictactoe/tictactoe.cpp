#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// Array to store board positions.
int boardPositions[ 3 ] [ 3 ];
int row;
int col;
int row1;
int row2;
int rows2;
int legal;
 



// Generate random numebers.
int randRange (int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// Recording positions.
void recordPosition(int row, int col);
void AIMethods(int rows, int cols);
int isAICorrect(int row, int col);
void AIPosition(int rows, int cols);
void intelligentMoveCenter(int & rows, int & cols);
void intelligentAntiTrick(int & rows, int & cols);
void intelligentMoveRows(int & rows, int & cols);
void intelligentMoveCols(int & rows, int & cols);
void intelligentMoveCross( int & rows, int & cols);
void winLoseHorizontal(int winLose, int & placement);
void winLoseVertical(int winLose, int & placement);
void winLoseCross(int winLose, int & placement);
void printBoard();
 



// Execute program.
int main()
{
    cout << "Welcome to TicTacToe!  Have fun " << endl;
    cout << " " << endl;
    
    
    
    // Enums to make the program look better to user.  But they do not work, will fix that later.
    // Quit enum theoretically allows user to type quit to exit program.  But it does not work.
    enum ticTac {
        alpha = 1,
        bravo,
        charlie,
        delta,
        ecko,
        foxtrot,
        golf,
        hotel,
        india,
        quit
    };
    
    
    // Board position.  Number from 1 to 9.
    int placement;
    // Allows AI to know if move is legal.
    bool yesno = false;
    
    
    
    // Type 10 to quit the program.
    while (placement != 10) {
        
        // Ask human for his/her move, and accept response.
        cout << "Type your move in here: ";
        int placement;
        cin >> placement;
        cout << " " << endl;
        
        // Record humans move on the board.
        switch (placement)
        {
            case 1:
                recordPosition(0,0);
                break;
                
            case 2:
                recordPosition(1,0);
                break;
                
            case 3:
                recordPosition(2,0);
                break;
                
            case 4:
                recordPosition(0,1);
                break;
                
            case 5:
                recordPosition(1,1);
                break;
                
            case 6:
                recordPosition(2,1);
                break;
                
            case 7:
                recordPosition(0,2);
                break;
                
            case 8:
                recordPosition(1,2);
                break;
                
            case 9:
                recordPosition(2,2);
                break;
            case 10:
                //Final goodbye.
                cout << "" << endl;
                cout << "Good bye!  Thanks for the game. " << endl;
                return 0;
        }
        
        // Terminate if you win
        winLoseHorizontal(1, placement);
        winLoseVertical(1, placement);
        winLoseCross(1, placement);
        if( placement == 10)
        {
            printBoard();
            cout << " " << endl;
            cout << " Good game " << endl;
            return 0;
        }
        
        // Assume that the AI got it wrong.  AI must prove its right.
        int legal = 10;
        int rows, cols;
        
        // AI's turn.
        if (placement != 10) {
            while (legal == 10) {
                switch (randRange( 10, 19))
                {
                    case 10:
                        rows = 0; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 12:
                        rows = 1; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 13:
                        rows = 2; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 14:
                        rows = 0; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 15:
                        rows = 1; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 16:
                        rows = 2; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 17:
                        rows = 0; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 18:
                        rows = 1; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 19:
                        rows = 2; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        AIMethods(rows, cols);
                        AIPosition(rows, cols);
                        break;
                }
                
            }
        }
        
        
        //Print board
        printBoard();
        
       //Terminate if you lose
        winLoseHorizontal(2, placement);
        winLoseVertical(2, placement);
        winLoseCross(2, placement);
        if( placement == 10)
        {
            cout << " " << endl;
            cout << " Good game " << endl;
            return 0;
        }
        
    }
}

//Print board
void printBoard()
{
    // Print the board based on the array.
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (boardPositions[ x ][ y ] == 0) {
                cout << " ";
            }
            else if (boardPositions[ x ][ y ] == 2) {
                cout << "O";
            }
            else {
                cout << "X";
            }
            
        }
        cout << endl;
    }
}

// Record human position.  Return error if human tries to cheat, and allow the AI to
// steal his/her move if thats the case, for punishment.
void recordPosition(int row, int col)
{
    if (boardPositions[ row ][ col ] == 1) {
        cout << "Illegal move!  Try something else" << endl;
    }
    else if (boardPositions[ row ][ col ] == 2) {
        cout << "Illegal move!  Try something else" << endl;
    }
    else {
        boardPositions[ row ][ col ] = 1;
    }
}

// Take the centre position if available.
void intelligentMoveCenter(int & rows, int & cols)
{
    if (boardPositions[ 1 ][ 1 ] == 0) {
        rows = 1;
        cols = 1;
    }
}

// All the AI's methods
void AIMethods(int rows, int cols)
{
    void intelligentMoveCenter(int & rows, int & cols);
    void intelligentMoveRows(int & rows, int & cols);
    void intelligentMoveCols(int & rows, int & cols);
    void intelligentMoveCross( int & rows, int & cols);
    rows = rows;
    cols = cols;
}

// Determine if there is a winning move (for AI or human) using a row.
// Move to block or win if that is the case.
void intelligentMoveRows(int & rows, int & cols)
{
    int count = 0;
    int deltaPlace;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (boardPositions[ x ][ y ] == 2) {
                count++;
            }
        }
        if (count == 2) {
            for (int x = 0; x < 3; x++) {
                if (boardPositions[ x ][ y ] == 0) {
                    rows = x;
                    cols = y;
                    deltaPlace = 2;
                    
                }
            }
        }
        if (deltaPlace != 2) {
            count = 0;
            for (int x = 0; x < 3; x++) {
                if (boardPositions[ x ][ y ] == 1) {
                    count++;
                }
            }
            if (count == 2) {
                for (int x = 0; x < 3; x++) {
                    if (boardPositions[ x ][ y ] == 0) {
                        rows = x;
                        cols = y;
                    }
                }
            }
        }
        count = 0;
    }
}


// Determine if there is a winning move (for AI or human) using a column.
// Move to block or win if that is the case.
void intelligentMoveCols(int & rows, int & cols)
{
    int count = 0;
    int deltaPlace;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (boardPositions[ x ][ y ] == 2) {
                count++;
            }
            
        }
        if (count == 2) {
            for (int y = 0; y < 3; y++) {
                if (boardPositions[ x ][ y ] == 0) {
                    rows = x;
                    cols = y;
                    deltaPlace = 2;
                }
            }
        }
        if (deltaPlace != 2) {
            count = 0;
            for (int y = 0; y < 3; y++) {
                if (boardPositions[ x ][ y ] == 1) {
                    count++;
                }
            }
            if (count == 2) {
                for (int y = 0; y < 3; y++) {
                    if (boardPositions[ x ][ y ] == 0) {
                        rows = x;
                        cols = y;
                        
                    }
                }
            }
        }
        count = 0;
    }
    deltaPlace = 0;
}

// Determine if there is a winning move (for AI or human) using a diagonal.
// Move to block or win if that is the case.
void intelligentMoveCross( int & rows, int & cols)
{
    int counta = 0;
    int y = 3;
    for (int x = 0; x < 3; x++) {
        y--;
        if (boardPositions[ x ][ y ] == 1) {
            counta++;
        }
    }
    if (counta == 2) {
        y = 3;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y--;
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }
    y = -1;
    counta = 0;
    for (int x = 0; x < 3; x++) {
        y++;
        if (boardPositions[ x ][ y ] == 1) {
            counta++;
        }
    }
    if (counta == 2) {
        y = -1;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y++;
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }

    counta = 0;
    y = 3;
    for (int x = 0; x < 3; x++) {
        y--;
        if (boardPositions[ x ][ y ] == 2) {
            counta++;
        }
    }
    if (counta == 2) {
        y = 3;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y--;
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }
    y = -1;
    counta = 0;
    for (int x = 0; x < 3; x++) {
        y++;
        if (boardPositions[ x ][ y ] == 2) {
            counta++;
        }
    }
    if (counta == 2) {
        y = -1;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y++;
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }
    y = 0;
    counta = 0;
}

// Avoid falling for tricks
void intelligentAntiTrick(int & rows, int & cols)
{
    for (int x = 0; x < 3; x += 2)
    {
        for (int y = 0; x < 3; y += 2)
        {
            if (boardPositions[ x ][ y ] == 1) {
                for (int x = 0; x < 3; x += 2)
                {
                    if (boardPositions[ x ][ 1 ] == 0) {
                        rows = x;
                        cols = y;
                    }
                }
                for (int y = 0; y < 3; y += 2)
                {
                    if (boardPositions[ 1 ][ y ] == 0) {
                        rows = x;
                        cols = y;
                    }
                }
            }
        }
    }
}

// Determine if AI's position is legal
int isAICorrect(int row1, int col1)
{
    if (boardPositions[ row1 ][ col1 ] == 1) {
        legal = 10;
        return 10;
    }
    else if (boardPositions[ row1 ][ col1 ] == 2) {
        legal = 10;
        return 10;
    }
    else {
        legal = 0;
        return 0;
    }
}

// Record the AI's position
void AIPosition(int rows, int cols)
{
    if (legal != 10) {
        boardPositions[ rows ][ cols ] = 2;
    }
}

// Does the game end, horizontal win lose?
void winLoseHorizontal(int winLose, int & placement)
{
    int counta = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (boardPositions[ x ][ y ] == winLose) {
                counta++;
            }
        }
        if (counta == 3) {
            if (winLose == 1) {
                cout << "You win, well done!" << endl;
                placement = 10;
            }
            else if (winLose == 2) {
                cout << "You lose, better luck next time!" << endl;
                placement = 10;
            }
            
        }
        counta = 0;
    }
}

//Vertical win lose?
void winLoseVertical(int winLose, int & placement)
{
    int counta = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (boardPositions[ x ][ y ] == winLose) {
                counta++;
            }
        }
        if (counta == 3) {
            if (winLose == 1) {
                cout << "You win, well done!" << endl;
                placement = 10;
                }
            else if (winLose == 2) {
                cout << "You lose, better luck next time!" << endl;
                placement = 10;
            }
            
        }
        counta = 0;
    }
}

//Cross win lose?
void winLoseCross(int winLose, int & placement)
{
    int counta = 0;
    int y = 3;
    for (int x = 0; x < 3; x++) {
        y--;
        if (boardPositions[ x ][ y ] == winLose) {
            counta++;
        }
    }
    if (counta == 3) {
        cout << "You lose, better luck next time!" << endl;
        placement = 10;
    }
    y = -1;
    counta = 0;
    for (int x = 0; x < 3; x++) {
        y++;
        if (boardPositions[ x ][ y ] == winLose) {
            counta++;
        }
    }
    if (counta == 3) {
        if (winLose == 1) {
            cout << "You win, well done!" << endl;
            placement = 10;
        }
        else if (winLose == 2) {
            cout << "You lose, better luck next time!" << endl;
            placement = 10;
        }
    }
    y = 3;
    counta = 0;
}


