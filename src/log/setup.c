#include "../def.h"
#include "../utils/utils.c"
#include "options.c"
#include <unistd.h>

_Bool setupLogs() {

    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder)) {
        fprintf(stderr, "Error setting up logs");
        return 0;
    }

    sprintf(getLogsPath(), "%s/main.log", folder);

    return 1;
}