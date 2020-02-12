#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

void forkexample() 
{

    // child process 
    if (fork() == 0)
	{
		char* argv[2];
		argv[0] = "/bin/ls";
		argv[1] = NULL;

		if(execv(argv[0], argv)==-1)
			printf("Error in calling exec!!");

        printf("Hello from Child!\n"); 
  	} else {
        printf("Hello from Parent!\n");
		wait(NULL);
	}
} 

int main() 
{ 
    forkexample(); 
    return 0; 
} 
