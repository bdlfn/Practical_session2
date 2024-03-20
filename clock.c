#include <stdio.h>
#include <time.h>

void print_seconds_since_execution() {
    clock_t start_time = clock(); // Get the initial clock time

    while (1) {
        clock_t current_time = clock();
        double elapsed_seconds = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        printf("Seconds since execution: %.2lf\n", elapsed_seconds);
        sleep(1); // Wait for one second
    }
}

int main() {
    print_seconds_since_execution();
    return 0;
}
