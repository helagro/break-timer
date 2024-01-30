#pragma once

#include "../utils/time.c"
#include "options.c"
#include <stdio.h>

void note(char *message) {
    FILE *file = fopen(getLogsPath(), "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        return;
    }

    printf("%s\n", message);

    char timeStamp[20];
    stamp(timeStamp, "%Y-%m-%d %H:%M", 20);
    fprintf(file, "%s - %s\n", timeStamp, message);

    fclose(file);
}
