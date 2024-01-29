#include "../def.h"
#include "../utils.c"

char _logsPath[MAX_PATH_LENGTH];

_Bool setupLogs() {
    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder)) {
        fprintf(stderr, "Error setting up logs");
        return 0;
    }

    sprintf(_logsPath, "%s/main.log", folder);

    return 1;
}

char *getLogsPath() {
    return _logsPath;
}