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