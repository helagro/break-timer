#include "log.c"
#include "options.c"
#include <stdlib.h>
#include <unistd.h>

void run() {
    while (1) {
        sleep(getTimerSeconds());
        note("break");
        fflush(stdout);

        if (system("afplay funk.mp3")) note("Error playing sound");
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
