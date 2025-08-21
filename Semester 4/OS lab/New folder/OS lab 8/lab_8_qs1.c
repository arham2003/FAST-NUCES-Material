#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10000000

float A[ARRAY_SIZE];
float B[ARRAY_SIZE];
float C[ARRAY_SIZE];

void *thread_add(void *arg) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        C[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        A[i] = i * 1.0; 
        B[i] = i * 2.0; // Just an example initialization
    }


    pthread_create(&thread, NULL, thread_add, NULL);

 
    pthread_join(thread, NULL);

    // Printing some elements of array C
    for (int i = 0; i < 10; ++i) {
        printf("C[%d] = %.2f\n", i, C[i]);
    }

    return 0;
}

