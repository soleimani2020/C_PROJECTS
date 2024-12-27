/******************************************************************************

                             Tic Tac Toe Game

*******************************************************************************/

#include <stdio.h>

char board[3][3];
#define EMPTY ' '
char current_player = 'X';



// Function to initialize the game board
void InitializeBoard()
{

    for (int i=0; i< 3; i++){
        for (int j=0;j<3;j++)
        {
            board[i][j]=EMPTY;
        }
    }

}


// Function to display the board game

void DisplayBoard(){

    for (int i=0; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            printf(" %c",board[i][j]);
            if (j<2){
                printf("|");
            }
        }
        printf("\n");
        if (i<2){
            printf("--+--+--\n");
        }
    }

}



// Player Switch function

void Player_Switch(){

    if (current_player == 'X'){
        current_player == 'O';
    } else {
        current_player == 'X';
    }
}


// Function to check for a winner
int CheckWinningMoves() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) ||
            (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
        (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)) {
        return 1;
    }

    return 0;
}


// Function to check if the game is a draw
int CheckDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
                // Someone has won
            }
        }
    }
    return 1;
    //Draw
}





int main()
{
    InitializeBoard();
    DisplayBoard();
    WinningMoves();


    return 0;
}


