#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#define BUFFER_SIZE 5
sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
void *producer(void *arg) {
int item;
while (1) {
item = rand() % 100; // Generate a random item to produce
sem_wait(&empty);
sem_wait(&mutex);
buffer[in] = item;
printf("Produced: %d\n", item);
in = (in + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&full);
sleep(rand() % 3); // Simulate some processing time
}
}
void *consumer(void *arg) {
int item;
while (1) {
sem_wait(&full);
sem_wait(&mutex);
item = buffer[out];
printf("Consumed: %d\n", item);
out = (out + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&empty);
sleep(rand() % 3); // Simulate some processing time
}
}
int main() {
pthread_t producer_thread, consumer_thread;
// Initialize semaphores
sem_init(&mutex, 0, 1);
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&full, 0, 0);
// Create producer and consumer threads
pthread_create(&producer_thread, NULL, producer, NULL);
pthread_create(&consumer_thread, NULL, consumer, NULL);
// Join threads
pthread_join(producer_thread, NULL);
pthread_join(consumer_thread, NULL);
// Destroy semaphores
sem_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);
return 0;
}
