#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int *thread_num = (int *)arg;
    printf("Thread %d is running\n", *thread_num);
    sleep(2); 
    printf("Thread %d finished\n", *thread_num);
    pthread_exit(NULL); 
    return 0;
}

int main() {
    pthread_t thread_id;
    int thread_num = 1;

    if (pthread_create(&thread_id, NULL, thread_function, &thread_num) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    printf("Main thread is waiting for the created thread to finish\n");

    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Created thread has finished. Exiting main thread.\n");

    return 0;
}
