#include "utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------- MACROS ------------------------- */

#define MAX_PATH_LENGTH 256
#define MAX_LINE_LENGTH 128

/* ------------------------ VARIABLES ----------------------- */

unsigned char _timerLength = 25;
char _silent = 0;
char _notification = 1;

/* ------------------------- METHODS ------------------------ */

char getFilePath(char *output) {
    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder, MAX_PATH_LENGTH)) {
        note("Error getting folder");
        return 0;
    }

    sprintf(output, "%s/.env", folder);
    return 1;
}

char loadOptions() {
    char filePath[266];
    if (!getFilePath(filePath)) {
        note("Error getting file path");
        return 0;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) return 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r' || line[0] == '\0') continue;

        const char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (strcmp(key, "LENGTH") == 0) _timerLength = atoi(value);
        if (strcmp(key, "SILENT") == 0) _silent = value[0] == '1';
        if (strcmp(key, "NOTIFICATION") == 0) _notification = value[0] == '1';
    }
    return 1;
}

/* ------------------------- GETTERS ------------------------ */

unsigned char getTimerSeconds() {
    return _timerLength * 60;
}

char isSilent() {
    return _silent;
}

char isNotification() {
    return _notification;
}