#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* args[], char* envp[])
{
    DIR* directory = opendir(args[1]);
    struct dirent* d = readdir(directory);

    if(args[2] == NULL)
    {
        while(d != NULL)
        {
            if(d -> d_name[0] != '.')
                printf("%s ", d -> d_name);
            d = readdir(directory);
        }
    }
    else if(args[2] != NULL)
    {
        if(args[2][0] != '-')
        {
            DIR* directory = opendir(args[2]);
            if(directory == NULL)
            {
                perror("File doesn't exist");
                exti(EXIT_FAILURE);
            }
            struct dirent* d = readdir(directory);
            while(d != NULL)
            {
                if(d -> d_name[0] != '.')
                    printf("%s ", d -> d_name);
                d = readdir(directory);
            }
        }
        else if(strcmp(args[2], "-a") == 0)
        {
            if(args[3] == NULL)
            {
                DIR* directory = opendir(args[1]);
                struct dirent* d = readdir(directory);
            }
            else
            {
                DIR* directory = opendir(args[3]);
                if(directory == NULL)
                {
                    perror("File doesn't exist");
                    exti(EXIT_FAILURE);
                }
                struct dirent* d = readdir(directory);
            }

            while(d != NULL)
            {
                printf("%s ", d -> d_name);
                d = readdir(directory);
            }
        }
        else if(strcmp(args[2], "-p") == 0)
        {
            if(args[3] == NULL)
            {
                DIR* directory = opendir(args[1]);
                struct dirent* d = readdir(directory);
            }
            else
            {
                DIR* directory = opendir(args[3]);
                if(directory == NULL)
                {
                    perror("File doesn't exist");
                    exti(EXIT_FAILURE);
                }
                struct dirent* d = readdir(directory);
            }

            while(d != NULL)
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
        }
        else 
        {
            perror("Invalid operation error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        perror("Invalid syntax error");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    closedir(directory);

    return 0;
}