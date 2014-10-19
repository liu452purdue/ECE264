#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int startpoint(char **maze, int w, int h)
{
	int i = 0；
	char *row1 = maze[0]; // the entry is in the first row 
    for (i = 0; i < w; ++i)
    {
          if (row1[i] == ' ')
          {
          	return i;
          }
    }
    return -1;
}   

void buffer(char dirction)
{
	static char dirbuff = 'S'; // record the dirction to go
	static int dirlen = 0; // record how many steps have been done in this dirction

	if (dirbuff == dirction)
	{

		dirlen++;
	}
	else
	{
		printf("%c %d\n",dirbuff, dirlen );
		dirbuff = dirction;
		dirlen = 1;
	}
}

void travelrecursion(char **maze， int w, int h, int x, int y, int prx, int pry)
{
	/*x = current position in x - axis
	  y = current position in y - axis
	  prx = previous postion in x
	  pry = previous postion in y*/
    int ntx;
    int nty;
    char dirction;
}