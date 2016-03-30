#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "chess.h"

//declare the global board
piece board[8][8];
int c = 0; //use this as counter used for displaying who's turn it is -- white or black.
char start[6];
char end[6];



// initiates the board and fills in all the nodes into the array.
void initboard(board);
void printboard(board);
void printletters();

//gets the player's move and returns the move node with all the information
move getmove(char* player)
{
    move a;
    printf("It's your turn, %s, what piece would you like to move?\nEnter the letter followed by the number. Enter Q to forfeit:\n", player);
    scanf("%s", start);


    while (isvalidopen(player) == 1)
    {
        printf("It's your turn, %s, what piece would you like to move?\nEnter the letter followed by the number. Enter Q to forfeit:\n", player);
        scanf("%s", start);
    }
    if((strcmp(start, "q") == 0) || (strcmp(start, "Q") == 0)) {
        printf("looks like you quit\n");
        exit(0);
    }

    printf("Where you would like to move to? Enter the letter followed by the number.\nEnter Q to forfeit or R to selected a different piece:\n");
    scanf("%s", end);


    if((strcmp(end, "r") == 0) || (strcmp(end, "R") == 0)) {
        printf("What piece would you like to move? Enter letter then number\n");
        scanf("%s", start);
        end = 0;
    }

    while (isvalidmove(player) == 1)
    {
        printf("Where you would like to move to? Enter the letter followed by the number.\nEnter Q to forfeit or R to selected a different piece:\n");
        scanf("%s", end);
    }
    if((strcmp(end, "q") == 0) || (strcmp(end, "Q") == 0)) {
        printf("looks like you quit\n");
        exit(0);
    }

    else {
        a.froml = start[0];
        a.fromi = start[1]-48;
        a.tol = end[0];
        a.toi = end[1]-48;
    }

    return a;
}


//checks to see if entry for the piece to move was valid and if the selected piece is that player's piece
int isvalidopen(char*player)
{
    char d = start[0];
    int m = start[1]-48;
    char *letters = "abcdefgh";
    if((strcmp(start, "q") == 0) || (strcmp(start, "Q") == 0)) {
        return 0;
    }
    else if (strchr(letters, start[0]) == NULL  && start[0] != 'q' && start[0] != 'Q') {
        printf("ERROR: please enter a letter between a-h.\n");
        return 1;
    }
        //checks to see if the second entry is 0 or 9 -- both are invalid.
    else if(start[1]== 48 || start[1] == 57) {
        printf("ERROR: please enter a number between 1-9.\n");
        return 1;
    }
    else if (strlen(start)>2) {
        printf("ERROR: please enter only one letter and one number.\n");
        return 1;
    }
    else if (board[8-m][d-'a'].color != tolower(player[0]) && start[0] != 'q' && start[0] != 'Q'){
        printf("ERROR: please move your own piece.\n");
        return 1;
    }
    return 0;
}



//checks to see if the move is valid... needs a lot more rules.
int isvalidmove(char *start, char *end, char*player) {
    char d = start[0];
    int m = start[1] - 48;
    char e = end[0];
    int n = end[1] - 48;
    char *letters = "abcdefgh";
    if ((strcmp(end, "q") == 0) || (strcmp(end, "Q") == 0)) {
        return 0;
    }
    else if (strchr(letters, end[0]) == NULL && end[0] != 'q' && end[0] != 'Q') {
        printf("ERROR: please enter a letter between a-h.\n");
        return 1;
    }
    else if (end[1] == 48 || end[1] == 57) {
        printf("ERROR: please enter a number between 1-9.\n");
        return 1;
    }
    else if (strlen(end) > 2) {
        printf("ERROR: please enter only one letter and one number.\n");
        return 1;
    }
    else if ((d == e) && (m == n)) {
        printf("ERROR: cant pick the space you are already on.\n");
        return 1;
    }
}