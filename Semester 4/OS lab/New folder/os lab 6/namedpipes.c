#define FIFO_FILE "/tmp/myfifo"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    fd = open(FIFO_FILE, O_RDONLY); // Open the named pipe for reading (consumer)
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Consumer loop
        num_bytes = read(fd, buffer, BUFSIZ); // Read data from the named pipe
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Consumer: Received message: %s", buffer); // Display the data sent by the producer

        if (strncmp(buffer, "exit", 4) == 0) { // Check for exit condition
            break;
        }
    }

    close(fd); // Close the named pipe

    return 0;
}
