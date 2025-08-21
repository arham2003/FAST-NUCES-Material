#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function to handle SIGALRM
void handleAlarm(int signum) {
    printf("\nAlarm signal received. Terminating program.\n");
    // Exit the program gracefully
    exit(0);
}

int main() {
    // Set up signal handler for SIGALRM
    signal(SIGALRM, handleAlarm);

    // Set an alarm for 5 seconds
    alarm(5);

    // Sleep loop to print a message every second
    for (int i = 1; ; i++) {
        printf("Message %d\n", i);
        sleep(1);
    }

    return 0;
}

