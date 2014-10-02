#include <stdio.h>
#include <stdlib.h>

int int main(int argc, char const *argv[])
{
    FILE *file;
  
    int i = 0;
    char Content;
    
    char * help[6];

    strcpy (help,"--help");
      
    for (i = 1; i < argc -1; i ++)
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

    for (i = 0; i < argc -1; i++)
    {
       file  = fopen(argv[i],"r");
       
       if (file == NULL)
       {
         printf( "cat cannot open %s\n", argv[i] );
         return EXIT_FAILURE;
       } 

 
       else
       {
          while (Content != EOF)
          {
             Content = fgetc (file);
              printf("%c", Content);
          }
            printf("\n");
        fclose (pFile);

       }      



    }
    
    return EXIT_SUCCESS;
}

