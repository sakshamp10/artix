#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* args[], char* envp[])
{
    if(args[1] == NULL)
    {
        char week[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
        char month[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        time_t T = time(NULL);
        struct tm time = *localtime(&T);
        printf("%s %s %02d %02d:%02d:%02d IST %d\n", week[time.tm_wday], month[time.tm_mon + 1], time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec, time.tm_year + 1900);
    }
    // else if(strcmp(args[1], "-u") == 0)
    else if(args[1][0] == '-')
    {
        if(args[1][1] == 'u')
        {
            char week[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
            char month[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            time_t T = time(NULL);
            struct tm* time = gmtime(&T);
            printf("%s %s %02d %02d:%02d:%02d UTC %d\n", week[time -> tm_wday], month[time -> tm_mon + 1], time -> tm_mday, time -> tm_hour, time -> tm_min, time -> tm_sec, time -> tm_year + 1900);
        }
        else if(args[1][1] == 'R')
        {
            char week[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
            char month[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

            time_t T = time(NULL);
            struct tm time = *localtime(&T);
            printf("%s, %02d %s %d %02d:%02d:%02d +0530\n", week[time.tm_wday], time.tm_mday, month[time.tm_mon + 1], time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
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

    return 0;
}