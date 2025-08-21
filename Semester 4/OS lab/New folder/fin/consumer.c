#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define SHARED_MEM_NAME "/home/aaryan/Desktop/fin/"
#define BUFFER_SIZE 1024

int main() {
    int shm_fd;
    char *shared_memory;
    FILE *file;

    // Open the shared memory object
    shm_fd = shm_open(SHARED_MEM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the address space of the process
    shared_memory = (char *)mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Open the file
    file = fopen("shared.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read data from file
    fread(shared_memory, sizeof(char), BUFFER_SIZE, file);
    printf("Data read from shared memory:\n%s\n", shared_memory);

    // Close the file
    fclose(file);

    // Unmap the shared memory object
    if (munmap(shared_memory, BUFFER_SIZE) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // Close the shared memory file descriptor
    close(shm_fd);

    return 0;
}
