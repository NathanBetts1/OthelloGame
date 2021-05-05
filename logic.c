//
// Created by Nathan Betts on 05/05/2021.
//

#include <stdio.h>
#include <time.h>
#include "logic.h"

int lettertoNum(char letter){
    //functon to convert input letter to number
    //Using simple if statements and their respective return values.
    if(letter == 'a'){
        return 0;
    }
    if(letter == 'b'){
        return 1;
    }
    if(letter == 'c'){
        return 2;
    }
    if(letter == 'd'){
        return 3;
    }
    if(letter == 'e'){
        return 4;
    }
    if(letter == 'f'){
        return 5;
    }
    if(letter == 'g'){
        return 6;
    }
    if(letter == 'h'){
        return 7;
    }
    else{
        return -1;
    }

}
int isLegal(char board[][8],int column, int row){
    // if the selected position is a blank this function returns 1
    if(board[row][column] == ' '){
        return 1;
    }
    return -1;
}

int isValidBlack(char board[][8],int column,int row)
{
    //function to check the validity of a selected move.
    //commeting will be the same for isValidWhite, just alternating colours
    int numWhite=0;
    int i=0;
    int j=0;
    //Checks Up by increasing row by 1 each time
    //if a white is encountered increases numWhite
    //then if a 'B' is found and numWhite is greater or equal to 1 move is valid
    for(i=row+1;i<8;i++){
        if(board[i][column]=='W'){
            numWhite++;
        }

        if((board[i][column] =='B')&& numWhite>=1){
            return 1;
        }
    }
    numWhite=0;
    //Same as above but checks to the Down
    for(i=row-1;i>=0;i--){
        if(board[i][column]=='W'){
            numWhite++;
        }

        if((board[i][column] =='B')&& numWhite>=1){
            return 1;
        }
    }
    numWhite=0;
    //Checks Right by increasing column
    for(i=column+1;i<8;i++){
        if(board[row][i]=='W'){
            numWhite++;
        }

        if((board[row][i] =='B')&& numWhite>=1){
            return 1;
        }
    }
    numWhite=0;
    //Checks left by decreasing column

    for(i=column-1;i>=0;i--){
        if(board[row][i]=='W'){
            numWhite++;
        }

        if((board[row][i] =='B')&& numWhite>=1){
            return 1;
        }
    }




    numWhite=0;
    //Checks upper left diagonal by decreasing both row and column
    i = row-1; j = column-1;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            return 1;
        }
        i--; j--;
    }

    numWhite=0;
    //Checks lower right  diagonal by increasing both row and column

    i = row+1; j = column+1;
    while(i<8 && j<8)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            return 1;
        }
        i++; j++;
    }



    numWhite=0;
    //Checks lower left diagonal by decreasing column and increasing row

    i = row+1; j = column-1;
    while(i<8 && j>=0)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            return 1;
        }
        i++; j--;
    }


    numWhite=0;
    //Checks upper right diagonal by decreasing row and increasing column

    i = row-1; j = column+1;
    while(i>=0 && j<8)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            return 1;
        }
        i--; j++;
    }


    return -1;
}


int isValidWhite(char board[][8],int column,int row)
{
    //Same commenting as isValidBlack with colours inverted
    //Check Right
    int numBlack=0;
    int i=0;
    int j=0;

    for(i=row+1;i<8;i++){
        if(board[i][column]=='B'){
            numBlack++;
        }

        if((board[i][column] =='W')&& (numBlack>=1)){
            return 1;
        }
    }
    numBlack=0;
    for(i=row-1;i>=0;i--){
        if(board[i][column]=='B'){
            numBlack++;
        }

        if((board[i][column] =='W')&& (numBlack>=1)){
            return 1;
        }
    }
    numBlack=0;
    for(i=column+1;i<8;i++){
        if(board[row][i]=='B'){
            numBlack++;
        }

        if((board[row][i] =='W')&& (numBlack>=1)){
            return 1;
        }
    }
    numBlack=0;
    for(i=column-1;i>=0;i--){
        if(board[row][i]=='B'){
            numBlack++;
        }

        if((board[row][i] =='W')&& (numBlack>=1)){
            return 1;
        }
    }

    numBlack=0;
    i = row-1; j = column-1;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='B'){
            numBlack++;
        }
        if((board[i][j]=='W')&& (numBlack>=1)){
            return 1;
        }
        i--; j--;
    }

    numBlack=0;
    i = row+1; j = column+1;
    while(i<8 && j<8)
    {
        if(board[i][j]=='B'){
            numBlack++;
        }
        if((board[i][j]=='W')&& (numBlack>=1)){
            return 1;
        }
        i++; j++;
    }



    numBlack=0;
    i = row+1; j = column-1;
    while(i<8 && j>=0)
    {
        if(board[i][j]=='B'){
            numBlack++;
        }
        if((board[i][j]=='W')&& (numBlack>=1)){
            return 1;
        }
        i++; j--;
    }


    numBlack=0;
    i = row-1; j = column+1;
    while(i>=0 && j<8)
    {
        if(board[i][j]=='B'){
            numBlack++;
        }
        if((board[i][j]=='W')&& (numBlack>=1)){
            return 1;
        }
        i--; j++;
    }

    return -1;
}
