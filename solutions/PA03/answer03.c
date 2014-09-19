#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"



char * strcat_ex(char * * dest, int * n, const char * src)
 {
 	char *store;

 	if (src == NULL)
 	{
 		return (*dest);
 	}

 	else if (*dest == NULL || *n <= strlen(*dest) + strlen(src))
 	{
 		if (*dest != NULL )
 		{
 			*n = 1 + 2 * (strlen(*dest) + strlen(src));

 			store  = malloc(sizeof(char*)*(1+2 * (strlen(*dest) + strlen(src))));
 			
 			strcpy(store,*dest);

 			free(*dest);

 			*dest = store;

 			strcat(*dest,src);
 		}
 		else if(*dest == NULL)
 		{
            *n = (1 +2*(strlen(src)));

            store = malloc(sizeof(char*)*(1 + 2 * strlen(src)));

            *dest  = store;

            strcpy(*dest,src);
 		}

 	}

 	else
 	{
 		strcat(*dest,src);
 	}

 	return(*dest);
 }







char * * explode(const char * str, const char * delims, int * arrLen)
{
	int ind1 = 0;
	
	
    
	int size = strlen(str);

	int numrow = 0; 


	for (ind1 = 0; ind1 < size; ind1++)
	{
		if (strchr(delims,str[ind1]) != NULL)
		{
			numrow++;
		}
		
	}

    char ** arr1 =  (char **)malloc(sizeof(char **)*(numrow + 1));

    int row = 0;

    int ind2 = 0;

    int pointer = 0;

    int counter = 0;



    for(row =0; row <= size; row ++)
    {
   
     if ((strchr(delims,str[row]) == NULL) &&  (str[row] != '\0'))
     {

      counter ++;
     }
     else
      {
        
        arr1[ind2] = (char*)malloc(sizeof(char*)*(1+counter));
        memcpy(arr1[ind2],(str+pointer),counter);
        arr1[ind2][counter] = '\0';
        ind2++;
        pointer = row +1 ;
        counter = 0;
      }
    }

   *arrLen = numrow + 1; 



    return arr1;
}
/*
int main()
{
  char*str = "The\nturing Test";
  const char * delims = "\n ";
  int n;
  char * * strArr = explode(str, delims, &n);
  
  int ii = 0;
  
  for(ii=0;ii<3;ii++)
  {
    printf("s%sa\n",strArr[ii] );
  }
  return 0;
}
*/


char * implode(char * * strArr, int len, const char * glue)
{

  int ind = 0;
  int size = 0;
  char *string = NULL;


  for (ind = 0; ind < len-1; ind ++)
  {
  	strcat_ex(&string,&size,strArr[ind]);

  	
  		strcat_ex(&string,&size,glue);
  	
  }

  strcat_ex(&string,&size,strArr[ind]);

  return(string);
}


void sortStringArray(char * * arrString, int len)
{


  int compare(const void *a, const void *b)
{
  return strcmp(*(char **)a ,*(char **)b);
}


	qsort(arrString,len,sizeof(char*),compare);
}




void sortStringCharacters(char * str)
{

int compare2(const void *a, const void *b)
{
  return (*(char*)a - *(char*)b);
}
  int length = strlen(str);

    qsort(str,length,sizeof(char),compare2);
}



void destroyStringArray(char * * strArr, int len)
{
  int ii = 0;
  
  if (strArr == NULL)
  {
    return;
  }

  for (ii = 0; ii < len; ii++ )
   {
     
       free(strArr[ii]);
     
   }
   free(strArr);
}


