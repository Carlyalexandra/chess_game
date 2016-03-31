#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



extern piece board[8][8];
extern char white;
extern char black;




 

int main()
{
	move v;
	initboard(board);
	printboard(board);
	v = getmove();
	makemove(v);


}
