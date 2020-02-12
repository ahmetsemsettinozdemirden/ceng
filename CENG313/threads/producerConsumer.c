#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 20
#define MAX_PRODUCER 15
#define MAX_CONSUMER 5

pthread_mutex_t isEmpty = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t isFull = PTHREAD_MUTEX_INITIALIZER;

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

//pthread_mutex_t emptySizeIndex[BUFFER_SIZE] = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t fullSizeIndex[BUFFER_SIZE] = PTHREAD_MUTEX_INITIALIZER;

int buffer[BUFFER_SIZE];
int fullCount = 0;
int emptyCount = BUFFER_SIZE;
int added;
int collected;

int findFree()
{
	int i;
	for (i = 0; i<BUFFER_SIZE; i++)
	{
		if (buffer[i] == 0)
			return i;
	}

	//it is full
	return i;
}

int findFull()
{
	int i;
	for (i = 0; i<BUFFER_SIZE; i++)
	{
		if (buffer[i] != 0)
			return i;
	}

	//it is empty
	return i;
}


void *myProducer(void* arg)
{
	int x, y, z;

	do
	{
		int producerID = *((int *)arg);
		x = (rand() % 10) + 50;

		pthread_mutex_lock(&isEmpty);
		
		y = findFree();
		
		added++;
		buffer[y] = x;
		printf("%d is produced by Producer #%d and added to %d value of buffer\n", x, producerID, y);
	
		pthread_mutex_unlock(&isFull);


	} while (1);

	//return 1;
}

void *myConsumer(void* arg)
{
	do
	{
		int consumerID = *((int *)arg);
		int y = 0;

		pthread_mutex_lock(&isFull);
		
		y = findFull();	

		collected++;
		printf("%d is consumed by Consumer #%d from buffer at index=%d\n", buffer[y], consumerID, y);
		buffer[y] = 0;	

		pthread_mutex_unlock(&isEmpty);
		
	} while (1);

	//return 1;
}

int main()
{
	int i;
	int targetThreadID, exitCode = 0;
	
	pthread_t tid[MAX_PRODUCER + MAX_CONSUMER];
	pthread_attr_t attr[MAX_PRODUCER + MAX_CONSUMER];
	
	srand(time(NULL));

	added = 0;
	collected = 0;

	for (i = 0; i<BUFFER_SIZE; i++)
	{
		buffer[i] = 0;
	}


	for (i = 0; i<MAX_PRODUCER; i++)
	{
		void *memory = malloc(sizeof(int));
		int* p = (int *)memory;
		*p = i+1;
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], myProducer, p);
	}

	for (i = 0; i<MAX_CONSUMER; i++)
	{
		void *memory = malloc(sizeof(int));
		int* p = (int *)memory;
		*p = i+1;
		pthread_attr_init(&attr[i + MAX_PRODUCER]);
		pthread_create(&tid[i + MAX_PRODUCER], &attr[i + MAX_PRODUCER], myConsumer, p);
	}

	for (i = 0; i<(MAX_PRODUCER + MAX_CONSUMER); i++)
	{
		pthread_join(tid[i], NULL);
	}


	//sleep(1);

	printf("*******\n%d\ttimes value is added \n", added);
	printf("*******\n%d\ttimes value is collected \n", collected);


	system("pause");
	return 0;
}
