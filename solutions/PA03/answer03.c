#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"



/**
 * Append the C-string 'src' to the end of the C-string '*dest'.
 *
 * strcat_ex(...) will append the C-string 'src' to the end of the string
 * at '*dest'. The parameter 'n' is the address of a int that specifies how
 * many characters can safely be stored in '*dest'. 
 *
 * If '*dest' is NULL, or if '*dest' is not large enough to contain the result
 * (that is, the sum of the lengths of *dest, src, and the null byte), then
 * strcat_ex will:
 * (1) malloc a new buffer of size 1 + 2 * (strlen(*dest) + strlen(src))
 * (2) set '*n' to the size of the new buffer
 * (3) copy '*dest' into the beginning of the new buffer
 * (4) free the memory '*dest', and then set '*dest' to point to the new buffer
 * (5) concatenate 'src' onto the end of '*dest'.
 *
 * Always returns *dest.
 *
 * Why do we need to pass dest as char * *, and n as int *? 
 * Please see the FAQ for an answer.
 *
 * Hint: These <string.h> functions will help: strcat, strcpy, strlen.
 * Hint: Leak no memory.
*/
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
















/**
 * Takes a string and splits it into an array of strings according to delimiter.
 * The memory location '*arrLen' is initialized to the length of the returned
 * array.
 *
 * str: A string to split
 * delims: a string that contains a set of delimiter characters. explode(...) 
 *         will split the string at any character that appears in 'delims'.
 * arrLen: pointer to an int that is used to store the resultant length of the
 *         returned array.
 *
 * For example, if delimiter is white space " \t\v\n\r\f", then,
 * int len;
 * char * * strArr = explode("The\nTuring test", " \t\v\n\r\f", &len);
 * // len = 3, strArr[0] is "The", strArr[1] is "Turing", strArr[2] is "test"
 *
 * Hint: you can use <string.h> functions "memcpy" and "strchr"
 *       "memcpy" copies blocks of memory.
 *       "strchr" can be used to tell if a specific character is in delims.
 * Hint: this question is hard; it will help to draw out your algorithm.
 * Hint: read the FAQ...
 */

char * * explode(const char * str, const char * delims, int * arrLen);
{
	int ind1 = 0;
	
	int row = 0;
    
	int size = strlen(str);

	int numrow = 0; 

	int **arr1;

	for (int ind1 = 0; ind1 < size; ind1++)
	{
		if (strchr(delims,str[ind1]) != NULL)
		{
			numrow++;
		}
		
	}

    char ** arr1 =  (char **)malloc(sizeof(char **)*(numrow + 1));

    
    int ind2 = 0;

    int pointer = 0;



    for (row = 0; row <= size; row++)
    {
    	if (str[row] =='\0' || strchr(delims,str[row]) != NULL)
    	{
    		arr1[ind2] =(char *) malloc(sizeof(char*)*(row - pointer + 1));

    		memcpy(arr1[ind2],&str[pointer],row - pointer);

    		pointer =  row + 1;

    		arr1[ind2][row - pointer] = '\0';

    		ind2 ++;
    	}
 

    }

    



    return arr1;
}

/**
 * Takes an array of strings, and concatenates the elements into a single
 * string, placing 'glue' between each successive element.
 *
 * strArr: an array of strings
 * len: the length of the array 'strArr'
 * glue: string to concatenate between each element of 'strArr'
 *
 * For example:
 * int len;
 * char * * strArr = explode("100 224 147 80", " ", &len);
 * char * str = implode(strArr, len, ", ");
 * printf("(%s)\n", str); // (100, 224, 147, 80)
 *
 * Hint: use strcat_ex in a for loop.
 */

char * implode(char * * strArr, int len, const char * glue);
{

  int ind = 0;
  int size = 0;
  char *string = NULL;

  for (int ind = 0; ind < len-1; ind ++)
  {
  	strcat_ex(&string,&size,strArr[ind]);

  	
  		strcat_ex(&string,&size,glue);
  	
  }

  strcat_ex(&string,&size,strArr[ind]);

  return(string);
}

/**
 * Takes an array of C-strings, and sorts them alphabetically, ascending.
 *
 * arrString: an array of strings
 * len: length of the array 'arrString'
 *
 * For example, 
 * int len;
 * char * * strArr = explode("lady beatle brew", " ", &len);
 * sortStringArray(strArr, len);
 * char * str = implode(strArr, len, " ");
 * printf("%s\n"); // beatle brew lady
 *
 * Hint: use the <stdlib.h> function "qsort"
 * Hint: you must _clearly_ understand the typecasts.
 */

void sortStringArray(char * * arrString, int len);
{
	qsort(arrString,len,sizeof(char*),compare);
}

int compare(const void *a, const void *b)
{
	return strcmp((char *)a ,(char *)b);
}
/**
 * Sorts the characters in a string.
 *
 * str: string whose characters are to be sorted
 *
 * For example, 
 * char * s1 = strdup("How did it get so late so soon?");
 * sortStringCharacters(s1)
 * // s1 is now "       ?Haddeegiilnooooossstttw"
 *
 * Hint: use the <stdlib.h> function "qsort"
 * Hint: you must _clearly_  understand the typecasts.
 */

void sortStringCharacters(char * str);
{
  int length = strlen(str);

    qsort(str,length,sizeof(char),compare2);
}

int compare2(const void *a, const void *b)
{
  return ((char)a - (char)b);
}
/**
 * Safely frees all memory associated with strArr, and then strArr itself.
 * Passing NULL as the first parameter has no effect.
 *
 * strArr: an array of strings
 * len: the length of 'strArr'
 *
 * int len;
 * const char * abe = "Give me six hours to chop down a tree and I will spend\n"
 *                    "the first four sharpening the axe.";
 * char * * strArr = explode(abe, "\n ");
 * destroyStringArray(strArr, len); // cleans memory -- no memory leaks
 * destroyStringArray(NULL, 0); // does nothing, does not crash.
 */

void destroyStringArray(char * * strArr, int len);
{
  int ii = 0;
  //int jj = 0;
  if (strArr == NULL)
  {
    return;
  }
  
  for (ii = 0; ii < len; ii++ )
   {
     free(strArr[ii]);
   }
}


