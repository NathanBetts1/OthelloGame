//
// Created by Nathan Betts on 05/05/2021.
//

#include <stdio.h>
#include <time.h>
#include "play.h"

typedef struct o_player
{
    char name[20];
    int score;
}othelloPlayer;

othelloPlayer player1,player2;
void getScore(char board[][8]){
    int i=0;
    int j=0;
    int scoreBlack=0;
    int scoreWhite=0;
    //similar to the later function but loop over whole board and get number of 'B' and 'W' and return update the
    //player.score accordingly for each player
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j] == 'B'){
                scoreBlack++;
            }
            if(board[i][j] == 'W'){
                scoreWhite++;
            }
        }
    }
    player1.score = scoreBlack;
    player2.score = scoreWhite;

}



int Over(char board[][8]) {
    int i = 0;
    int numBlank = 0;
    int numBlack = 0;
    int numWhite = 0;
    int j = 0;
    //Loop over the whole board and count number of 'B', 'W' and Blank spaces to see if the game needs to be ended
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == ' ') {
                numBlank++;
            }
            if (board[i][j] == 'W') {
                numWhite++;
            }
            if (board[i][j] == 'B') {
                numBlack++;
            }
        }
    }
    // if there are no 'B','W' or White space then the game is over and return -1;
    if ((numBlank == 0) || (numBlack == 0) || (numWhite == 0)) {
        return -1;
    } else {
        return 1;
    }
}
