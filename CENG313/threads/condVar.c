#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

// Define mutex
pthread_mutex_t fill_mutex;

int arr[10];
int flag=0;

// Initialize conditional variable
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;

// Thread Job for filling array 
void *fill() 
{
	int i=0;
	printf("\nEnter values\n");
	for(i=0;i<5;i++) {
		scanf("%d",&arr[i]);
	}
	pthread_mutex_lock(&fill_mutex);
	printf("Filler Locked\n");

	pthread_cond_signal(&cond_var);
	printf("Signaled other Threads\n");

	pthread_mutex_unlock(&fill_mutex);
	printf("Filler Released Mutex\n");

	pthread_exit(NULL);
}

// Thread job for reading array
void *read() 
{
	int i=0;
	pthread_mutex_lock(&fill_mutex);
	printf("\nReader Locked\n");
	
	printf("Waiting for fill\n");
	pthread_cond_wait(&cond_var,&fill_mutex); // release mutex if cond_var is not signalled

	pthread_mutex_unlock(&fill_mutex);
	printf("Values filled in array are");

	for(i=0;i<5;i++) {
		printf("\n%d",arr[i]);
	}
	printf("\n");

	pthread_exit(NULL);
}


void main() {

	pthread_t thread_id,thread_id1;
	pthread_attr_t attr;

	int ret;
	void *res;

	// Create 2 threads for filling and reading array
	ret=pthread_create(&thread_id,NULL,&fill,NULL);
	ret=pthread_create(&thread_id1,NULL,&read,NULL);

	printf("\n Threads Are Created");

	// Join threads
	pthread_join(thread_id1,&res);
	pthread_join(thread_id,&res);
	
}
