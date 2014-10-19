#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _DEBUG = 0;

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

void printMaze(char ** maze , int h , int x , int y)
{
    int i;
    fgetc(stdin);
    maze[y][x] = 'o';
   
    printf("\e[1;1H\e[2J");
    for(i=0;i<h;i++){
        printf("%s\n", maze[i]);
    }
    maze[y][x] = ' ';
}


void travelcheck(char **maze , int w , int h ,int x , int y , int prx , int pry ,int ntx , int nty , char direction)
{
    if((w > ntx) && (ntx >= 0) && (h > nty) && (nty >= 0) &&!((ntx==prx) && (nty==pry)) && (maze[nty][ntx]==SPACE))     
    {
        buffer(direction);
        if(_DEBUG)
        {
            printMaze(maze , w , ntx , nty);
        }
        travelrecursion(maze, w, h, ntx, nty, x, y);
        buffer(turnback(direction));
        if(_DEBUG)
        {
            printMaze(maze , w , ntx , nty);

        }
    }
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
    travelcheck(maze ,w ,h ,x ,y ,prx ,pry ,ntx ,nty ,direction);
    
    
    direction = 'W';
    ntx = x -1;
    nty = y;
 	 travelcheck(maze ,w ,h ,x ,y ,prx ,pry ,ntx ,nty ,direction);

    direction = 'S';
    ntx = x;
    nty = y +1;
 	 travelcheck(maze ,w ,h ,x ,y ,prx ,pry ,ntx ,nty ,direction);

    direction = 'N';
    ntx = x;
    nty = y-1;
 	 travelcheck(maze ,w ,h ,x ,y ,prx ,pry ,ntx ,nty ,direction);
  }  




void print_directions(char** maze, int w, int h)
{
	int start = startpoint(maze,w,h);
	if(start==-1)
	{
		printf("no start found for first line\n%s\n" , maze[0]);
		return;
	}
	
		travelrecursion(maze , w , h , start , 0 , -1 , -1);
		buffer(' ');
}

