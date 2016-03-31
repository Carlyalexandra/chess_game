#include <stdio.h>

#ifndef CHESS_H
#define CHESS_H





typedef struct piece
{
   char color;
   char piece;
} piece; 

typedef struct move
{
   char froml;
   int fromi;
   char tol;
   int toi;
} move;

void printletters();
void printboard(piece board[8][8]);
struct move getmove();
void initboard(piece board[8][8]);
int isvalidopen(char*player);
int isvalidmove(char*player);
int legalpawn (char*player);
int legalrook (char*player);
int legalknight (char*player);
int legalbishop (char*player);
int legalqueen (char*player);
int legalking (char*player);
void makemove(move v);
void swappiece(char*player);
int check(char*player);
int castling(char*player);


#endif
