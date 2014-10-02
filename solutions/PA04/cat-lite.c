#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0


int main(int argc, char const *argv[])
{
    FILE *file;
  
    int i = 0;

    int j = 0;

    int in;

    char Content;
    
    char help[6];

    strcpy (help,"--help");
      
    for (i = 1; i < argc ; i ++)
    {
        if (strcmp(argv[i],help)== 0)
        {
            fprintf(stdout,"Usage: cat-lite [--help] [FILE]...\n");
            fprintf(stdout,"With no FILE, or when FILE is -, read standard input.\n");
            fprintf(stdout,"\n");
            fprintf(stdout,"Examples:\n");
            fprintf(stdout,"  cat-lite README   Print the file README to standard output.\n");
            fprintf(stdout,"  cat-lite f - g    Print f's contents, then standard input,\n");
            fprintf(stdout,"                    then g's contents.\n");
            fprintf(stdout,"  cat-lite          Copy standard input to standard output.\n");
            fprintf(stdout,"\n"); 
        return EXIT_SUCCESS;
        }
    }

    
   if(argc == 1)
  {
    do{
   
    fputc(fgetc(stdin), stdout);
      }while (fgetc(stdin) != '\n');
  }

  else
  {
    for (j = 1; j < argc ; ++j)
    {
       
      if (*argv[j] == '-')
       {
         
         
         do
         {
           
           fputc(fgetc(stdin), stdout);
         } while(fgetc(stdin) !='\n');

        }
       
       
        else{
           file  = fopen(argv[j],"r");
       
         if (file == NULL)
           {
             printf( "cat cannot open %s\n", argv[j] );
             return EXIT_FAILURE;
            } 

 
          else
          {  
       
            do
            {
               Content = fgetc (file);
                //printf("%c", Content);

                 
      
            if(Content != EOF)
              {
                fputc(Content,stdout);
              }
            }while(Content != EOF);
            
            //printf("\n");
          fclose (file);

          }      
         } 


    }
    
    return EXIT_SUCCESS;
  }
}


