#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define	THREAD_COUNT	3

void *thread_function(void *arg)
{
	int i;
	int me;

	me = *((int *)arg);

	for(i=0;i<20;i++) {
		printf("%d Thread running i is \'%d\'\n",me, i);
		sleep(1);
	}

	return;
}

int main(void)
{
	pthread_t mythread[THREAD_COUNT];
	int thread_num[THREAD_COUNT];
	int i;

	/* Create Threads */
	for(i=0;i<THREAD_COUNT;i++) {
		thread_num[i] = i+1;
		if (pthread_create(&mythread[i], NULL, thread_function, (void*)&thread_num[i])) {
			printf("error creating %d's thread.\n", i+1);
			return -1;
		}
	}


	for(i=0;i<THREAD_COUNT;i++) {
		if (pthread_join(mythread[0], NULL)) {
			printf("error joining %d's thread.\n", i+1);
			return -1;
		}
	}

	return 0;
}
