#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define ARRAY_SIZE 10000000

float A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE];

void initialize_arrays() {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        A[i] = (float)rand() / 100.0; // Random float between 0 and 1
        B[i] = (float)rand() / 100.0;
    }
}

void *sum_arrays(void *arg) {
    int thread_id = *((int *)arg);
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    for (int i = start; i < end; ++i)
        C[i] = A[i] + B[i];

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    initialize_arrays();

    // Serial version
    printf("Serial version:\n");
    clock_t serial_start = clock();
    for (int i = 0; i < ARRAY_SIZE; ++i)
        C[i] = A[i] + B[i];
    clock_t serial_end = clock();
    double serial_time = (double)(serial_end - serial_start) / CLOCKS_PER_SEC;
    printf("Time taken for serial execution: %f seconds\n\n", serial_time);

    // Concurrent version
    printf("Concurrent version:\n");
    clock_t concurrent_start = clock();
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, sum_arrays, (void *)&thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i)
        pthread_join(threads[i], NULL);

    clock_t concurrent_end = clock();
    double concurrent_time = (double)(concurrent_end - concurrent_start) / CLOCKS_PER_SEC;
    printf("Time taken for concurrent execution: %f seconds\n", concurrent_time);

	for(int i=0;i<20;i++)
	{
		printf("%f\n",A[i]);
		printf("%f\n",B[i]);
		printf("%f\n",C[i]);
	}
    return 0;
}
