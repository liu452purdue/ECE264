#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const **argv)
{
	int i = 0;

	char help[6];
	strcpy(help,"--help");

	char invmatch[14];
	strcpy(invmatch,"--invert-match");
	int inmatch = 0;
	char im[3];
	strcpy(im,"-v");

	char lnumber[13];
	strcpy(lnumber,"--line-number");
    int number = 0;
    char ln[3];
    strcpy(ln,"-n");

	char quiet[7];
	strcpy(quiet,"--quiet");
    int qt = 0;
    char q[3];
    strcpy(q,"-q");
    

    char buffer[2000];
    



	  for (i = 1; i < argc ; i ++)
    {
        if (strcmp(argv[i],help)== 0)
        {
          fprintf(stdout,"Usage: grep-lite [OPTION]... PATTERN\n");
		  fprintf(stdout,"Search for PATTERN in standard input. PATTERN is a\n");
		  fprintf(stdout,"string. grep-lite will search standard input line by\n");
		  fprintf(stdout,"line, and (by default) print out those lines which\n");
		  fprintf(stdout,"contain pattern as a substring.\n");
		  fprintf(stdout,"\n");
		  fprintf(stdout,"  -v, --invert-match     print non-matching lines\n");
		  fprintf(stdout,"  -n, --line-number      print line number with output\n");
		  fprintf(stdout,"  -q, --quiet            suppress all output\n");
		  fprintf(stdout,"\n");
		  fprintf(stdout,"Exit status is 0 if any line is selected, 1 otherwise;\n");
		  fprintf(stdout,"if any error occurs, then the exit status is 2.\n");
		  fprintf(stdout,"\n"); 
          return EXIT_SUCCESS;
        }
        
        
    }

     
if ( argv[argc-1][0] == '-')
{
	return 2;
}
/*for (i = 1; i < argc ; i ++)
    {
        
       if ((strcmp(argv[i],invmatch) != 0)&&(strcmp(argv[i],im) != 0))
		 {
		 	if ((strcmp(argv[i],lnumber) != 0)&&(strcmp(argv[i],ln) != 0))
		 	{
				if ((strcmp(argv[i],quiet) != 0)&&(strcmp(argv[i],q) != 0))
		 		{
		              printf("%s\n",argv[argc-1]);
		              fprintf(stderr,"grep-lite will search standard input line by line by contain pa \n");
		              return 2;
		 		}
		 	break;
		 	}
		 	break;
		 } 
		 break;
       
    }*/



for (i = 1; i < argc ; i ++)
{
  if ((strcmp(argv[i],invmatch) == 0)||(strcmp(argv[i],im) == 0))
  {
  	 inmatch = 1;
  }

  if ((strcmp(argv[i],lnumber) == 0)||(strcmp(argv[i],ln) == 0))
  {
  	number = 1;
  }
  if ((strcmp(argv[i],quiet) == 0)||(strcmp(argv[i],q) == 0))
  {
  	qt = 1;
  }
 
}

 int found = 0;
 for (i = 1; !feof(stdin); ++i)
 {
   fgets(buffer,2000,stdin);

   if (strstr(buffer,argv[argc-1]) != NULL)
   {
   	 found = 1;
   	 if(qt == 1)
   	 {
   	 	return 0;
   	 }

   	 if(inmatch == 0)
   	 {
   	 	if (number == 1)
   	 	{
   	 		printf("%d:", i );
   	 	}
   	 	printf("%s",buffer);

   	 }
   }
  
  else 
   {
   	 found = 1;

   	 if(inmatch == 1)
   	 {
   	 	if (number == 1)
   	 	{
   	 		printf("%d:", i );
   	 	}
   	 	printf("%s",buffer);

   	 }
   }


 }
return 0;





    
}