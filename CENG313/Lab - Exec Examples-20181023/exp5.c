#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

void forkexample() 
{

    //child process 
    if (fork() == 0)
	{
		char* argv[2];
		argv[0] = "/usr/bin/teamviewer";
		argv[1] = NULL;

		if(execv(argv[0], argv)==-1)
			printf("Error in calling exec!!");

        printf("I will not be printed too!\n"); 
  	} 

	//parent process
    else
	{
        printf("Hello from Parent!\n");
		wait(NULL);
	}



	//another child
	if (fork() == 0)
	{
		char* argv[2];
		argv[0] = "/usr/bin/steam";
		argv[1] = NULL;

		if(execv(argv[0], argv)==-1)
			printf("Error in calling exec!!");

        printf("I will not be printed!\n"); 
  	}
	//parent again
    else
	{
        printf("Hello from Parent!\n");
		wait(NULL);
	}
} 




int main() 
{ 
    forkexample(); 
    return 0; 
} 