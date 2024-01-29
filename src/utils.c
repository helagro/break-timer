#pragma once

#include <stdio.h>

char getFolder(char *output, const int s) {
    if (_NSGetExecutablePath(output, &s) == 0) {
        unsigned int i = 0;

        for (; i < s && output[i] != '\0'; i++)
            ;

        for (; i > 0; i--) {
            if (output[i] == '/') {
                output[i] = '\0';
                return 1;
            }
        }
    }

    return 0;
}