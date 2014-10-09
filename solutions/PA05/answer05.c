#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Prints all the partitions of a positive integer value.
 *
 * Example:
 * partitionAll(3); // prints the following: (line order not important)
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 *
 * Note: Order does not matter, and neither does white-space. 
 * Hint: look at file: expected/partitionAll.output
 */
void f(int n, int*arr, int ind)
  {
   int i = 0;
   int j = 0;
   //printf("%d = ", n);
   if (n == 0)
   {
   printf("=");
     for (i = 0; i < ind -1; ++i)
     {
        printf("%d+",arr[i] ); 
     }
      printf("%d\n", arr[ind -1] );
      //return;
   }
     for (j = 1; j <= n; ++j)
     {
        
        arr[ind] = j;
        f(n-j,arr,ind +1);
     }
   
   return;
  }

void partitionAll(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f(value, arr, ind);
  free(arr);
  return;

}
/**
 * Prints all partitions that have strictly increasing values.
 *
 * Example:
 * partitionIncreasing(5); // prints the following: (line order not important)
 * = 1 + 4
 * = 2 + 3
 * = 5
 * 
 * These partitions are excluded because they are not _strictly_ increasing
 * 1 + 1 + 3
 * 2 + 1 + 2
 * 3 + 2
 * 
 * Note:
 * The program should generate only valid partitions.  Do not
 * generates all partitions and then filter for validity. If you 
 * do this, you will almost certainly have trouble understanding the exam.
 *
 * Hint: look at file: expected/partitionIncreasing.output
 */
void f1(int n, int*arr, int ind)
  {
   int i = 0;
   int j = 0;
   int incflag = 0;
   //printf("%d = ", n);
   if (n == 0)
   {
    for (i = 1; i < ind ; ++i)
    { 
      if (arr[i] <= arr[i-1])
      {
        incflag =1;
        //printf("%s\n","incflag = 1" );
      }
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
    }

  if (incflag == 0)
  {
   
   printf("= ");
     for (i = 0; i < ind -1; ++i)
     {
        printf("%d + ",arr[i] ); 
     }
      printf("%d\n", arr[ind -1] );
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
      //return;
    
    }
   }
     for (j = 1; j <= n; ++j)
     {
        
        arr[ind] = j;
        f1(n-j,arr,ind +1);
     }
   
   return;
  }



void partitionIncreasing(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f1(value, arr, ind);
  free(arr);
  return;
}


/**
 * Prints all partitions that have strictly decreasing values.
 *
 * Example:
 * partitionDecreasing(5); // prints the following: (line order not important)
 * = 3 + 2
 * = 4 + 1
 * = 5
 * 
 * These partitions are excluded because they are not _strictly_ decreasing
 * 1 + 1 + 3
 * 2 + 1 + 2
 * 
 * See: note on partitionIncreasing(...)
 * Hint: look at file: expected/partitionDecreasing.output
 */
void f2(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int Decflag=0;
   //printf("%d = ", n);
 if (n == 0)
 {
  for (i = 1; i < ind ; ++i)
  { 
    if (arr[i] >= arr[i-1])
    {
      Decflag =1;
        //printf("%s\n","incflag = 1" );
    }
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
  }

  if (Decflag == 0)
  {

   printf("= ");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
      //return;

}
}
for (j = 1; j <= n; ++j)
{

  arr[ind] = j;
  f2(n-j,arr,ind +1);
}

return;
}

void partitionDecreasing(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f2(value, arr, ind);
  free(arr);
  return;
}

/**
 * Prints all partitions comprised solely of odd numbers.
 *
 * Example:
 * partitionOdd(5); // prints the following (line order not important)
 * = 1 + 1 + 1 + 1 + 1
 * = 1 + 1 + 3
 * = 1 + 3 + 1
 * = 3 + 1 + 1
 * = 5
 * 
 * See: note on partitionIncreasing(...)
 * Hint: for odd numbers, (value % 2 != 0)
 * Hint: look at file: expected/partitionOdd.output
 */

 void f3(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int oddflag=1;
   //printf("%d = ", n);
 if (n == 0)
 {
  for (i = 0; i <= ind ; ++i)
  { 
    if ((arr[i] %2)==0)
    {
      oddflag =0;
        //printf("%s\n","incflag = 1" );
    }
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
  }

  if (oddflag == 1)
  {

   printf("= ");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );
     // printf("\t %d %d %d\n",arr[i],arr[i-1],(arr[i] <= arr[i-1]) );
      //return;

}
}
for (j = 1; j <= n; ++j)
{

  arr[ind] = j;
  f3(n-j,arr,ind +1);
}

return;
}
void partitionOdd(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f3(value, arr, ind);
  free(arr);
  return;
}
int main(int argc, char const *argv[])
{
 // partitionAll(4);
  partitionOdd(8);
  return 0;
}


/**
 * Prints all partitions comprised solely of even numbers.
 *
 * Example:
 * partitionEven(6); // prints the following (line order not important)
 * = 2 + 2 + 2
 * = 2 + 4
 * = 4 + 2
 * = 6
 * 
 * See: note on partitionIncreasing(...)
 * Hint: for even numbers, (value % 2 == 0)
 * Hint: you can never partition an odd number with even numbers alone.
 * Hint: look at file: expected/partitionEven.output
 */
void partitionEven(int value);

/**
 * Prints all partitions that do not have consecutive odd or even numbers.
 * In other words, it only prints partitions that have alternating odd and 
 * even numbers.
 *
 * Example:
 * partitionOddAndEven(5); // prints the following (line order not important)
 * = 1 + 4
 * = 2 + 1 + 2
 * = 2 + 3
 * = 3 + 2
 * = 4 + 1
 * = 5
 *
 * See: note on partitionIncreasing(...)
 * Hint: look at file: expected/partitionOddAndEven.output
 */
void partitionOddAndEven(int value);

/**
 * Prints all partitions that comprise solely of prime numbers.
 *
 * Example:
 * partitionPrime(5); // prints the following (line order not important)
 * = 2 + 3
 * = 3 + 2
 * = 5
 * 
 * See: note on partitionIncreasing(...)
 * Hint: you will need to write a function that checks if a number is prime.
 * Hint: 1 is not a prime number.
 * Hint: look at file: expected/partitionPrime.output
 */
void partitionPrime(int value);

