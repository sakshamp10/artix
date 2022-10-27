#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* args[], char* envp[])
{
    if(strcmp(args[0], ">") == 0 && args[1] != NULL && args[2] == NULL)
    {
        int check;
        char *dirName = args[1];

        check = mkdir(dirName, 0777);

        if(check != 0)
        {
            perror("Unable to create directory");
            exit(EXIT_FAILURE);
        }
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
    else if(strcmp(args[1], ">>") == 0)
    {
        FILE *file1, *file2;
        char c1, c2;

        file1 = fopen(args[0], "r");
        c1 = fgetc(file1);
        while(c1 != EOF)
        {
            printf("%c", c1);
            c1 = fgetc(file1);
        }
        printf(" ");
        file2 = fopen(args[2], "r");
        c2 = fgetc(file1);
        while(c2 != EOF)
        {
            printf("%c", c2);
            c2 = fgetc(file2);
        }
        fclose(file1);
        fclose(file2);
    }
    
    return 0;
}