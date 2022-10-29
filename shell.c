#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <sys/wait.h>


void cd(char** args)
{
    if(args[1] == NULL)
    {
        perror("Invalid syntax error");
    }
    else
    {
        if(chdir(args[1]) != 0)
        {
            perror("File doesn't exit");
        }  
    }
}


void echo(char** args)
{
    if (args[1] == NULL)
        perror("Invalid syntax error");
    
    else if (strcmp(args[1], "*") == 0)
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
        }
        while((d = readdir(currDir)) != NULL)
        {
            if(d -> d_name[0] == '.')
                continue;
            printf("%s ", d -> d_name);

        }
        printf("\n");
    }

    else if(args[1][0] != '-' && args[1] != "*")
    {
        for(int i = 1 ; args[i] != NULL ; i++)
        {
            printf("%s ", args[i]);
        }
        printf("\n");
    }
    
    else if(args[1][0] == '-')
    {
        if(args[1][1] == 'n')
        {
            for(int i = 2 ; args[i] != NULL ; i++)
            {
                printf("%s ", args[i]);
            }
        }
        else 
            perror("Invalid operation error");
    }
    else
        perror("Invalid syntax error");
}


void pwd(char** args)
{
    char directory[1024];
    getcwd(directory, sizeof(directory));
    if(args[1] == NULL)
        printf("%s\n", directory);
    else if(args[1] != NULL)
    {
        if(args[1][0] == '-')
        {
            if(args[1][1] == 'L')
                printf("%s\n", directory);
            else if(args[1][1] == 'P')
                printf("%s\n", directory);
            else
                perror("Invalid operation error");
        }
        else
            perror("Invalid syntax error");
    }
}


void ls(char** args)
{
    pid_t childPID;
    int childStatus;

    childPID = fork();

    if(childPID == -1)
    {
        perror("Couldn't execute fork");
    }
    else if(childPID == 0)
    {
        char currDir[1024];
        getcwd(currDir, sizeof(currDir));
        execl("ls", args[0], currDir, args[1], args[2], NULL);
        perror("Functions not allowed");
    }
    else
    {
        childStatus = wait(NULL);
    }
}


void cat(char** args)
{
    pid_t childPID;
    int childStatus;
    childPID = fork();

    if(childPID == -1)
    {
        perror("Couldn't execute fork");
    }
    else if(childPID == 0)
    {
        execl("cat", args[0], args[1], args[2], args[3], NULL);
        perror("Invalid syntax error");
    }
    else
    {
        childStatus = wait(NULL);
    }
}


void date(char** args)
{
    pid_t childPID;
    int childStatus;
    childPID = fork();

    if(childPID == -1)
    {
        perror("Couldn't execute fork");
    }
    else if(childPID == 0)
    {
        execl("date", args[0], args[1], NULL);
        perror("Invalid syntax error");
    }
    else
    {
        childStatus = wait(NULL);
    }
}


void rm(char** args)
{
    pid_t childPID;
    int childStatus;
    childPID = fork();

    if(childPID == -1)
    {
        perror("Couldn't execute fork");
    }
    else if(childPID == 0)
    {
        execl("rm", args[0], args[1], args[2], NULL);
        perror("Invalid syntax error");
    }
    else
    {
        childStatus = wait(NULL);
    }
}


void mkdir(char** args)
{
    pid_t childPID;
    int childStatus;
    childPID = fork();

    if(childPID == -1)
    {
        perror("Couldn't execute fork");
    }
    else if(childPID == 0)
    {
        execl("mkdir", args[0], args[1], args[2], NULL);
        perror("Invalid syntax error");
    }   
    else
    {
        childStatus = wait(NULL);
    }
}


void* systemExecution(void* argument)
{
    system((char*) (argument));
    return NULL;
}


void ls_thread(char** args)
{
    char* argument = malloc(sizeof(char) * 1024);
    strcat(argument, "./ls ");
    char currDir[1024];
    getcwd(currDir, sizeof(currDir));
    strcat(argument, currDir);
    strcat(argument, " ");

    if(args[1] != NULL)
        strcat(argument, args[1]);
    
    pthread_t thread;
    pthread_create(&thread, NULL, systemExecution, (void*) (argument));
    pthread_join(thread, NULL);
}


void cat_thread(char** args)
{
    char* argument = malloc(sizeof(char) * 1024);
    strcat(argument, "./cat ");

    if(strcmp(args[1], ">") == 0 && args[2] != NULL && args[3] == NULL)
    {
        strcat(argument, "> ");
        strcat(argument, args[2]);
    }

    else if(args[2] == NULL)
        strcat(argument, args[1]);

    else if(args[2] != NULL)
    {
        strcat(argument, args[1]);
        strcat(argument, " ");
        strcat(argument, args[2]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, systemExecution, (void*) (argument));
    pthread_join(thread, NULL);
}


void date_thread(char** args)
{
    char* argument = malloc(sizeof(char) * 1024);
    strcat(argument, "./date ");
    if(args[1] != NULL)
        strcat(argument, args[1]);
    
    pthread_t thread;
    pthread_create(&thread, NULL, systemExecution, (void*) (argument));
    pthread_join(thread, NULL);
}


void rm_thread(char** args)
{
    char* argument = malloc(sizeof(char) * 1024);
    strcat(argument, "./rm ");

    if(args[2] == NULL)
        strcat(argument, args[1]);

    else if(strcmp(args[1], "-i") == 0)
    {
        strcat(argument, "-i ");
        strcat(argument, args[2]);
    }

    else if(strcmp(args[1], "-v") == 0)
    {
        strcat(argument, "-v ");
        strcat(argument, args[2]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, systemExecution, (void*) (argument));
    pthread_join(thread, NULL);
}


void mkdir_thread(char** args)
{
    char* argument = malloc(sizeof(char) * 1024);
    strcat(argument, "./mkdir ");

    if(args[2] == NULL)
        strcat(argument , args[1]);
    
    else if(strcmp(args[1], "-v") == 0)
    {
        strcat(argument, "-v ");
        strcat(argument, args[2]);
    }

    else if(strcmp(args[1], "-m") == 0)
    {
        strcat(argument, "-m ");
        strcat(argument, args[2]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, systemExecution, (void*) (argument));
    pthread_join(thread, NULL);
}


char* takeInput(void) 
{
    int bufferSize = 1024;
    int position = 0;
    char* buffer = malloc(bufferSize * sizeof(char));
    int c;

    if(!buffer)
    {
        printf("Error :Couldn't allocate memory\n");
        exit;
    }

    while(true)
    {
        c = getchar();

        if(c == EOF|| c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        if(position >= bufferSize)
        {
            bufferSize += 1024;
            buffer = realloc(buffer, bufferSize);
            if(!buffer)
            {
                printf("Error :Couldn't allocate memory\n");
            }
        }
    }
}


char** parseInput(char * line)
{
    int bufferSize = 64;
    int position = 0;
    char** tokens = malloc(sizeof(char*) * bufferSize);
    char* currToken;

    if(tokens == NULL)
    {
        printf("Error : Allocation error\n");
    }

    currToken = strtok(line, " ");
    while(currToken != NULL)
    {
        tokens[position] = currToken;
        position++;

        if(position >= bufferSize)
        {
            bufferSize += 64;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if(tokens == NULL)
            {
                printf("Error : Allocation error\n");
            }
        }

        currToken = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}


bool execute(char** args)
{
    if(strcmp(args[0], "cd") == 0)
        cd(args);
    else if(strcmp(args[0], "echo") == 0)
        echo(args);
    else if(strcmp(args[0], "pwd") == 0)
        pwd(args);
    else if(strcmp(args[0], "ls") == 0)
        ls(args);
    else if(strcmp(args[0], "ls&t") == 0)
        ls_thread(args);
    else if(strcmp(args[0], "cat") == 0)
        cat(args);
    else if(strcmp(args[0], "cat&t") == 0)
        cat_thread(args);
    else if(strcmp(args[0], "date") == 0)
        date(args);
    else if(strcmp(args[0], "date&t") == 0)
        date_thread(args);
    else if(strcmp(args[0], "rm") == 0)
        rm(args);
    else if(strcmp(args[0], "rm&t") == 0)
        rm_thread(args);
    else if(strcmp(args[0], "mkdir") == 0)
        mkdir(args);
    else if(strcmp(args[0], "mkdir&t") == 0)
        mkdir_thread(args);
    else if(strcmp(args[0], "exit") == 0)
        return false;
    else
    {
        perror("Unknown command");
    }
    return true;
}


void shell() 
{
    char *input;
    char **arguments;
    bool status = true;
    char directory[1024];


    while(status) 
    {
        getcwd(directory, sizeof(directory));
        printf("[%s %s]$ ", (getenv("USER")), directory);
        input = takeInput();
        arguments = parseInput(input);
        status = execute(arguments);

        free(input);
        free(arguments);
    }
}


int main() 
{
    shell();
    return 0;
}