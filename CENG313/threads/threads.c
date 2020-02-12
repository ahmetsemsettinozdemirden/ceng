#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_THREADS 1000

int totalSum = 0;

// Initialize mutex
//pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

// Define thread task
void *task(void *param);

int main(int argc, char* argv[]) 
{
	pthread_t tid[NUM_OF_THREADS];
	pthread_attr_t attr[NUM_OF_THREADS];

	if(argc != 2)
	{
		fprintf(stderr, "Your program needs 2 arguments\n");
		return -1;
	}

	if(atoi(argv[1]) < 0)
	{
		fprintf(stderr, "Your argument must be a positive integer\n");
		return -2;
	}

	int i=0;

	// Initialize and create NUM_OF_THREADS amount of threads
	for(i=0; i<NUM_OF_THREADS; i++)
	{
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], task, argv[1]);
	}

	// Join and run threads
	for(i=0; i<NUM_OF_THREADS; i++)
	{
		
		pthread_join(tid[i], NULL);
		//printf("Total Sum: %d\n",totalSum);
	}

	printf("Total Sum: %d\n",totalSum);
}

// Thread Job
void *task(void *param)
{
	int i=0;
	int max = atoi(param);
	
	//pthread_mutex_lock(&mut);

	// Critical Section BEGIN
	for(i=0; i<max; i++)
	{
		totalSum++;
	}
	// Critical Section END

	//pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
	
}
