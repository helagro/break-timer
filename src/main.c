#include "def.h"
#include "log/log.c"
#include "log/setup.c"
#include "notification.c"
#include "options.c"
#include "utils/utils.c"
#include <stdlib.h>
#include <unistd.h>

/* ------------------------- MACROS ------------------------- */

#define MAX_COMMAND_LENGTH 275

/* ------------------------ FUNCTIONS ----------------------- */

_Bool getCommand(char *output) {
    char folder[MAX_PATH_LENGTH];
    if (!getFolder(folder)) return 0;

    sprintf(output, "afplay %s/funk.mp3", folder);
    return 1;
}

void run() {
    char command[275];
    if (!getCommand(command)) {
        note("Error getting command");
        return;
    }

    for (unsigned char i = 0; 1; i++) {
        sleep(getTimerSeconds());

        note("break");
        fflush(stdout);

        if (!loadOptions()) return;

        if (isNotification()) displayNotification();
        if (!isSilent())
            if (system(command)) note("Error playing sound");
    }
}

int main() {
    if (!setupLogs()) return 1;

    if (!loadOptions()) {
        note("Error loading options");
        return 1;
    }

    run();

    return 0;
}
