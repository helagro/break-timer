#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 32

unsigned char _timerLength = 25;

char loadOptions() {
    FILE *file = fopen(".env", "r");
    if (file == NULL) return 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r' || line[0] == '\0') continue;

        const char *key = strtok(line, "=");
        const char *value = strtok(NULL, "=");

        if (strcmp(key, "TIMER_LENGTH") == 0) _timerLength = atoi(value);
    }

    return 1;
}