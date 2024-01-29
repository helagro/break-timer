#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------- MACROS ------------------------- */

#define MAX_LINE_LENGTH 128

/* ------------------------ VARIABLES ----------------------- */

unsigned char _timerLength = 25;

char _setPlayCommand = 0;
char *_playCommand = "afplay funk.mp3";

/* ------------------------- METHODS ------------------------ */

char loadOptions() {
    FILE *file = fopen(".env", "r");
    if (file == NULL) return 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r' || line[0] == '\0') continue;

        const char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (strcmp(key, "TIMER_LENGTH") == 0) _timerLength = atoi(value);
        if (strcmp(key, "PLAY_COMMAND") == 0) {
            if (_setPlayCommand) free(_playCommand);
            _setPlayCommand = 1;

            _playCommand = malloc(strlen(value) + 1);
            strcpy(_playCommand, value);
        }
    }

    return 1;
}

/* ------------------------- GETTERS ------------------------ */

unsigned char getTimerSeconds() {
    return _timerLength * 1;
}

char *getPlayCommand() {
    return _playCommand;
}