//Nathan Betts- 20358446
//Othello Board Game
//Software Engineering Project

#include <stdio.h>
#include <time.h>
#include "flip.h"
#include "logic.h"
#include "board.h"
#include "play.h"
//Structure to hold player data i.e. their name and their score
typedef struct o_player
{
    char name[20];
    int score;
}othelloPlayer;

othelloPlayer player1,player2;

int main(void)
{
    char board[8][8];
    time_t rawtime;
    struct tm * timeinfo;
    int playerOne;
    int playerTwo;
    int legality =-1;
    char letter;
    int row,column;
    int valid;
    int i,j,k;
    int gameOver = 1;
    int currentPlayer = playerOne;
    int validSpaces =0;
    FILE *fptr;
//open file for printing results to
    fptr = fopen("othello-results.txt","rb+");
    if(fptr == NULL) //if file does not exist, create it
    {
        fptr = fopen("othello-results.txt", "wb");
    }

    //Welcome Message to game
    printf("                    Welcome to ");
    printf("\n"
           " _______ _______ __   __ _______ ___     ___     _______ \n"
           "|       |       |  | |  |       |   |   |   |   |       |\n"
           "|   _   |_     _|  |_|  |    ___|   |   |   |   |   _   |\n"
           "|  | |  | |   | |       |   |___|   |   |   |   |  | |  |\n"
           "|  |_|  | |   | |   _   |    ___|   |___|   |___|  |_|  |\n"
           "|       | |   | |  | |  |   |___|       |       |       |\n"
           "|_______| |___| |__| |__|_______|_______|_______|_______|    \n\n\n");

//Initailise the board
    initboard(board);
    //ask players for their names and read into the structures
    printf("Enter name of Player 1 (Black):");
    scanf("%[^\n]s", player1.name);
    //Flush the standard input
    fflush(stdin);
    printf("\nEnter name of Player 2 (White):");
    scanf("%[^\n]s", player2.name);
    //Get score of the board 2:2
    getScore(board);
    //print board and start game
    printboard(board);
//While game isnt over
    while(gameOver!=-1){
        //Check whether the game is actually not over
        gameOver = Over(board);

        if(gameOver == -1){
            //if game is over, print winnner, their score and print the same data with time and date to othello-results.txt
            printf("\n\nGame Over, there are no more moves\n The Winner is: ");
            if(player1.score>player2.score){
                printf("%s with %d points",player1.name,player1.score);
                printboard(board);
                time ( &rawtime );
                timeinfo = localtime ( &rawtime );
                fprintf(fptr,"%s:Winner = %s, Score:%d", asctime (timeinfo),player1.name,player1.score);
                break;
            }
            else{
                printf("%s with %d points",player2.name,player2.score);
                printboard(board);
                time ( &rawtime );
                timeinfo = localtime ( &rawtime );
                fprintf(fptr,"%s:Winner = %s, Score:%d", asctime (timeinfo),player2.name,player2.score);
                break;
            }
        }
        //using the currentPLayer variable to control the game flow for each player
        if(currentPlayer==playerOne)
        {
            again://use a goto event for when an invalid or non legal move is proposed , to repeat process
            printf("\n%s's turn, Please enter a position: for example d 4\n", player1.name);
            scanf("%s", &letter);
            //if they try to pass, loop over board sending each i jth to the function isValid to see if
            //there exists a valid move, if there is then a pass cannot be made
            if(letter == 'p'){
                validSpaces=0;
                for(i=0;i<8;i++){
                    valid=0;
                    for(j=0;j<8;j++){
                        valid =  isValidBlack(board,i,j);
                        if(valid == 1){
                            validSpaces++;
                        }
                    }
                }
                if(validSpaces >=1){
                    printf("You Cannot Pass, there is a valid move\n");
                    //cant pass so try again, using goto
                    goto again;
                }
                else{
                    //if you can pass, currentPlayer becomes other player and using goto againWhite.
                    printf("%s passed, its %s turn",player1.name,player2.name);
                    currentPlayer=playerTwo;
                    goto againWhite;
                }
            }
            //scan in row
            scanf("%d",&row);
            //convert the letter to number using function
            column = lettertoNum(letter);
            //remove 1 from row as board is indexed from 0
            row = row - 1;
            //checks if the proposed position is within confines of the board
            if(column<8 &&row<8&&column>-1)
            {
                // assign variable legailty to outcome of isLegal function
                legality = isLegal(board,column,row);
                if(legality == -1 )
                {
                    //if it returns -1 then the move is not legal and go to again
                    printf("Non Legal move, Try Again!\n");
                    goto again;
                }
                else
                {
                    //then check if the move is Valid
                    valid =isValidBlack(board,column,row);
                    if(valid == 1)
                    {
                        //if so place the token and then flip the 'W' which are applicable
                        board[row][column]= 'B';
                        flipBlack(board,row,column);
                        //get the score after the flip
                        getScore(board);
                        printboard(board);
                        //print the board to show move and current score
                        //move over
                        //make currentPLayer the other player
                        currentPlayer = playerTwo;
                    }
                    else
                    {
                        printf("Non Legal Move! Try Again\n");
                        goto again;
                    }
                }
            }
            else{
                printf("Invalid Move! Try again!\n");
                goto again;
            }
        }

//Commmenting the same but with roles reversed.
        if(currentPlayer==playerTwo)
        {
            valid=0;
            againWhite:
            printf("\n%s's turn, Please enter a position: for example d 4\n", player2.name);
            scanf("%s", &letter);
            if(letter == 'p'){
                validSpaces=0;
                for(i=0;i<8;i++){
                    valid=0;
                    for(j=0;j<8;j++){
                        valid =  isValidWhite(board,i,j);
                        if(valid == 1){
                            validSpaces++;
                        }
                    }
                }
                if(validSpaces >=1){
                    printf("You Cannot Pass, there is a valid move\n");
                    goto againWhite;
                }
                else{
                    printf("%s passed, its %s turn",player2.name,player1.name);
                    currentPlayer=playerOne;
                    goto again;
                }
            }
            scanf("%d",&row);
            column = lettertoNum(letter);
            row = row - 1;
            if(column<8 &&row<8&&column>-1)
            {
                legality = isLegal(board,column,row);
                if(legality == -1 )
                {
                    printf("Non Legal move, Try Again!\n");
                    goto againWhite;
                }
                else
                {
                    valid = isValidWhite(board,column,row);
                    if(valid == 1)
                    {
                        board[row][column]= 'W';
                        flipWhite(board,row,column);
                        getScore(board);
                        printboard(board);
                        currentPlayer = playerOne;
                    }
                    else
                    {
                        printf("Non Legal Move! Try Again\n");
                        goto againWhite;
                    }
                }
            }
            else{
                printf("Invalid Move! Try again!\n");
                goto againWhite;
            }
        }
    }
}
