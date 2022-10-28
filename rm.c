#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* args[], char* envp[])
{
    if(args[2] == NULL)
    {
        int status;
        status = remove(args[1]);
        if(status != 0)
        {
            perror("Couldn't remove the file");
            exit(EXIT_FAILURE);
        }
    }
    else if(strcmp(args[1], "-i") == 0)
    {
        char check;
        printf("remove file %s? ", args[2]);
        scanf("%c", &check);
        if(check == 'y')
        {
            int status;
            status = remove(args[2]);
            if(status != 0)
            {
                perror("Couldn't remove the file");
                exit(EXIT_FAILURE);
            }
        }
    }
    else if(strcmp(args[1], "-v") == 0)
    {
        int status;
        status = remove(args[2]);
        if(status != 0)
        {
            perror("Couldn't remove the file");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("removed %s\n", args[2]);
        }
    }
    else
    {
        perror("Invalid operation error");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}