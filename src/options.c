#pragma once

#include "def.h"
#include "utils/utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------- MACROS ------------------------- */

#define MAX_LINE_LENGTH 128

#define DFT_TIMER_LENGTH       25
#define DFT_SECONDS_PER_MINUTE 60
#define DFT_SILENT             0
#define DFT_NOTIFICATION       1

/* ------------------------ VARIABLES ----------------------- */

unsigned char _timerLength = DFT_TIMER_LENGTH;
unsigned char _secondsPerMinute = DFT_SECONDS_PER_MINUTE;
_Bool _silent = DFT_SILENT;
_Bool _notification = DFT_NOTIFICATION;
char _customTextCommand[256] = "";

/* ------------------------- METHODS ------------------------ */

_Bool getFilePath(char *output) {
    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder)) return 0;

    sprintf(output, "%s/.env", folder);
    return 1;
}

void _resetOptions() {
    _timerLength = DFT_TIMER_LENGTH;
    _secondsPerMinute = DFT_SECONDS_PER_MINUTE;
    _silent = DFT_SILENT;
    _notification = DFT_NOTIFICATION;
}

_Bool loadOptions() {
    char filePath[266];
    if (!getFilePath(filePath)) {
        note("Error getting file path");
        return 0;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) return 0;

    _resetOptions();

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r' || line[0] == '\0') continue;

        const char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (strcmp(key, "LENGTH") == 0) _timerLength = atoi(value);
        if (strcmp(key, "SECONDS_PER_MINUTE") == 0) _secondsPerMinute = atoi(value);
        if (strcmp(key, "SILENT") == 0) _silent = value[0] == '1';
        if (strcmp(key, "NOTIFICATION") == 0) _notification = value[0] == '1';
        if (strcmp(key, "CUSTOM_TEXT_COMMAND") == 0) strcpy(_customTextCommand, value);
        if (strcmp(key, "QUIT") == 0 && value[0] == '1') {
            note("Quitting due to .env value");

            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

/* ------------------------- GETTERS ------------------------ */

unsigned int getTimerSeconds() {
    return _timerLength * _secondsPerMinute;
}

_Bool isSilent() {
    return _silent;
}

_Bool isNotification() {
    return _notification;
}

char *getCustomTextCommand() {
    return _customTextCommand;
}