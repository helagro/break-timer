#include "../def.h"
#include "../utils.c"
#include "options.c"
#include <unistd.h>

_Bool setupLogs() {

    /* --------------------- SETUP LOG PATH --------------------- */

    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder)) {
        fprintf(stderr, "Error setting up logs");
        return 0;
    }

    sprintf(getLogsPath(), "%s/main.log", folder);

    /* --------------------- SETUP NOTIFICATION COMMAND --------------------- */

    sprintf(getNotificationCommand(),
            "osascript -e 'display notification \"%s | %d\" with title \"Break Timer\"'", VERSION,
            getpid());

    return 1;
}