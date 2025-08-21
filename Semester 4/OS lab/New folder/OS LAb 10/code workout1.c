#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ITEMS 5
sem_t empty;
sem_t full;
int buffer[MAX_ITEMS];
int in = 0;
int out = 0;

void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MAX_ITEMS; i++) {
        item = rand(); // Produce an random item
        sem_wait(&empty);
        // Critical section
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%MAX_ITEMS;
        sem_post(&full);
    }
}

void *consumer(void *cno)
{   
    for(int i = 0; i < MAX_ITEMS; i++) {
        sem_wait(&full);
        // Critical section
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out); 
        out = (out+1)%MAX_ITEMS;
        sem_post(&empty);
    }
}

int main()
{   
    pthread_t pro[5],con[5];
    sem_init(&empty,0,MAX_ITEMS);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

