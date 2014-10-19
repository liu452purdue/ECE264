#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int startpoint(char **maze, int w, int h)
{
	int i = 0;
	char *firstrow = maze[0]; // the entry is in the first row 
    for (i = 0; i < w; ++i)
    {
          if (firstrow[i] == ' ')
          {
          	return i;
          }
    }
    return -1;
}   

void buffer(char direction)
{
	static char dirbuff = 'S'; // record the direction to go
	static int dirlen = 0; // record how many steps have been done in this direction

	if (dirbuff == direction)
	{

		dirlen++;
	}
	else
	{
		printf("%c %d\n",dirbuff, dirlen );
		dirbuff = direction;
		dirlen = 1;
	}
}

char turnback(char direction)
{
    if(direction=='W')
    {
        return 'E';
    }
    else if(direction=='E')
    {
        return 'W';
    }
    else if(direction=='N')
    {
        return 'S';
    }
    else if(direction=='S')
    {
        return 'N';
    }
    return '?';
}

void travelrecursion(char **maze, int w, int h, int x, int y, int prx, int pry)
{
	/*x = current position in x - axis
	  y = current position in y - axis
	  prx = previous postion in x
	  pry = previous postion in y*/
    int ntx;
    int nty;
    char direction;
    
    direction = 'E';
    ntx = x + 1;
    nty = y;
    if((w > ntx) && (ntx >= 0) && (h > nty) && (nty >= 0) &&!((ntx==prx) && (nty==pry)) && (maze[nty][ntx]==' '))		
    {
    	buffer(direction);
        travelrecursion(maze, w, h, x, y, prx, pry);
        buffer(turnback(direction));
    }
    
    direction = 'W';
    ntx = x -1;
    nty = y;
 	if((w > ntx) && (ntx >= 0) && (h > nty) && (nty >= 0) &&!((ntx==prx) && (nty==pry)) && (maze[nty][ntx]==' '))		
    {

        buffer(direction);
        travelrecursion(maze, w, h, x, y, prx, pry);
        buffer(turnback(direction));
    }

    direction = 'S';
    ntx = x;
    nty = y +1;
 	if((w > ntx) && (ntx >= 0) && (h > nty) && (nty >= 0) &&!((ntx==prx) && (nty==pry)) && (maze[nty][ntx]==' '))		
    {
    
        buffer(direction);
        travelrecursion(maze, w, h, x, y, prx, pry);
        buffer(turnback(direction));
    }

    direction = 'N';
    ntx = x;
    nty = y-1;
 	if((w > ntx) && (ntx >= 0) && (h > nty) && (nty >= 0) &&!((ntx==prx) && (nty==pry)) && (maze[nty][ntx]==' '))		
    {
        buffer(direction);
        travelrecursion(maze, w, h, x, y, prx, pry);
        buffer(turnback(direction));
    }
  }  




void print_directions(char** maze, int w, int h)
{
	int start;
	start = startpoint(maze,w,h);
	if(start==-1)
	{
		printf("no start found for first line\n%s\n" , maze[0]);
		return;
	}
	else
	{
		travelrecursion(maze , w , h , start , 0 , -1 , -1);
		buffer(' ');
 	}

}

