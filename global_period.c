#define _POSIX_C_SOURCE 199309L // Required for timer functions

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#define PERIOD_NS 1000000000 // Period in nanoseconds (1 second)

timer_t timerid;

void task1_handler(int sig, siginfo_t *si, void *uc) {
    printf("Task 1 released\n");
}

void task2_handler(int sig, siginfo_t *si, void *uc) {
    printf("Task 2 released\n");
}

void task3_handler(int sig, siginfo_t *si, void *uc) {
    printf("Task 3 released\n");
}

int main() {
    struct sigaction sa;
    struct itimerspec its;

    // Set up signal handler for task 1
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = task1_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Set up signal handler for task 2
    sa.sa_sigaction = task2_handler;
    if (sigaction(SIGRTMIN + 1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Set up signal handler for task 3
    sa.sa_sigaction = task3_handler;
    if (sigaction(SIGRTMIN + 2, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Create timer
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = &timerid;
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        perror("timer_create");
        exit(EXIT_FAILURE);
    }

    // Set timer to trigger every period
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = PERIOD_NS;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = PERIOD_NS;
    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        perror("timer_settime");
        exit(EXIT_FAILURE);
    }

    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}
