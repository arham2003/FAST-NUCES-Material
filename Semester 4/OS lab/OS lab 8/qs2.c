#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 3

int arr_val[100];
int num_count;
double average;
int max, min;
void * fun_avg(void *arg) {
    double sum = 0.0;
    for (int i = 0; i < num_count; ++i) {
        sum += arr_val[i];
    }
    average = sum / num_count;
    pthread_exit((void *)&average);
}

void * fun_max(void *arg) {
    max = arr_val[0];
    for (int i = 1; i < num_count; ++i) {
        if (arr_val[i] > max) {
            max = arr_val[i];
        }
    }
    pthread_exit((void *)&max);
}

void * fun_min(void *arg) {
    min = arr_val[0];
    for (int i = 1; i < num_count; ++i) {
        if (arr_val[i] < min) {
            min = arr_val[i];
        }
    }
    pthread_exit((void *)&min);
}


int main(int argc, char *argv[]){
	
	int i;
	num_count = argc-1;
	if(argc < 2){
		fprintf(stderr,"Error: no values passed.");
		return 1;
	}
	
	for(i=1; i<argc; i++){
		arr_val[i-1] = atoi(argv[i]);
	}
	
	pthread_t threads[THREADS];
	
	pthread_create(&threads[0],NULL,fun_avg, NULL);
	pthread_create(&threads[1],NULL,fun_max, NULL);
	pthread_create(&threads[2],NULL,fun_min, NULL);
	
	
    
    pthread_join(threads[0], (void **)&average);
	pthread_join(threads[1], (void **)&max);
	pthread_join(threads[2], (void **)&min);
	
	printf("The average value is %.2lf.\n", average);
    printf("The minimum value is %d.\n", min);
    printf("The maximum value is %d.\n", max);
	
}
