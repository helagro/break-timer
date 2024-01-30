#include <stdio.h>
#include <time.h>

void stamp(char *input, char *format, const unsigned char s) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    if (tm_info == NULL)
        sprintf(input, "Time error");
    else
        strftime(input, s, format, tm_info);
}