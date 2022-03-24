#include <time.h>
#include <stdio.h>

clock_t startTimer() {
    return clock();
}

void stopTimer(clock_t t) {
    t = clock() - t;
    printf("Time elapsed: %.6f secs\n", ((double)t)/CLOCKS_PER_SEC);
}