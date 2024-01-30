#pragma once
#include "../def.h"

char _logsPath[MAX_PATH_LENGTH];
char _notificationCommand[100];

char *getLogsPath() {
    return _logsPath;
}

char *getNotificationCommand() {
    return _notificationCommand;
}