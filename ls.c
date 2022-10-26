#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>


int main(int argc, char* args[], char* envp[])
{
    DIR* directroy;
    if(args[0] == NULL)
        directroy = opendir('.');
    else
        directroy = opendir(args[0]);
    if(directroy == NULL)
    {
        perror("Directory doesn't exist");
        exit(EXIT_FAILURE);
    }
    
    struct dirent* d = readdir(directroy);

    while(d != NULL)
    {
        if(args[1] == NULL)
        {
            if(d -> d_name[0] != '.')
            {
                printf("%s ", d -> d_name);
            }
            d = readdir(directroy);
        }
    }
    printf("\n");

    return 0;
}