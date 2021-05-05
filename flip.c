//
// Created by Nathan Betts on 05/05/2021.
//
#include <stdio.h>
#include <time.h>
#include "flip.h"

void flipBlack(char board[][8],int row,int column){
//Same Function as isValidBlack/White
//Except if move is valid it goes back and turns opposing players tokens to their colours.
//Only Commenting first few as is very intuitive and repetive
    int numWhite=0;
    int i=0;
    int j=0;
    int q=0;
    int r=0;

    for(i=row+1;i<8;i++){
        if(board[i][column]=='W'){
            numWhite++;
        }

        if((board[i][column] =='B')&& (numWhite>=1)){
            //Move is valid therfore, loop over again and if 'W' is found turn to 'B'
            for(j=row+1;j<8;j++)
            {
                if(board[j][column]=='W')
                    board[j][column]='B';
                else
                    break;
            }
        }
    }
    numWhite=0;


    for(i=row-1;i>=0;i--){
        if(board[i][column]=='W'){
            numWhite++;
        }

        if((board[i][column] =='B')&& (numWhite>=1)){
            //Move is valid therfore, loop over again and if 'W' is found turn to 'B'

            for(j=row-1;j>=0;j--)
            {
                if(board[j][column]=='W')
                    board[j][column]='B';
                else
                    break;
            }
        }
    }
    numWhite=0;
    for(i=column+1;i<8;i++){
        if(board[row][i]=='W'){
            numWhite++;
        }

        if((board[row][i] =='B')&& (numWhite>=1)){
            //Move is valid therfore, loop over again and if 'W' is found turn to 'B'

            for(q=column+1;q<8;q++)
            {
                if(board[row][q]=='W'){
                    board[row][q]='B';
                }
                else{
                    break;
                }
            }
        }
    }

    numWhite=0;
    for(i=column-1;i>=0;i--){
        if(board[row][i]=='W'){
            numWhite++;
        }

        if((board[row][i] =='B')&& (numWhite>=1)){
            //Move is valid therfore, loop over again and if 'W' is found turn to 'B'

            for(q=column-1;q>=0;q--)
            {
                if(board[row][q]=='W'){
                    board[row][q]='B';
                }
                else{
                    break;
                }
            }
        }
    }

    numWhite=0;
    i = row-1; j = column-1;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            //Move is valid therfore, loop over again and if 'W' is found turn to 'B'

            q = row-1; r = column-1;
            while(q>=0 && r>=0)
            {
                if(board[q][r]=='W'){
                    board[q][r]='B';
                }
                else{
                    break;
                }
                q--; r--;
            }
        }
        i--; j--;
    }

    numWhite=0;
    i = row+1; j = column+1;
    while(i<8 && j<8)
    {
        if(board[i][j] == 'W'){
            numWhite++;
        }
        if((board[i][j] == 'B')&& (numWhite>=1)){
            q = row+1; r = column+1;
            while(q<8 && r<8)
            {
                if(board[q][r] == 'W')
                    board[q][r]='B';
                else
                    break;
                q++; r++;
            }
        }
        i++; j++;
    }



    numWhite=0;
    i = row+1; j = column-1;
    while(i<8 && j>=0)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            q = row+1; r = column-1;
            while(q<8 && r>=0)
            {
                if(board[q][r]=='W')
                    board[q][r]='B';
                else
                    break;
                q++; r--;
            }
        }
        i++; j--;
    }


    numWhite=0;
    i = row-1; j = column+1;
    while(i>=0 && j<8)
    {
        if(board[i][j]=='W'){
            numWhite++;
        }
        if((board[i][j]=='B')&& (numWhite>=1)){
            q = row-1; r = column+1;
            while(q>=0 && r<8)
            {
                if(board[q][r]=='W')
                    board[q][r]='B';
                else
                    break;
                q--; r++;
            }
        }
        i--; j++;
    }


}




void flipWhite(char board[][8],int row,int column){
    // Left Check
    //Check Right
    int numBlack=0;
    int i=0;
    int j=0;
    int q=0;
    int r=0;

    for(i=row+1;i<8;i++){
        if(board[i][column]=='B'){
            numBlack++;
        }

        if((board[i][column] =='W')&& numBlack>=1){
            for(j=row+1;j<8;j++)
            {
                if(board[j][column]=='B')
                    board[j][column]='W';
                else
                    break;
            }
        }
    }
    numBlack=0;


    for(i=row-1;i>=0;i--){
        if(board[i][column]=='B'){
            numBlack++;
        }

        if((board[i][column] =='W')&& numBlack>=1){
            for(j=row-1;j>=0;j--)
            {
                if(board[j][column]=='B')
                    board[j][column]='W';
                else
                    break;
            }
        }
    }
    numBlack=0;
    for(i=column+1;i<8;i++){
        if(board[row][i]=='B'){
            numBlack++;
        }

        if((board[row][i] =='W')&& (numBlack>=1)){
            for(q=column+1;q<8;q++)
            {
                if(board[row][q]=='B')
                    board[row][q]='W';
                else
                    break;
            }
        }
    }
    numBlack=0;
    for(i=column-1;i>=0;i--){
        if(board[row][i]=='B'){
            numBlack++;
        }

        if((board[row][i] =='W')&& (numBlack>=1)){
            for(q=column-1;q>=0;q--)
            {
                if(board[row][q]=='B')
                    board[row][q]='W';
                else
                    break;
            }
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
            q = row-1; r = column-1;
            while(q>=0 && r>=0)
            {
                if(board[q][r]== 'B'){
                    board[q][r]='W';
                }
                else{
                    break;
                }
                q--; r--;
            }
        }
        i--;
        j--;
    }

    numBlack=0;
    i = row+1; j = column+1;
    while(i<8 && j<8)
    {
        if(board[i][j]=='B'){
            numBlack++;
        }
        if((board[i][j]=='W')&& (numBlack>=1)){
            q = row+1; r = column+1;
            while(q<8 && r<8)
            {
                if(board[q][r]=='B')
                    board[q][r]='W';
                else
                    break;
                q++; r++;
            }
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
            q = row+1; r = column-1;
            while(q<8 && r>=0)
            {
                if(board[q][r]=='B')
                    board[q][r]='W';
                else
                    break;
                q++; r--;
            }
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
            q = row-1; r = column+1;
            while(q>=0 && r<8)
            {
                if(board[q][r]=='B')
                    board[q][r]='W';
                else
                    break;
                q--; r++;
            }
        }
        i--; j++;
    }
}
