#include <stdio.h>
#include <pthread.h>
#define THREAD_NO 10

void *mythread(void *arg) {
    int id = *(int *)arg;
    printf("my id is %d\n", id);
    free(arg);
    return NULL;
}

int main(){
    pthread_t p[THREAD_NO];

    int i = 0;
    for(i=0; i<THREAD_NO; i++){
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&p[i], NULL, mythread, arg);
    }

    for(i=0; i<THREAD_NO; i++){
	    pthread_join(p[i], NULL);
    }
    return 0;
}
