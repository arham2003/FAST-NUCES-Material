#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;

void *runner(void *parameters){
	int i, upper = *( (int *)parameters);
	
	if(upper > 0){
		for(i=1; i<= upper; i++){
			sum= sum + i;
		}
	}
	pthread_exit(0);
}

int main(){

	pthread_t thread1;
	pthread_attr_t attributes;
	int num= 5;
	
	pthread_attr_init(&attributes);
	pthread_create(&thread1, &attributes, runner,(void *)&num);
	pthread_join(thread1, NULL);
	printf("sum=%d\n", sum);
	exit(0);
}
