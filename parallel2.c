#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ARRAY_SIZE 1000000
#define THREAD_NO 10

int sum = 0;
pthread_mutex_t lock;

void *worker(void *arg) {
    int *arr = (int *)arg;

    for(int i = 0; i < ARRAY_SIZE/THREAD_NO; i++){
        sum += arr[i]; 
    }

    return NULL;
}

int main(){
    int num[THREAD_NO][ARRAY_SIZE/THREAD_NO];

    srand(100);
    //initialize arrays
    for(int i=0; i< THREAD_NO; i++){
	for(int j=0; j< ARRAY_SIZE/THREAD_NO; j++){
            num[i][j] = rand() % 100;
	}
    }

    pthread_t threads[THREAD_NO];

    for(int i = 0; i < THREAD_NO; i++){
        pthread_create(&threads[i], NULL, worker, num[i]);
    }

    for(int i = 0; i < THREAD_NO; i++){
        pthread_join(threads[i], NULL);
    }
    
    printf("sum = %d\n", sum);
    return 0;
}
