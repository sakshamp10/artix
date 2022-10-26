#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>


void ls(char** args, int a, int l)
{
    struct dirent *d;
    DIR *currDir = opendir(".");
    if(!currDir)
    {
        if(errno == ENOENT)
        {
            perror("Directory does not exist");
        }
        else 
        {
            perror("Unable to open directory");
        }
        exit(EXIT_FAILURE);
    }
    while((d = readdir(currDir)) != NULL)
    {
        if(!a && d -> d_name[0] == '.')
            continue;
        printf("%s ", d -> d_name);
        if(l)
            printf("\n");

    }
    if(!l)
        printf("\n");
}


int main(char** args)
{  
    if(args[1] == NULL)
    {
        ls(".", 0, 0);
    }
    else if(args[1] != NULL)
    {
        if(args[1][0] == '-')
        {
            int a = 0; int l = 0;
            char *operation = (char *)args[1] + 1;
            if(operation == 'a')
                a = 1;
            if(operation == 'l')
                l = 1;
            else
            {
                perror("Unknown operation error");
                exit(EXIT_FAILURE);
            }
            ls(".", a, l);
        }
    }
    return 0;
}