#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELIMITER '$'

// Function to parse the integer array from command line argument
void parseArray(char *arg, int *array, int *size) {
    *size = 0;
    while (*arg != '\0') {
        if (*arg != DELIMITER) {
            array[*size] = atoi(arg);
            (*size)++;
            while (*arg != DELIMITER && *arg != '\0') {
                arg++;
            }
        } else {
            arg++;
        }
    }
}

// Function to calculate sum of elements in the array
int calculateSum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to calculate average of elements in the array
float calculateAverage(int *array, int size) {
    int sum = calculateSum(array, size);
    return (float)sum / size;
}

// Function to find maximum number in the array
int findMax(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <integer_array_delimited_by_%c>\n", argv[0], DELIMITER);
        return 1;
    }

    // Parse the integer array from command line argument
    int array[100];
    int size;
    parseArray(argv[1], array, &size);

    // Fork three child processes
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (i == 0) {
                // Child 1: Calculate and print sum
                int sum = calculateSum(array, size);
                printf("Sum: %d\n", sum);
            } else if (i == 1) {
                // Child 2: Calculate and print average
                float average = calculateAverage(array, size);
                printf("Average: %.2f\n", average);
            } else if (i == 2) {
                // Child 3: Find and print maximum number
                int max = findMax(array, size);
                printf("Maximum: %d\n", max);
            }
            exit(0);
        } else if (pid < 0) {
            // Error forking process
            printf("Error forking process %d\n", i);
            return 1;
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}

