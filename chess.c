#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chess.h"

//declare the global board
piece board[8][8];
int c = 0; //use this as counter used for displaying who's turn it is -- white or black. 



// initiates the board and fills in all the nodes into the array.
void initboard(piece board[8][8])
{
	piece wPawn;
	wPawn.color = 'w';
	wPawn.piece = 'P';
	piece bPawn;
	bPawn.color = 'b';
	bPawn.piece = 'P';
	
	piece wRook;
	wRook.color = 'w';
	wRook.piece = 'R';
	piece bRook;
	bRook.color = 'b';
	bRook.piece = 'R';
	
	piece wkNight;
	wkNight.color = 'w';
	wkNight.piece = 'N';
	piece bkNight;
	bkNight.color = 'b';
	bkNight.piece = 'N';

	piece wBishop;
	wBishop.color = 'w';
	wBishop.piece = 'B';
	piece bBishop;
	bBishop.color = 'b';
	bBishop.piece = 'B';
	
	piece wQueen;
	wQueen.color = 'w';
	wQueen.piece = 'Q';
	piece bQueen;
	bQueen.color = 'b';
	bQueen.piece = 'Q';
	
	piece wKing;
	wKing.color = 'w';
	wKing.piece = 'K';
	piece bKing;
	bKing.color = 'b';
	bKing.piece = 'K';

	int j;
	for(j=0;j<8;j++)
	{			
		board[6][j] = wPawn;	
		board[1][j] = bPawn;	
	}
	
	board[0][0] = bRook;
	board[0][7] = bRook;
	board[7][0] = wRook;
	board[7][7] = wRook;

	board[0][1] = bkNight;
	board[0][6] = bkNight;
	board[7][1] = wkNight;
	board[7][6] = wkNight;

	board[0][2] = bBishop;
	board[0][5] = bBishop;
	board[7][2] = wBishop;
	board[7][5] = wBishop;

	board[0][3] = bQueen;
	board[7][3] = wQueen;

	board[0][4] = bKing;
	board[7][4] = wKing;
}


//prints the board, maintaining the spacing.

void printboard(piece board[8][8])
{
	printletters();
	printf("\n");
	int i;
	int j;
	int k = 8;
	for(i=0;i<8;i++)
	{
		printf(" %d  ",k);
		for(j=0;j<8;j++)
			if(board[i][j].color != 0)
			{
				
				printf(" %c-%c", board[i][j].color,board[i][j].piece);
				printf("    ");
			}
			else
			{
				printf("  - ");
				printf("    ");
			}
		printf(" %d ",k);
		printf("\n");
		printf("\n");
		k--;		
	}
	printletters();
}

//adds the boarder of letters to the top and the bottom of the board as a guide
void printletters()
{
	int i;
	printf("   ");
    for(i=0;i<8;i++)
    {
        printf("   %c    ",'a'+i);
    }
    printf("\n");
}

//gets the player's move and returns the move node with all the information
move getmove(char* player)
{	
	char start[6];
	char end[6];
	move a;
	printf("It's your turn, %s, what piece would you like to move?\nPlease enter the coordinates, with the letter followed by the number or if you wish to forfeit simply enter Q:\n", player);
	scanf("%s", start);
	while (isvalidopen(start, player) == 1)
	{
		printf("It's your turn, %s, what piece would you like to move?\nPlease enter the coordinates, with the letter followed by the number or if you wish to forfeit simply enter Q:\n", player);
		scanf("%s", start);
        if((strcmp(start, "q") == 0) || (strcmp(start, "Q") == 0))
        {
            printf("looks like you quit\n");
            exit(0);
        }
	}
	if((strcmp(start, "q") == 0) || (strcmp(start, "Q") == 0))
	{	
		printf("looks like you quit\n");
		exit(0);
	}
	else
	{	
		a.froml = start[0];
		a.fromi = start[1]-48;
	}

    printf("Please enter the coordinates of where you would like to move to, with the letter followed by the number\nor if you wish to forfeit simply enter Q:\n");
 	scanf("%s", end);
	while (isvalidmove(start, end, player) == 1)
	{
		printf("Please enter the coordinates of where you would like to move to, with the letter followed by the number\nor if you wish to forfeit simply enter Q:\n");
        scanf("%s", end);
        if((strcmp(end, "q") == 0) || (strcmp(end, "Q") == 0))
        {
            printf("looks like you quit\n"); // right now I it quits the program but I need to figure out how to get it drop the first choice
            exit(0);
        }
	}
	if((strcmp(end, "q") == 0) || (strcmp(end, "Q") == 0))
 	{	
		printf("looks like you quit\n");
		exit(0);
	}
 	else
 	{
 		a.tol = end[0];
 		a.toi = end[1]-48;
 	}

 	return a;
}



//checks to see if entry for the piece to move was valid and if the selected piece is that player's piece
int isvalidopen(char *entry, char*player)
{	
	char d = entry[0];
	int m = entry[1]-48;
	char *letters = "abcdefgh";
	if (strchr(letters, entry[0]) == NULL  && entry[0] != 'q' && entry[0] != 'Q')
	{
		printf("ERROR: please enter a letter between a-h.\n");
        return 1;
	}
    if(entry[1]== 48 || entry[1] == 57) //checks to see if the second entry is 0 or 9 -- both are invalid.
    {
        printf("ERROR: please enter a number between 1-9.\n");
        return 1;
    }
	if (strlen(entry)>2)
	{
        printf("ERROR: please enter only one letter and one number.\n");
		return 1;
	}
	if (board[8-m][d-'a'].color != player[0] && entry[0] != 'q' && entry[0] != 'Q')
	{
        printf("ERROR: please move your piece, not your opponents.\n");
		return 1;
	}
	return 0;
}

//checks to see if the move is valid... needs a lot more rules.
int isvalidmove(char *start, char *end, char*player)
{	
	char d = start[0];
	int m = start[1]-48;
	char *letters = "abcdefgh";
	if (strchr(letters, end[0]) == NULL  && end[0] != 'q' && end[0] != 'Q')
	{
        printf("ERROR: please enter a letter between a-h.\n");
		return 1;
	}
	if(end[1]== 48 || end[1] == 57) //checks to see if the second entry is 0 or 9 -- both are invalid.
	{
        printf("ERROR: please enter a number between 1-9.\n");
		return 1;
	}
	if (strlen(end)>2)
	{
        printf("ERROR: please enter only one letter and one number.\n");
		return 1;
	}
	if(board[8-m][d-'a'].piece == 'P') //checks pawn moves.
	{
		int ret;
		ret = legalpawn(start, end, player);
		return ret;
	}
	if(board[8-m][d-'a'].piece == 'R') //checks rooks moves.
	{	
		int ret;
		ret = legalrook(start, end,player);
		return ret;
	}
	if(board[8-m][d-'a'].piece == 'N') //checks knights moves.
	{
		int ret;
		ret = legalknight(start, end, player);
		return ret;
	}
	if(board[8-m][d-'a'].piece == 'B') //checks bishops moves.
	{	
		int ret;
		ret = legalbishop(start, end, player);
		return ret;
	}
	if(board[8-m][d-'a'].piece == 'Q') //checks queens moves.
	{
		int ret;
		ret = legalqueen(start, end, player);
		return ret;
	}
	if(board[8-m][d-'a'].piece == 'K') //checks kings moves.
	{
		int ret;
		ret = legalking(start, end, player);
		return ret;
	}
	return 0;
}

//takes the move that is entered and makes the actual move on the board.
void makemove(move v)
{
	char* player;
	if (c % 2 == 0)  // evaluates to see who's move it is.
	{
		player ="black";
	}
	else
	{
		player = "white";
	}
	char d = v.froml;
	int m = v.fromi;
	char e = v.tol;
	int n = v.toi;
	board[8-n][e-'a'].color = board[8-m][d-'a'].color;
	board[8-n][e-'a'].piece = board[8-m][d-'a'].piece;
	board[8-m][d-'a'].color = 0;
	board[8-m][d-'a'].piece = 0;
	printboard(board);
	c++; // progresses the counter to swap which player is playing
	move t;
	t = getmove(player);
	makemove(t);

}

// functions that check to see if the move is legal for that piece.

//check for the pawn -- DONE
int legalpawn (char *start, char *end, char*player) {
    int a = 0;
    char d = start[0];
    int m = start[1] - 48;
    char e = end[0];
    int n = end[1] - 48;
    int p;
    if (c % 2 == 0)  // evaluates to see who's move it is.
    {
        p = 1; //player is white tokens
    }
    else {
        p = 2; //player is black tokens
    }
//if its the white players turn....
    if (p == 1) {
        if (n < m) { // checks to see if the move is going backwards, returns an error.
            printf("ERROR: Pawns cannot move backwards.\n");
            a = 1;
        }
        if (d == e){ //makes sure the pawn doesn't move into the space in front of it if there is a piece there.
            if(board[8 - n][e - 'a'].color != 0){
                printf("ERROR: Another piece is already in that spot.\n");
                a = 1;
            }
        }
        if (abs(n - m) > 1) { //if the move is two spaces, the pawn has to be in the opening position
            if (m != 2) {
                printf("ERROR: Can only move two spaces on opening move.\n");
                a = 1;
            }
            if (abs(n-m) >2){
                printf("ERROR: Can only move one spaces.\n");
                a = 1;
            }
        }
        if (d != e) { // checks to see if moving diagonally is a valid move.
            if (abs(e - d) != 1) {
                printf("ERROR: Can only move diagonally when taking an opponent's piece.\n");
                a = 1;
            }
            if(m == n){
                a = 1;
                printf("ERROR: Pawns cannot move sideways.\n");
            }
            else {
                if (board[8 - n][e - 'a'].color != 0) {
                    if ((board[8 - n][e - 'a'].color == 'b') && (e-d)==1){
                        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken if one was taken
                    }
                    if (board[8 - n][e - 'a'].color == 'w') {
                        printf("ERROR: Pawns cannot capture it's own piece.\n");
                        a = 1;
                    }
                }
                else{
                    printf("ERROR: Can only move diagonally when taking an opponent's piece.\n");
                    a = 1;
                }
            }
        }
    }
    //if its the black players turn...
    if (p == 2) {
        if (n > m) { // if the move is going backwards, its an error.
            printf("ERROR: Pawns cannot move backwards.\n");
            a = 1;
        }
        if (d == e){ //makes sure the pawn doesn't move into the space in front of it if there is a piece there.
            if(board[8 - n][e - 'a'].color != 0){
                printf("ERROR: Another piece is already in that spot.\n");
                a = 1;
            }
        }
        if (abs(n - m) > 1) { //if the move is two spaces, the pawn has to be in the opening position.
            if (m != 7) {
                printf("ERROR: Can only move two spaces on opening move.\n");
                a = 1;
            }
            if(abs(n-m)>2){
                printf("ERROR: Can only move one spaces.\n");
                a =1;
            }
        }
        if (d != e) { // checks to see if moving diagonally is a valid move.
            if (abs(e - d) != 1) {
                printf("ERROR: Can only move diagonally when taking an opponent's piece.\n");
                a = 1;
            }
            if(m == n){
                printf("ERROR: Pawns cannot move sideways.\n");
                a = 1;
            }
            else {
                if (board[8 - n][e - 'a'].color != 0) {
                    if ((board[8 - n][e - 'a'].color == 'w') && (abs(e-d))==1){
                        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken if one was taken
                    }
                    if (board[8 - n][e - 'a'].color == 'b') {
                        printf("ERROR: Pawns cannot capture it's own piece.\n");
                        a = 1;
                    }
                }
                else{
                    printf("ERROR: Can only move diagonally when taking an opponent's piece.\n");
                    a = 1;
                }
            }
        }
    }
    if ( a == 0 && d==e ){
        printf("%s moved a PAWN to %c-%d\n", player, e, n); //prints the move if no piece was taken.
    }
    return a;
}

//check for the rook - DONEish.
int legalrook (char *start, char *end, char*player)
{
    int a = 0;
    char d = start[0];
    int m = start[1];
    char e = end[0];
    int n = end[1];
    if((d != e) && (m != n)){ //makes sure the move is only horizontal or vertical
        printf("ERROR: can only move horizontally or vertically.\n");
        a = 1;
    }
    if((d==e) && (m==n)){
        printf("ERROR: cant pick the space you are already on.\n");
        a = 1;
    }
    if(d == e) { // makes sure there are no other pieces in the way vertically.
        int q = m - 48;
        if (m > n) {
            for (; q > n-47;) {
                q--;
                if (board[8-q][d-'a'].piece != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }

            }
        }
        if (n > m) {
            for (; q < n-m;) {
                q++;
                if (board[8-q][d-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }
            }
        }
    }
    if( m == n) { // makes sure there are no pieces in the way horizontally.
        char q = d;
        if (d > e) {
            for (; q > e+1;) {
                q--;
                if (board[56-m][q-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    printf("THis is Q%d",q);
                    a = 1;
                    break;
                }
            }
        }
        if (e > d) {
            for (; q-'a' < e-d;) {
                q++;
                if (board[56-m][q-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }
            }
        }
    }

    if (board[56-n][e-'a'].color == player[0]){
        printf("ERROR: cant take your own piece.\n");
        a = 1;
    }


    if(a == 0 ){
        printf("%s moved a ROOK to %c-%d\n",player,e,n-48);
    }
    else{ // need to figure out the conditional.
        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken.
    }
	return a;
}

//check for the knight -- DONE
int legalknight (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1];
	char e = end[0];
	int n = end[1];

	if((abs(n-m)==2 && abs(e-d) == 1) || (abs(n-m)==1 && abs(e-d)== 2))
	{	
		if(board[56-n][e-'a'].color == 0)
		{		
			printf("%s moved a KNIGHT to %c-%d\n",player, e,n-48);
		}
	}
	else 
	{
        printf("ERROR: Knight can only move one space up two spaces over or two spaces up one space over.\n");
		a = 1;
	}
    if(board[56-n][e-'a'].color != 0){
        if(board[56-n][e-'a'].color == player[0]){
            printf("ERROR: Knight can take it's own piece.\n");
            a = 1;
        }
        else{
            printf("%s took %c-%c!!!\n", player, board[56-n][e - 'a'].color, board[56-n][e - 'a'].piece);
        }
    }
	return a;
}

//check for the bishop
int legalbishop (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1]-48;
	char e = end[0];
	int n = end[1]-48;
	if(d != e)
	{
		a = 1;
	}
	else 
	{		
		printf("%s moved a BISHOP to %c-%d\n",player,e,n);
	}
	return a;
}

//check for the queen
int legalqueen (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1]-48;
	char e = end[0];
	int n = end[1]-48;


    //checks to make sure not moving on the space the piece is already on.
    if((d==e) && (m==n)){
        printf("ERROR: cant pick the space you are already on.\n");
        a = 1;
    }
    //checks to make sure there are no pieces horizontally or vertically in the way.

    if(d == e) { // makes sure there are no other pieces in the way vertically.
        int q = m - 48;
        if (m > n) {
            for (; q > n-47;) {
                q--;
                if (board[8-q][d-'a'].piece != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }

            }
        }
        if (n > m) {
            for (; q < n-m;) {
                q++;
                if (board[8-q][d-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }
            }
        }
    }
    if( m == n) { // makes sure there are no other pieces in the way horizontally.
        char q = d;
        if (d > e) {
            for (; q > e+1;) {
                q--;
                if (board[56-m][q-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    printf("THis is Q%d",q);
                    a = 1;
                    break;
                }
            }
        }
        if (e > d) {
            for (; q-'a' < e-d;) {
                q++;
                if (board[56-m][q-'a'].color != 0) {
                    printf("ERROR: cant move if pieces are along the path on.\n");
                    a = 1;
                    break;
                }
            }
        }
    }


	return a;
}

//check for the king DONE
int legalking (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1];
	char e = end[0];
	int n = end[1];
	if(abs(d-e)!= 1 && abs(m-n)!=1){ //setting it so the king can only move one space -- still have to make it so it can't put itself into check and can castle
        printf("ERROR: King can only move one space.\n");
        a = 1;
    }
    if(board[56-n][e-'a'].color != 0){
        if(board[56-n][e-'a'].color == player[0]){ //only allows for the king to take opponent's piece and not it's own.
            printf("ERROR: Knight can take it's own piece.\n");
            a = 1;
        }
        else{
            printf("%s took %c-%c!!!\n", player, board[56-n][e - 'a'].color, board[56-n][e - 'a'].piece);
        }
    }

	return a;
}



