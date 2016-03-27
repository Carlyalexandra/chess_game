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
struct move getmove(char* player);
void initboard(piece board[8][8]);
int isvalidopen(char *entry, char*player);
int isvalidmove(char *start, char *end, char*player);
int legalpawn (char *start, char *end, char*player);
int legalrook (char *start, char *end, char*player);
int legalknight (char *start, char *end, char*player);
int legalbishop (char *start, char *end, char*player);
int legalqueen (char *start, char *end, char*player);
int legalking (char *start, char *end, char*player);
void makemove(move v);

#endif
