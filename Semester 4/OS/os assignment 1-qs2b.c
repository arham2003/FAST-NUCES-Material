#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>

void fun_collatzConjecture(int n, int *sequence) {
    int i = 0;
    while (n != 1) {
        sequence[i++] = n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    sequence[i] = 1;
}

int main(int c, char *argv[]) {
    if (c < 2) {
        fprintf(stderr, "No arguments passed for %s\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int n = atoi(argv[1]);

    int shm_fd = shm_open("/collatz_shared_memory", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        fprintf(stderr, "shm_open failed\n");
        return 1;
    }
    
    if (ftruncate(shm_fd, 4096) == -1) {
        fprintf(stderr, "ftruncate failed\n");
        return 1;
    }

    
    int *shared_memory = (int *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_memory == MAP_FAILED) {
        fprintf(stderr, "mmap failed\n");
        return 1;
    }

    
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        fun_collatzConjecture(n, shared_memory);
        return 0;
    } else {
        // Parent process
        wait(NULL); 

        
        printf("Collatz sequence for %d: ", n);
        for (int i = 0; shared_memory[i] != 1; ++i) {
            printf("%d, ", shared_memory[i]);
        }
        printf("1\n");

       
        if (munmap(shared_memory, 4096) == -1) {
            fprintf(stderr, "munmap failed\n");
            return 1;
        }
        if (close(shm_fd) == -1) {
            fprintf(stderr, "close failed\n");
            return 1;
        }
        if (shm_unlink("/collatz_shared_memory") == -1) {
            fprintf(stderr, "shm_unlink failed\n");
            return 1;
        }
    }

    return 0;
}

