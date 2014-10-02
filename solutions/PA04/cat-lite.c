#include <stdio.h>
#include <stdlib.h>
void _filecopy(FILE *fp_in, FILE * fp_out);
int main(int argc , char * argv[])
{
 
    FILE * fp;
    char *prog = argv[0] ;  //指定的错误输出文件名;
 
    if( argc == 1 ) //没有指定打开文件,把标准输入复制到标准输出
        _filecopy(stdin,stdout);
 
    else
        while(--argc > 0)
            if((fp = fopen(*++argv,"r")) == NULL) 
            {//文件打开失败
                fprintf(stderr,"%s:打开%s失败\n",prog,*argv );
                exit(1);
            }else{
                _filecopy(fp ,stdout);
                fclose(fp);
            }
    if(ferror(stdout)){  //如果输出流出错ferror函数返回一个非零的值
        fprintf(stderr, "%s:输出流出错了!\n",prog);
        exit(2);
    }
    exit(0);
    return 0;
}
 
void _filecopy(FILE *fp_in, FILE * fp_out)
{
    int c;
    while ((c = getc(fp_in)) != EOF)
        putc(c,fp_out);
}

