#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* args[], char* envp[])
{
    if(strcmp(args[0], ">") == 0 && args[1] != NULL && args[2] == NULL)
    {
        FILE *file;
        file = fopen(args[1], "w");
        fclose(file);
    }

    else if(args[1] == NULL)
    {
        FILE *file;
        char c;
        file = fopen(args[0], "r");
        c = fgetc(file);
        while(c != EOF)
        {
            printf("%c", c);
            c = fgetc(file);
        }
        fclose(file);
    }
    else if(args[1] != NULL)
    {
        FILE *file1;
        FILE *file2;
        char c1, c2;

        file1 = fopen(args[0], "r");
        c1 = fgetc(file1);
        while(c1 != EOF)
        {
            printf("%c", c1);
            c1 = fgetc(file1);
        }
        fclose(file1);
        file2 = fopen(args[1], "r");
        c2 = fgetc(file1);
        while(c2 != EOF)
        {
            printf("%c", c2);
            c2 = fgetc(file2);
        }
        fclose(file2);
    }
    
    return 0;
}