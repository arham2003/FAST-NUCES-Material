#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define MAX_NUMBERS 100

// Structure to pass data to the threads
struct ThreadData {
    int *numbers;
    int size;
};

// Function to calculate average value
void *average(void *threadData) {
    struct ThreadData *data = (struct ThreadData *)threadData;
    double sum = 0;
    for (int i = 0; i < data->size; i++) {
        sum += data->numbers[i];
    }
    double avg = sum / data->size;
    pthread_exit((void *)(long)avg);
}

// Function to calculate maximum value
void *maximum(void *threadData) {
    struct ThreadData *data = (struct ThreadData *)threadData;
    int max = data->numbers[0];
    for (int i = 1; i < data->size; i++) {
        if (data->numbers[i] > max) {
            max = data->numbers[i];
        }
    }
    pthread_exit((void *)(long)max);
}

// Function to calculate minimum value
void *minimum(void *threadData) {
    struct ThreadData *data = (struct ThreadData *)threadData;
    int min = data->numbers[0];
    for (int i = 1; i < data->size; i++) {
        if (data->numbers[i] < min) {
            min = data->numbers[i];
        }
    }
    pthread_exit((void *)(long)min);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number1> <number2> ... <numberN>\n", argv[0]);
        return 1;
    }

    int numbers[MAX_NUMBERS];
    int size = argc - 1;
    if (size > MAX_NUMBERS) {
        printf("Exceeded maximum number of input numbers.\n");
        return 1;
    }

    // Convert command-line arguments to integers
    for (int i = 0; i < size; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData = {numbers, size};
    void *result;

    // Create threads to calculate average, maximum, and minimum values
    pthread_create(&threads[0], NULL, average, (void *)&threadData);
    pthread_create(&threads[1], NULL, maximum, (void *)&threadData);
    pthread_create(&threads[2], NULL, minimum, (void *)&threadData);

    // Wait for all threads to finish and retrieve their results
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &result);
        if (i == 0) {
            printf("The average value is %.2f.\n", (double)(long)result);
        } else if (i == 1) {
            printf("The maximum value is %ld.\n", (long)result);
        } else {
            printf("The minimum value is %ld.\n", (long)result);
        }
    }

    return 0;
}
