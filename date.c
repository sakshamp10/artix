#include <stdio.h>
#include <time.h>

int main(int argc, char* args[], char* envp[])
{
    time_t T = time(NULL);
    struct tm time = *localtime(&T);
    printf("%d-%02d-%02d %02d:%02d:%02d\n", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    return 0;
}