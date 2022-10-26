#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[], char* envp[])
{
    int check;
    char *dirName = args[0];
    // clrscr();

    check = mkdir(dirName, 0777);

    if(check == 0)
        printf("Directory created\n");
    else
    {
        perror("Unable to create directory");
        exit(EXIT_FAILURE);
    }

    // getch();
    // system("dir");
    // getch();
    return 0;
}