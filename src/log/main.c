#pragma once

#include "options.c"
#include <stdio.h>
#include <time.h>

#define TIMESTAMP_LENGTH 20

void stamp(char *input) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    if (tm_info != NULL) {
        strftime(input, TIMESTAMP_LENGTH, "%Y-%m-%d %H:%M", tm_info);
    }
}

void note(char *message) {
    FILE *file = fopen(getLogsPath(), "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        return;
    }

    printf("%s\n", message);

    char timeStamp[TIMESTAMP_LENGTH];
    stamp(timeStamp);
    fprintf(file, "%s - %s\n", timeStamp, message);
    fclose(file);
}
