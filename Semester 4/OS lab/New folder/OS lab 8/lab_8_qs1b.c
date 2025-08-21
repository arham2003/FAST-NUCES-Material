#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10000000
#define NUM_THREADS 10

float A[ARRAY_SIZE];
float B[ARRAY_SIZE];
float C[ARRAY_SIZE];

// Function to be executed by each thread
void *thread_add(void *arg) {
    int thread_id = *((int *)arg);
    int workload_per_thread = ARRAY_SIZE / NUM_THREADS;
    int start = thread_id * workload_per_thread;
    int end = (thread_id + 1) * workload_per_thread;

    for (int i = start; i < end; ++i) {
        C[i] = A[i] + B[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize arrays A and B
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        A[i] = i * 1.0; // Just an example initialization
        B[i] = i * 2.0; // Just an example initialization
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_add, (void *)&thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Printing some elements of array C as a sample
    for (int i = 0; i < 10; ++i) {
        printf("C[%d] = %.2f\n", i, C[i]);
    }

    return 0;
}

