#include "def.h"
#include "utils/utils.c"
#include <stdlib.h>

char _notificationCommand[100];

void displayNotification() {
    char timeStamp[18];
    stamp(timeStamp, "%H:%M", 18);

    sprintf(_notificationCommand,
            "osascript -e 'display notification \" %s | %s | %d\" with title \"Break Timer\"'",
            timeStamp, VERSION, getpid());

    system(_notificationCommand);
}