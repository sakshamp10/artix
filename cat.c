#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* args[], char* envp[])
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
    return 0;
}