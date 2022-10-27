#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* args[], char* envp[])
{
    if(args[1] == NULL)
    {
        int check;
        char *dirName = args[0];

        check = mkdir(dirName, 0777);

        if(check != 0)
        {
            perror("Unable to create directory");
            exit(EXIT_FAILURE);
        }
    }
    if(strcmp(args[1], "-v") == 0)
    {
        int check;
        char *dirName = args[0];

        check = mkdir(dirName, 0777);

        if(check == 0)
            printf("Directory created %s\n", (char*) args[0]);
        else
        {
            perror("Unable to create directory");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}