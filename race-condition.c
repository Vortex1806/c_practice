#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *routine(){
    for(int i = 0; i < 100000;i++){

        mails++;

        //read mails
        // increment value
        // write to memory

        /*
        line 25 in assembly
        movl	mails(%rip), %eax
	    addl	$1, %eax
	    movl	%eax, mails(%rip)
        */
    }
}



int main() {
    pthread_t t1,t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("No of mails %d\n",mails); 
    return 0;
}