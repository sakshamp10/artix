#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* args[], char* envp[])
{
    if(args[2] == NULL)
    {
        int check;
        char *dirName = args[1];

        check = mkdir(dirName, 0777);

        if(check != 0)
        {
            perror("Unable to create directory");
        }
    }
    else if(args[1][0] == '-')
    {
        if(args[1][1] == 'v')
        {
            int check;
            char *dirName = args[2];

            check = mkdir(dirName, 0777);

            if(check == 0)
                printf("Directory created %s\n", (char*) args[1]);
            else
            {
                perror("Unable to create directory");
            }
        }
        else if(args[1][1] == 'm')
        {
            int level = atoi(args[1]+3);
            int check;
            char *dirName = args[2];

            check = mkdir(dirName, level);

            if(check != 0)
            {
                perror("Unable to create directory");
            }
        }
    }
    else
        perror("Invalid operation error");

    return 0;
}