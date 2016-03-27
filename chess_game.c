#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



extern piece board[8][8];
extern char white;
extern char black;




 

int main()
{
	char *player = "white"; 
	move v;
	initboard(board);
	printboard(board);
	v = getmove(player);
	// while
	// {
		makemove(v);
	// }

}
//to call a space on the board it's letter minus a, 8 minus number
