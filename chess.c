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
		printf("Not a valid entry\n");
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
		printf("Not a valid entry\n");
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
		return 1;
	}
	if (strlen(entry)>2)
	{
		return 1;
	}
	if (board[8-m][d-'a'].color != player[0] && entry[0] != 'q' && entry[0] != 'Q')
	{
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
		return 1;
	}
	if(end[1]== 48 || end[1] == 57) //checks to see if the second entry is 0 or 9 -- both are invalid.
	{
		return 1;
	}
	if (strlen(end)>2)
	{
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
        printf("this is the value of ret: %d\n", ret);
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

//check for the pawn
int legalpawn (char *start, char *end, char*player) {
    int a = 0;
    char d = start[0];
    int m = start[1] - 48;
    char e = end[0];
    int n = end[1] - 48;
    int p;
    if (c % 2 == 0)  // evaluates to see who's move it is.
    {
        p = 1; //player is black
    }
    else {
        p = 2; //player is white
    }

    if (p == 1) {
        if (n < m) { // checks to see if the move is going backwards, returns an error.
            a = 1;
        }
        if (d == e){ //makes sure the pawn doesn't move into the space in front of it if there is a piece there.
            if(board[8 - n][e - 'a'].color != 0){
                a = 1;
            }
        }
        if (abs(n - m) > 1) { //if the move is two spaces, the pawn has to be in the opening position
            if (m != 2) {
                a = 1;
            }
            if (abs(n-m) >2){
                a = 1;
            }
        }
        if (d != e) { // checks to see if moving diagonally is a valid move.
            if (abs(e - d) > 1) {
                a = 1;
            }
            else {
                if (board[8 - n][e - 'a'].color != 0) {
                    if ((board[8 - n][e - 'a'].color == 'b') && (e-d)==1){
                        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken if one was taken
                    }
                    if (board[8 - n][e - 'a'].color == 'w') {
                        a = 1;
                    }
                }
                else{
                    a = 1;
                }
            }
        }
    }
    if (p == 2) {
        if (n > m) { // if the move is going backwards, its an error.
            a = 1;
        }
        if (d == e){ //makes sure the pawn doesn't move into the space in front of it if there is a piece there.
            if(board[8 - n][e - 'a'].color != 0){
                a = 1;
            }
        }
        if (abs(n - m) > 1) { //if the move is two spaces, the pawn has to be in the opening position.
            if (m != 7) {
                a = 1;
            }
            if(abs(n-m)>2){
                a =1;
            }
        }
        if (d != e) { // checks to see if moving diagonally is a valid move.
            if (abs(e - d) > 1) {
                a = 1;
            }
            else {
                if (board[8 - n][e - 'a'].color != 0) {
                    if ((board[8 - n][e - 'a'].color == 'w') && (e-d)==1){
                        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken if one was taken
                    }
                    if (board[8 - n][e - 'a'].color == 'b') {
                        a = 1;
                    }
                }
                else{
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

//check for the rook
int legalrook (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1]-48;
	char e = end[0];
	int n = end[1]-48;
	int p;

	if(d != e)
	{
		a = 1;
	}
	else 
	{		
		printf("%s moved a ROOK to %c-%d\n",player,e,n);
	}
	return a;
}

//check for the knight
int legalknight (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0]-'a';
	int m = start[1]-48;
	char e = end[0]-'a';
	int n = end[1]-48;

	if((abs(n-m)==2 && abs(e-d) == 1) || (abs(n-m)==1 && abs(e-d)== 2))
	{	
		if(board[8-n][e-'a'].color == 0)	
		{		
			printf("%s moved a KNIGHT to %c-%d\n",player, e+'a',n);
		}
	}
	else 
	{
		a = 1;
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
	if(d != e)
	{
		a = 1;
	}
	else 
	{		
		printf("%s moved a QUEEN to %c-%d\n",player,e,n);
	}
	return a;
}

//check for the king
int legalking (char *start, char *end, char*player)
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
		printf("%s moved a KING to %c-%d\n",player, e,n);
	}
	return a;
}



