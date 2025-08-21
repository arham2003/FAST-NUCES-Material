#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int numbers[100];
int num_count;

void *fun_avg(void *arg) {
    double sum = 0.0;
    for (int i = 0; i < num_count; ++i) {
        sum += numbers[i];
    }
    double average = sum / num_count;
    double *result = malloc(sizeof(double));
    *result = average;
    pthread_exit(result);
}

void *fun_max(void *arg) {
    int max = numbers[0];
    for (int i = 1; i < num_count; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    int *result = malloc(sizeof(int));
    *result = max;
    pthread_exit(result);
}

void *fun_min(void *arg) {
    int min = numbers[0];
    for (int i = 1; i < num_count; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    int *result = malloc(sizeof(int));
    *result = min;
    pthread_exit(result);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers...>\n", argv[0]);
        return 1;
    }

    num_count = argc - 1;
    for (int i = 1; i < argc; ++i) {
        numbers[i - 1] = atoi(argv[i]);
    }

    pthread_t threads[NUM_THREADS];
    double *average;
    int *maximum, *minimum;

    pthread_create(&threads[0], NULL, fun_avg, NULL);
    pthread_create(&threads[1], NULL, fun_max, NULL);
    pthread_create(&threads[2], NULL, fun_min, NULL);

    pthread_join(threads[0], (void **)&average);
    pthread_join(threads[1], (void **)&maximum);
    pthread_join(threads[2], (void **)&minimum);

    printf("The average value is %.2lf.\n", *average);
    printf("The minimum value is %d.\n", *minimum);
    printf("The maximum value is %d.\n", *maximum);

    free(average);
    free(maximum);
    free(minimum);

    return 0;
}

