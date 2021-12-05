#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {SECS_TO_SLEEP = 3, NSEC_TO_SLEEP = 125};

int main() {
    struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};

    printf("Started loop..\n");
    for (int i = 0; i < 10; ++i) {
        printf("Iteration - %d\n", i);
        if (i % 4 == 0) {
            printf("Sleeping ....\n");
            nanosleep(&request, &remaining);
        }
    }

    exit(EXIT_SUCCESS);
}