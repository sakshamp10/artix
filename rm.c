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
    return 0;
}