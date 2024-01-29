#include "options.c"

int main() {
    if (!loadOptions()) {
        fprintf(stderr, "Error loading options\n");
        return 1;
    }

    printf("Timer length: %d\n", _timerLength);

    return 0;
}
