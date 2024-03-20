#include <stdio.h>
#include <unistd.h>

void task1() {
    while (1) {
        printf("Task 1\n");
        sleep(1); // Simulating task execution time
    }
}

void task2() {
    while (1) {
        printf("Task 2\n");
        sleep(1); // Simulating task execution time
    }
}

void task3() {
    while (1) {
        printf("Task 3\n");
        sleep(1); // Simulating task execution time
    }
}

int main() {
    // Create three child processes, one for each task
    pid_t pid1 = fork();
    if (pid1 == 0) {
        task1();
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            task2();
        } else {
            task3(); // Main process executes task3
        }
    }
    return 0;
}

