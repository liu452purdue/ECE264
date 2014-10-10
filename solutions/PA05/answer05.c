#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void f(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;

 if (n == 0)
 {
   printf("=");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d+",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );

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

void f1(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int incflag = 0;

 if (n == 0)
 {
  for (i = 1; i < ind ; ++i)
  { 
    if (arr[i] <= arr[i-1])
    {
      incflag =1;

    }

  }

  if (incflag == 0)
  {

   printf("= ");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );

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


void f2(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int incflag=0;

 if (n == 0)
 {
  for (i = 1; i < ind ; ++i)
  { 
    if (arr[i] >= arr[i-1])
    {
      incflag =1;

    }
    
  }

  if (incflag == 0)
  {

   printf("= ");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );


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


void f3(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int oddflag=1;

 if (n == 0)
 {
  for (i = 0; i <ind ; ++i)
  { 
    if ((arr[i] %2)==0)
    {
      oddflag =0;

    }

  }

  if (oddflag == 1)
  {

   printf("= ");
   for (i = 0; i < ind -1; ++i)
   {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );


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




void f4(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int evenflag=1;

 if (n == 0)
 {
  for (i = 0; i < ind ; ++i)
  { 

    if (((arr[i]) %2)==1)
    {
      evenflag =0;

    }     
  }
  if (evenflag == 1)
  {
    printf("= ");
    for (i = 0; i < ind -1; ++i)
    {
      printf("%d + ",arr[i] ); 
    }
    printf("%d\n", arr[ind -1] );

  }
}

for (j = 1; j <= n; j += 1)
{

  arr[ind] = j;
  f4(n-j,arr,ind +1);
}

return;

}
void partitionEven(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f4(value, arr, ind);
  free(arr);
  return;
}


void f5(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int oeflag=1;

 if (n == 0)
 {
  for (i = 1; i < ind ; ++i)
  { 

    if (((arr[i]+arr[i-1]) %2)==0)
    {
      oeflag =0;

    }     
  }
  if (oeflag == 1)
  {
    printf("= ");
    for (i = 0; i < ind -1; ++i)
    {
      printf("%d + ",arr[i] ); 
    }
    printf("%d\n", arr[ind -1] );

  }
}

for (j = 1; j <= n; j += 1)
{

  arr[ind] = j;
  f5(n-j,arr,ind +1);
}

return;

}

void partitionOddAndEven(int value)
{
  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f5(value, arr, ind);
  free(arr);
  return;
}






int check_prime(int number)
{
  int i =0;
  {
    for (i = 2; i < number; i++)
    {
      if (number % i == 0 && i != number)
        return 0;
    }
    return 1;
  }
}


void f6(int n, int*arr, int ind)
{
 int i = 0;
 int j = 0;
 int primeflag=1;

 if (n == 0)
 {
  for (i = 0; i <ind  ; ++i)
  { 
   if((check_prime(arr[i])==0)||(arr[i] == 1))
   {
    primeflag =0;
  }
  

}
if (primeflag == 1)
{
  printf("= ");
  for (i = 0; i < ind -1; ++i)
  {
    printf("%d + ",arr[i] ); 
  }
  printf("%d\n", arr[ind -1] );

}
}

for (j = 1; j <= n; j += 1)
{

  arr[ind] = j;
  f6(n-j,arr,ind +1);
}

return;

}


void partitionPrime(int value)
{

  int *arr;
  arr = malloc(sizeof(int)*value);
  int ind = 0;
  f6(value, arr, ind);
  free(arr);
  return;
}


