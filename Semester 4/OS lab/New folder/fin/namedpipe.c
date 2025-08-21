#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 1024

int main() {
    int fifo_fd;
    char buffer[BUFFER_SIZE];

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_NAME, 0666);

    // Open the FIFO for writing
    fifo_fd = open(FIFO_NAME, O_WRONLY);
    if (fifo_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Producer process: Enter message to send (type 'exit' to quit)\n");

    while (1) {
        printf(">> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Check for exit command
        if (strcmp(buffer, "exit\n") == 0)
            break;

        // Write to the FIFO
        if (write(fifo_fd, buffer, strlen(buffer)) == -1) {
            perror("write");
            close(fifo_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Close the FIFO
    close(fifo_fd);

    return 0;
}
