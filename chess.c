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
	for(i=0;i<8;i++) {
		printf(" %d  ",k);
		for(j=0;j<8;j++)
			if(board[i][j].color != 0) {
				
				printf(" %c-%c", board[i][j].color,board[i][j].piece);
				printf("    ");
			}
			else {
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
int isvalidmove(char*player)
{	
	char d = start[0];
	int m = start[1]-48;
    char e = end[0];
    int n = end[1]-48;
	char *letters = "abcdefgh";
    if((strcmp(end, "q") == 0) || (strcmp(end, "Q") == 0)) {
        return 0;
    }
	else if (strchr(letters, end[0]) == NULL  && end[0] != 'q' && end[0] != 'Q') {
        printf("ERROR: please enter a letter between a-h.\n");
		return 1;
	}
	else if(end[1]== 48 || end[1] == 57) {
        printf("ERROR: please enter a number between 1-9.\n");
		return 1;
	}
	else if (strlen(end)>2) {
        printf("ERROR: please enter only one letter and one number.\n");
		return 1;
	}
    else if((d==e) && (m==n)){
        printf("ERROR: cant pick the space you are already on.\n");
        return 1;
    }
    //checks pawn moves.
	else if(board[8-m][d-'a'].piece == 'P') {
		int ret;
		ret = legalpawn(start, end, player);
		return ret;
	}
    //checks rooks moves.
	else if(board[8-m][d-'a'].piece == 'R') {
		int ret;
		ret = legalrook(start, end,player);
		return ret;
	}
    //checks knights moves.
	else if(board[8-m][d-'a'].piece == 'N') {
		int ret;
		ret = legalknight(start, end, player);
		return ret;
	}
    //checks bishops moves.
	else if(board[8-m][d-'a'].piece == 'B') {
		int ret;
		ret = legalbishop(start, end, player);
		return ret;
	}
    //checks queens moves.
	else if(board[8-m][d-'a'].piece == 'Q') {
		int ret;
		ret = legalqueen(start, end, player);
		return ret;
	}
    //checks kings moves.
	else if(board[8-m][d-'a'].piece == 'K') {
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
    // evaluates to see who's move it is.
	if (c % 2 == 0) {
		player ="BLACK";
	}
	else {
		player = "WHITE";
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
int legalpawn (char *start, char *end, char*player) {
    int a = 0;
    char d = start[0];
    int m = start[1] - 48;
    char e = end[0];
    int n = end[1] - 48;
    int p;
    // evaluates to see who's move it is.
    if (c % 2 == 0) {
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
                printf("ERROR: Can only move one spaces.\n");
                a = 1;
            }
            if (abs(n-m) >2){
                printf("ERROR: Can only move one or two spaces on opening move.\n");
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
                printf("ERROR: Can only move one spaces.\n");
                a = 1;
            }
            if(abs(n-m)>2){
                printf("ERROR: Can only move one or two spaces on opening move.\n");
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


//check for the rook
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
    else if(d == e) { // makes sure there are no other pieces in the way vertically.
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

    if (board[56-n][e-'a'].color == tolower(player[0])){
        printf("ERROR: cant take your own piece.\n");
        a = 1;
    }


//    if(a == 0 ){
//        printf("%s moved a ROOK to %c-%d\n",player,e,n-48);
//    }
//    else{ // need to figure out the conditional.
//        printf("%s took %c-%c!!!\n", player, board[8 - n][e - 'a'].color, board[8 - n][e - 'a'].piece); //prints what piece was taken.
//    }
	return a;
}

//check for the knight
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
        if(board[56-n][e-'a'].color == tolower(player[0])){
            printf("ERROR: Knight can take it's own piece.\n");
            a = 1;
        }
//        else{
//            printf("%s took %c-%c!!!\n", player, board[56-n][e - 'a'].color, board[56-n][e - 'a'].piece);
//        }
    }
	return a;
}

//check for the bishop
int legalbishop (char *start, char *end, char*player)
{
	int a = 0;
	char x = start[0];
	int y = start[1];
	char x1 = end[0];
	int y1 = end[1];
    int i;

    //checks to make sure the line is diagonal.
    if((x==x1) || (y==y1)){
        printf("ERROR: must move diagonally.\n");
        a = 1;
    }

    //checks to make the slope of the line is \1\.
    else if(abs(x-x1) != abs(y-y1)){
        printf("ERROR: must be a straight diagonal line.\n");
        a = 1;
    }

    // if start is bigger letter and number (eg. h-7 to d-3) -- x1=x-i y1=y-i.
    if((x>x1)&&(y>y1)){
        for(i=1;i<y-y1;i++){
            if(board[56-(y-i)][(x-i)-'a'].color !=0){
                printf("ERROR: cant move if pieces are along the path on.\n");
                a = 1;
                break;
            }
        }
    }
// if start is bigger letter but smaller number(eg. h-1 to d-5) -- x1=x-i, y1=y+i.
    if((x>x1)&&(y<y1)){
        for(i=1;i<y1-y;i++){
            if(board[56-(y+i)][(x-i)-'a'].color !=0){
                printf("ERROR: cant move if pieces are along the path on.\n");
                a = 1;
                break;
            }
        }
    }

//if start is less than end letter and number(eg. a-1 to e-5) -- x1=x+i, y1=y+i.
    if((x<x1)&&(y<y1)){
        for(i=1;i<y1-y;i++){
            if(board[56-(y+i)][(x+i)-'a'].color !=0){
                printf("ERROR: cant move if pieces are along the path on.\n");
                a = 1;
                break;
            }
        }
    }


//if start is less than letter but bigger number (eg. a-7 to e-3) -- x1=x+i, y1= y-i.
    if((x<x1)&&(y>y1)){
        for(i=1;i<y-y1;i++){
            if(board[56-(y-i)][(x+i)-'a'].color !=0){
                printf("ERROR: cant move if pieces are along the path on.\n");
                a = 1;
                break;
            }
        }
    }
    if(board[56-y1][x1 -'a'].color != 0){
        if(board[56-y1][x1-'a'].color == tolower(player[0])){
            printf("ERROR: Can not take your own piece.\n");
            a = 1;
        }
    }

//    if(a == 0 ){
//        printf("%s moved a BISHOP to %c-%d\n",player,x1,y1-48);
//    }
	return a;
}

//check for the queen
int legalqueen (char *start, char *end, char*player)
{
	int a = 0;
	char d = start[0];
	int m = start[1];
	char e = end[0];
	int n = end[1];

    //if move is horizontally or vertically, checks to make sure move it legal.
    if((d==e) || (m==n)){
        a=legalrook(start, end, player);
    }
    //if move it diagnoal, checks to make sure move is legal.
    if((d != e) && (m != n)){
        a=legalbishop(start, end, player);
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
    else if(board[56-n][e-'a'].color != 0){
        if(board[56-n][e-'a'].color == tolower(player[0])){ //only allows for the king to take opponent's piece and not it's own.
            printf("ERROR: Knight can take it's own piece.\n");
            a = 1;
        }
        else{
            printf("%s took %c-%c!!!\n", player, board[56-n][e - 'a'].color, board[56-n][e - 'a'].piece);
        }
    }

	return a;
}

//int check(char*player){
//    int a = 0;
//    if (king is in check then the move has to used){
//        a = 1;
//    }
//
//    return a;
//}

