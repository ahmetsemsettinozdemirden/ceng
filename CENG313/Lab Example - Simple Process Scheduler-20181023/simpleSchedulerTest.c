#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include"processScheduler.h"

int main(){
	
	Process *p1 = (Process*)malloc(sizeof(Process*));
	p1->processName = "./out1";
	p1->arrivalTime = 0;
	p1->executionTime = 5;	
	
	Process *p2 = (Process*)malloc(sizeof(Process*));
	p2->processName = "./out2";
	p2->arrivalTime = 3;
	p2->executionTime = 4;
	
	Process *p3 = (Process*)malloc(sizeof(Process*));
	p3->processName = "./out3";
	p3->arrivalTime = 7;
	p3->executionTime = 3;
	
	Process *readyQueue = (Process*)malloc(3*sizeof(Process*));

	readyQueue = p1;	
	*(readyQueue+1) = *p2;
	*(readyQueue+2) = *p3;

	pid_t main_pid = getpid();
	
	for(int i=0; i<3; i++){	
			
		if(main_pid == getpid()){

			pid_t pid = fork();
				
			if(pid == 0) {
				printf("children starting");										
				char *args[]= { readyQueue[i].processName,NULL };
				execvp(args[0], args);				
			} else {
				wait(NULL);		
			}
				
		}
			
	}		

	char buf[30];

	for(int i=0; i<3; i++){
		sprintf(buf, "%s is in the state : %d \n", readyQueue[i].processName);	
		write(1, buf, strlen(buf));	
	}

	return 0;
}

/*
What is the reason of using write rather than printf? It is because printf() is "buffered," meaning printf() will group the output of a process together. While buffering the output for the parent process, the child may also use printf to print out some information, which will also be buffered. As a result, since the output will not be send to screen immediately, you may not get the right order of the expected result. Worse, the output from the two processes may be mixed in strange ways. To overcome this problem, you may consider to use the "unbuffered" write.
*/


