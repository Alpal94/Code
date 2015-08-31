/*	Welcome to tic tac toe!
	This program is an undefeatable tic tac toe AI.  It is not only undefeatable, but 
	will use every trick in the book to give the best chance of winning.
	You have the first move, enjoy!
*/

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

// Recording positions.  Intelligent moves, all methods.
void recordPosition(int row, int col);
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
        // First find random number, default move.  Then AI will try and select a better move, based on the methods contained in the
        // switch statements.  Methods are organised based on priority, the result of fooling a trick will be over written if
        // AI can win the game instead, for example.
        if (placement != 10) {
            // 10 will be returned if AI's position is not legal, will repeat the process until is legal.
            while (legal == 10) {
                switch (randRange( 10, 19))
                {
                    case 10:
                        rows = 0; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 12:
                        rows = 1; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 13:
                        rows = 2; cols = 0; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 14:
                        rows = 0; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 15:
                        rows = 1; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 16:
                        rows = 2; cols = 1; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 17:
                        rows = 0; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 18:
                        rows = 1; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
                        AIPosition(rows, cols);
                        break;
                        
                    case 19:
                        rows = 2; cols = 2; rows2 = 0;
                        
                        legal = isAICorrect(rows,cols);
                        intelligentAntiTrick(rows, cols);
                        intelligentMoveCenter(rows, cols);
                        
                        intelligentMoveRows(rows, cols);
                        intelligentMoveCols(rows, cols);
                        intelligentMoveCross(rows, cols);
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
    // 2's represent O's, 1's represent X's.
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
    // Take the centre position if it hasn't been taken already.
    if (boardPositions[ 1 ][ 1 ] == 0) {
        rows = 1;
        cols = 1;
    }
}

// Determine if there is a winning move (for AI or human) using a row.
// Move to block or win if that is the case.
void intelligentMoveRows(int & rows, int & cols)
{
    int count = 0;
    int deltaPlace;
    for (int y = 0; y < 3; y++) {
        // Check every row for friendly O's.
        for (int x = 0; x < 3; x++) {
            if (boardPositions[ x ][ y ] == 2) {
                count++;
            }
        }
        // If row count is 2, may be able to win game.
        if (count == 2) {
            for (int x = 0; x < 3; x++) {
                if (boardPositions[ x ][ y ] == 0) {
                    // Win game if possible.
                    rows = x;
                    cols = y;
                    // Use deltaPlace to determine if AI has made its move.
                    // Don't want to accidentally block, if AI should really win!
                    // Set deltaPlace to 2, that indicates AI has made its move.
                    deltaPlace = 2;
                    
                }
            }
        }
        // AI can't win using the rows. Same code but checks enemy X's.
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
    // Same code for checking rows, but for columns.
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
        // Count enemy in diagonal.
        // This diagonal:
        //     O
        //   X
        // X
        y--;
        if (boardPositions[ x ][ y ] == 1) {
            counta++;
        }
    }
    if (counta == 2) {
        // If count is equal to 2, may able to move (if AI hasn't taken piece already)
        y = 3;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y--;
            // Record position as AI's move.
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }
    y = -1;
    counta = 0;
    for (int x = 0; x < 3; x++) {
        // Count enemy in other diagonal.
        y++;
        if (boardPositions[ x ][ y ] == 1) {
            counta++;
        }
    }
    if (counta == 2) {
        // If count is equal to 2, may able to move (if AI hasn't taken piece already)
        y = -1;
        counta = 0;
        for (int x = 0; x < 3; x++) {
            y++;
            // Record position as AI's move.
            if (boardPositions[ x ][ y ] == 0) {
                rows = x;
                cols = y;
            }
        }
        
    }
    
    // Same code as before, but instead will allow AI to win the game, if possible.
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
    // In the array 1 represents crosses, 2 represents knots.
    
    // Check for tricks who's set up involves at least one corner
    // For example
    // X
    //   O
    //   X
    // Or
    //     X
    //   O
    // X
    // Or
    //
    // X O
    //     X
    // For this one, trick is foiled by predetermined steps taken by AI, there is only one case:
    //     X
    //   X
    // O
    
    // To stop the trick.  Force player to move using the horizontal or vertical.  Not diagonal.
    // For example:
    //     X
    //   O
    // X
    // Then
    //     X
    // O O
    // X
    // Then
    //     X
    // O O X
    // X
    //     X
    // O O X
    // X   O
    // Trick avoided.
    
    int counta = 0;
    int y = 0;
    // Check every corner for enemy piece.
    for (int x = 0; x < 3; x += 2)
    {
        for (int y = 0; y < 3; y += 2)
        {
            // If yes, possible trick,act to avoid.  We start with
            if (boardPositions[ x ][ y ] == 1) {
                // Check to see if AI can force a move on the horizontal.
                counta = 0;
                for (int x = 0; x < 3; x++) {
                    // Count number of taken tiles.  If center piece is the only taken, AI can force a move.
                    if ((boardPositions[ x ][ 1 ] == 1) || (boardPositions[ x ][ 1 ] == 2)) {
                        counta++;
                    }
                }
                for (int x = 0; x < 3; x += 2)
                {
                    // Force a move if center piece is the only piece, when count = 1
                    if ((boardPositions[ x ][ 1 ] == 0) && (counta == 1)) {
                        rows = x;
                        cols = 1;
                    }
                }
                counta = 0;
                // Check to see if move can be forced on the vertical.
                for (int y = 0; y < 3; y++) {
                    // Same steps as move forcing for the horizontal.
                    if ((boardPositions[ 1 ][ y ] == 1) || (boardPositions[ 1 ][ y ] == 2)) {
                        counta++;
                    }
                }
                for (int y = 0; y < 3; y += 2)
                {
                    if ((boardPositions[ 1 ][ y ] == 0) && (counta == 1)) {
                        rows = 1;
                        cols = y;
                    }
                }
            }
        }
    }
    
    
    //Check for tricks who's set up doesn't involve a corner.
    // Trick looks like this:
    //   X
    // X O
    //
    // Or
    //   X
    //   O X
    //
    
    
    // If possible trick, take the corner which will stop disaster.
    if (boardPositions[ 1 ][ 0 ] + boardPositions[ 0 ][ 1 ] == 2) {
        rows = 0;
        cols = 0;
    }
    if (boardPositions[ 1 ][ 0 ] + boardPositions[ 2 ][ 1 ] == 2) {
        rows = 2;
        cols = 0;
    }
    if (boardPositions[ 0 ][ 1 ] + boardPositions[ 1 ][ 2 ] == 2) {
        rows = 0;
        cols = 2;
    }
    if (boardPositions[ 2 ][ 1 ] + boardPositions[ 1 ][ 2 ] == 2) {
        rows = 2;
        cols = 2;
    }
}

// Determine if AI's position is legal
int isAICorrect(int row1, int col1)
{
    // Returning number 10 will force the while loop to generate a new random number.
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
    // Count elements in each row to see if game has ended.
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
    // Count elements in each column to see if game has ended.
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
    // Count elements in each diagonal to see if game has ended.
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


