#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const **argv)
{
	int i = 1;

	for (i = 1; i < argc ; i++)
	{
		printf("%s ",argv[i]);
	}
	printf("\n");	

	return (EXIT_SUCCESS);
}