#include <stdio.h>
#include <time.h>
#include <string.h>

void idByTime(char *output)
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    sprintf(output, "XX-%d-%d-%d-%d-%d-%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int main(int argc, char const *argv[])
{
    char s[100];
    idByTime(s);
    printf("%s\n", s);
    return 0;
}
