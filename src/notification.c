#pragma once

#include "def.h"
#include "options.c"
#include "utils/utils.c"
#include <stdlib.h>
#include <unistd.h>

#define NOTIFICATION_COMMAND_SIZE 600
#define CUSTOM_PART_SIZE          400

_Bool getCustomPart(char *buffer, int size) {
    FILE *fp = popen(getCustomTextCommand(), "r");
    buffer[0] = '\0';

    if (fp == NULL) {
        note("popen failed!");
        return 1;
    }

    if (fgets(buffer, size, fp) == NULL) {
        return 1;
    }

    int status = pclose(fp);
    if (status == -1) {
        note("pclose failed!");
    }

    return 0;
}

void displayNotification() {
    char notificationCommand[NOTIFICATION_COMMAND_SIZE];
    char customPartBuffer[CUSTOM_PART_SIZE];

    if (getCustomPart(customPartBuffer, CUSTOM_PART_SIZE)) {
        sprintf(customPartBuffer, "Break time!");
    }

    if (strlen(customPartBuffer) == 0) {
        note("Error getting custom part, read: empty string");
    }

    snprintf(notificationCommand, NOTIFICATION_COMMAND_SIZE,
             "osascript -e 'display notification \" %s | %d\" with title \"Break Timer\"'",
             customPartBuffer, getpid());

    system(notificationCommand);
}
