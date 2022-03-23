#include <time.h>

clock_t startTimer() {
    return clock();
}

void stopTimer(clock_t t) {
    t = clock() - t;
    printf("Time elapsed: %.4f secs\n", ((double)t)/CLOCKS_PER_SEC);
}