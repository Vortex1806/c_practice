#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine(){
    printf("Test from threads\n");
    sleep(3);
    printf("Ending threadd %d\n",getpid());
}


void *r1(){
    x++;
    sleep(3);
    printf("Value of x in 1 %d\n",x);
}

void *r2(){
    // x++;
    sleep(3);
    printf("Value of x in 2 %d\n",x);
}

int main() {
    pthread_t t1,t2;
    pthread_create(&t1, NULL, &r1, NULL);
    pthread_create(&t2, NULL, &r2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}