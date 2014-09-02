#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int ind;
  int sum = 0;
  
  for (ind = 0; ind < len; ind ++) 
    {
      sum += array[ind];
    }
   return sum;
}

int arrayCountNegative(int * array, int len)
{
  int cntind ;
  int entry;
  int negative = 0;
  for ( cntind = 0; cntind < len; cntind ++)
    {
      entry = array[cntind];
    if ( entry  < 0)
	
       negative ++ ;
    }
     
  return  negative;
}

int arrayIsIncreasing(int * array, int len)
{    
  int icrind;
  int result = 0;
  if ( len == 0 || len ==1 )
  {
    result = 1;
  }
  else 
    {
      for (icrind = 0; (icrind + 1) < len; icrind ++)
    {
    
      if (( array[icrind] <= array[icrind + 1]) ||( len == 0) )
        {
	  	  result = 1; 
        }
      else if (array[icrind] > array[icrind +1] )
	{
          result = 0; break;

        }      
    }    
    }	
     
   return result;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int Find;
  int Fresult = 0;
  if (len == 0)
    { 
      Fresult = -1;
    }
 else
   {
    for ( Find = 0; Find < len; Find ++ )
    {
      if ( haystack[Find] == needle )
	{ 
          Fresult = Find;
	}
      else if ( (Find == len || Find == 0) && haystack[Find] != needle )
	{
	  Fresult = -1;
	}
    }
   }
    return Fresult;
}

int arrayFindSmallest(int * array, int len)
{
  int Sind;
  int min;
  int result = 0;
  
  min = array[0];

  for (Sind = 0; Sind < len; Sind ++) 
    {
      if (min > array[Sind])
	{
	  min = array[Sind];
	  result = Sind;
        }
    }
return result;
}
