#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* args[], char* envp[])
{
    if(args[1] == NULL)
    {
        int status;
        status = remove(args[0]);
        if(status != 0)
        {
            perror("Couldn't remove the file");
            exit(EXIT_FAILURE);
        }
    }
    else if(strcmp(args[0], "-i") == 0)
    {
        char check;
        printf("remove file %s? ", args[1]);
        scanf("%c", &check);
        if(check == 'y')
        {
            int status;
            status = remove(args[1]);
            if(status != 0)
            {
                perror("Couldn't remove the file");
                exit(EXIT_FAILURE);
            }
        }
    }
    else if(strcmp(args[0], "-v") == 0)
    {
        int status;
        status = remove(args[1]);
        if(status != 0)
        {
            perror("Couldn't remove the file");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("removed %s", args[1]);
        }
    }
    return 0;
}