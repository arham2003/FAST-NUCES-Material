#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SHARED_MEM_NAME "/home/aaryan/Desktop/fin/"
#define BUFFER_SIZE 1024
#define FILE_PATH "shared.txt"

int main() {
    int shm_fd;
    char *shared_memory;
    FILE *file;

    // Create the shared memory object
    shm_fd = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Set the size of the shared memory object
    if (ftruncate(shm_fd, BUFFER_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the address space of the process
    shared_memory = (char *)mmap(NULL, BUFFER_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Open the file
    file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write data to shared memory and file
    strcpy(shared_memory, "Hello, this is shared data!\n");
    fwrite(shared_memory, sizeof(char), BUFFER_SIZE, file);

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
