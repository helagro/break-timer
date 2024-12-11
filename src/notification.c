#pragma once

#include "def.h"
#include "options.c"
#include "utils/utils.c"
#include <stdlib.h>
#include <unistd.h>

_Bool getCustomPart(char *buffer, int size) {
    FILE *fp = popen(getCustomTextCommand(), "r");

    if (fp == NULL) {
        perror("popen failed!");
        return 1;
    }

    // Read and print the output line by line
    while (fgets(buffer, size, fp) != NULL) {
    }

    int status = pclose(fp);
    if (status == -1) {
        perror("pclose failed!");
    }

    return 0;
}

void displayNotification() {
    char notificationCommand[500];
    char customPartBuffer[350];

    if (getCustomPart(customPartBuffer, 600)) {
        sprintf(customPartBuffer, "Break time!");
    }

    sprintf(notificationCommand,
            "osascript -e 'display notification \" %s | %d\" with title \"Break Timer\"'",
            customPartBuffer + 6, getpid());

    system(notificationCommand);
}
