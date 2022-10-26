#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>


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
            {
                perror("Unknown operation error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            perror("Invalid syntax error");
            exit(EXIT_FAILURE);
        }   
    }
}


void echo(char** args)
{
    if (strcmp(args[1], "*") == 0)
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
}


void cd(char** args)
{
    if(args[1] == NULL)
    {
        printf("Error :Invalid Syntax\n");
    }
    else
    {
        if(chdir(args[1]) != 0)
        {
            perror("Invalid syntax error");
        }  
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
        exit(EXIT_FAILURE);
    }
    else if(childPID == 0)
    {
        execl("ls", args[1], args[2]);
        perror("Unknown command");
        exit(EXIT_FAILURE);
    }
    else
    {
        pid_t temp = wait(&childStatus);
        while(temp != childPID);
        {
            temp = wait(&childStatus);
            if(temp != childPID)
            process_terminated(temp);
        } 
    }
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
                exit(EXIT_FAILURE);
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
        exit(EXIT_FAILURE);
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
                exit(EXIT_FAILURE);
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
    {
        cd(args);
    }
    else if(strcmp(args[0], "echo") == 0)
    {
        echo(args);
    }
    else if(strcmp(args[0], "pwd") == 0)
    {
        pwd(args);
    }
    else if(strcmp(args[0], "ls") == 0)
    {
        for(int i = 1 ; args[i] != NULL ; i++)
        {
            puts(args[i] + 2);
        }
    }
    else if(strcmp(args[0], "exit") == 0)
    {
        return false;
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
        printf("[%s %s]$ ", (getenv("USERNAME")), directory);
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