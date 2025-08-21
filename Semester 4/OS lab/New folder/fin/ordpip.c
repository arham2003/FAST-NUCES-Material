#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd[2]; // File descriptors for the pipe
    pid_t childpid;
    char buffer[BUFFER_SIZE];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    if ((childpid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (childpid == 0) { // Child process
        close(pipefd[1]); // Close the write end of the pipe

        // Read from the pipe
        ssize_t num_bytes = read(pipefd[0], buffer, BUFFER_SIZE);
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Null-terminate the received string
        buffer[num_bytes] = '\0';

        printf("Child received: %s\n", buffer);

        close(pipefd[0]); // Close the read end of the pipe in the child
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        const char *message = "Hello, child!";

        // Write to the pipe
        ssize_t num_bytes = write(pipefd[1], message, strlen(message));
        if (num_bytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]); // Close the write end of the pipe in the parent
    }

    return 0;
}
