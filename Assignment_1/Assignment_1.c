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
	pthread_t thread1;
	
	const char *message1 = "Thread1";
	if(pthread_create( &thread1, NULL, task, NULL))
	{
		printf("ERROR creating thread \n");
		exit(0);
	}
	pthread_join( thread1, NULL );
}



void *task()
{
	unsigned int j;
	while(j<INT_MAX)
		j++;
}
