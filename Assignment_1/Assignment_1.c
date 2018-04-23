#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <inttypes.h>
#include <limits.h>

//#defines

#define MAX_TASK_COUNT 10
#define MAX_THREAD_COUNT 9

//Typedefs

typedef struct{
	int threadCount;
	pthread_t threadId;
	int threadPolicy;
	int threadPri;
	long processTime;
	int64_t timeStamp[MAX_TASK_COUNT+1];
	time_t startTime;
	time_t endTime;
} ThreadArgs;

void *task();

int main(int argc, char *argv[])
{
	pthread_t threads[MAX_THREAD_COUNT+1];
	ThreadArgs args[MAX_THREAD_COUNT+1];
	for( int i=0; i<sizeof(threads)/sizeof(threads[0]); i++)
	{
		if(pthread_create( &threads[i], NULL, task, NULL))
		{
			printf("ERROR creating thread \n");
			exit(EXIT_FAILURE);
		}
		args[i].threadId = threads[i];
	}
	//pthread_join( threads[0], NULL );
}



void *task()
{
	unsigned int j=1;
	while(j)
		j++;
	printf("Hi\n");
}
