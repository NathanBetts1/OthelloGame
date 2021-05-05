//
// Created by Nathan Betts on 05/05/2021.
//

#ifndef OTHELLO_LOGIC_H
#define OTHELLO_LOGIC_H
int isValidWhite(char board[][8],int column,int row);
int isValidBlack(char board[][8],int column,int row);
int lettertoNum(char letter);

int isLegal(char board[][8],int column, int row);
#endif //OTHELLO_LOGIC_H
