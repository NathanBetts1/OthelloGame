//
// Created by Nathan Betts on 05/05/2021.
//

#include <stdio.h>
#include "board.h"

typedef struct o_player
{
    char name[20];
    int score;
}othelloPlayer;

othelloPlayer player1,player2;
void initboard(char board[][8]){
    //Using the dimensions 8x8 and variables row and column to create the board, and initialise the startung tokens
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            // at positions (3,3),(4,4) assign board[][] to 'W'
            if((row == 3 && col == 3) || (row == 4 && col == 4) )
            {
                board[row][col] = 'W';
            }
                // at positions (3,4),(4,3) assign board[][] to 'B'
            else if((row == 3 && col == 4) || (row == 4 && col == 3) )
            {
                board[row][col] = 'B';
            }
            else
            {
                //then just assign the board[][] to blank
                board[row][col] = ' ';
            }
        }
    }
}

void printboard(char board[][8])
{
// print the players name, their respective colours and their scores
    printf("\n\nScore: %s (Black) %d:%d %s (White)",player1.name,player1.score,player2.score,player2.name);
    printf("\n  ");
    // Loop for printing top border of the board
    for(int col=0;col<8;col++) {

        printf("+---");
    }
    //print end + and go to new line
    printf("+\n");
//using nested loops print formatting and contents of board[][]
    for(int row=0;row<8;row++)
    {
        // Print row indexing along side
        printf("%d ", row+1);
        for( int col=0;col<8;col++)
        {
            //print  wall and then content of board[][] at position row,column
            printf("| %c ",board[row][col]);
        }
        printf("|\n");
        printf("  ");
        for(int k=0;k<8;k++)
            //print bottom border of the game
            printf("+---");

        printf("+\n");
    }
    //print column indexing a-h
    printf("    a   b   c   d   e   f   g   h");

}