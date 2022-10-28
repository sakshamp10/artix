#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* args[], char* envp[])
{
    DIR* directory = opendir(args[1]);
    if(directory == NULL)
    {
        perror("Directory doesn't exist");
        exit(EXIT_FAILURE);
    }

    struct dirent* d = readdir(directory);

    while(d != NULL)
    {
        if(args[2] == NULL)
        {
            if(d -> d_name[0] != '.')
                printf("%s ", d -> d_name);
            d = readdir(directory);
        }
        else if(strcmp(args[2], "-a") == 0)
        {
            printf("%s ", d -> d_name);
            d = readdir(directory);
        }
        else if(strcmp(args[2], "-p") == 0)
        {
            if(d -> d_name != ".")
            {
                if(d -> d_type == 8)
                {
                    printf("%s ", d -> d_name);
                }
                else
                {
                    printf("%s/ ", d -> d_name);
                }
            }
            d = readdir(directory);
        }
        else
        {
            perror("Invalid operation error");
            exit(EXIT_FAILURE);
        }
    }
    printf("\n");

    closedir(directory);
    return 0;
}