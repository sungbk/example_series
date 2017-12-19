#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
	int i;

	for(i=0;i<20;i++) {
		printf("Thread running i is \'%d\'\n", i);
		sleep(1);
	}

	return;
}

int main(void)
{
	pthread_t mythread;

	if (pthread_create(&mythread, NULL, thread_function, NULL)) {
		printf(" error creating thread.\n");
		return -1;
	}

	if (pthread_join(mythread, NULL)) {
		printf("error joining thread.\n");
		return -1;
	}

	return 0;
}
