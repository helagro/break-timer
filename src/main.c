#include "log.c"
#include "options.c"
#include <stdlib.h>
#include <unistd.h>

void run() {
    for (unsigned char i = 0; 1; i++) {
        sleep(getTimerSeconds());

        note("break");
        fflush(stdout);
        if (system(getPlayCommand())) note("Error playing sound");

        if (i % 4 == 0) loadOptions();
    }
}

int main() {
    if (!loadOptions()) {
        note("Error loading options");
        return 1;
    }

    run();

    return 0;
}
