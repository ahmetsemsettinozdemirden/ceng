#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BILLION 1E9

// maximum size of matrix 
#define MAX 1000

// maximum number of threads 
#define MAX_THREAD 1000

int matA[MAX][MAX]; 
int matB[MAX][MAX]; 
int matC[MAX][MAX]; 
int step_i = 0;
void* multi(void* arg) 
{ 
	//int core = step_i++; 
	int core = *((int*)arg);

	// Each thread performs 1/MAX_THREAD of multiplication 
	for (int i = core * MAX / MAX_THREAD; i < (core + 1) * MAX / MAX_THREAD; i++) 
		for (int j = 0; j < MAX; j++) 
			for (int k = 0; k < MAX; k++) 
				matC[i][j] += matA[i][k] * matB[k][j]; 
} 


int main() 
{ 
	//srand(time(NULL));
	// Generating random values in matA and matB 
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) { 
			matA[i][j] = (rand() % 10) + 1; 
			matB[i][j] = (rand() % 10) + 1; 
		} 
	} 

	// Displaying matA 
	/*printf("\nMatrix A\n"); 
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d ",matA[i][j]); 
		printf("\n"); 
	}
	*/ 
	printf("Matrix A Generated\n");

	// Displaying matB 
	/*printf("\nMatrix B\n");
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d ",matB[i][j]);		 
		printf("\n");  
	} 
*/
	printf("Matrix B Generated\n");
	// declaring N threads 
	pthread_t threads[MAX_THREAD]; 
	//pthread_attr_t attr[MAX_THREAD];

	
	// Creating MAX_THREAD threads 
	for (int i = 0; i < MAX_THREAD; i++) { 
		int* p = malloc(sizeof(int));
		*p=i; 
		pthread_create(&threads[i], NULL, multi, p); 
	} 

	struct timespec requestStart, requestEnd;
	//Start timer
	
	//clock_t begin = clock();
	clock_gettime(CLOCK_REALTIME, &requestStart);
	// joining all threads 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL);	 

	//End timer
	clock_gettime(CLOCK_REALTIME, &requestEnd);

// Calculate time it took
double accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec ) / BILLION;



	//clock_t end = clock();
	//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 

	// Print Final matrix 
	printf("\nMultiplicationf of A and B\n");
 
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d ",matC[i][j]);		 
		printf("\n");  
	}

	
	printf("Total time spent %lf, for %d threads\n", accum, MAX_THREAD);
	//printf("Total time spent %lf, for %d threads\n",time_spent, );

	return 0; 
} 

