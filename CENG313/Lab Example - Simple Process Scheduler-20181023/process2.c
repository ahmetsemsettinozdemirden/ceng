#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){

	char buf[30];
	sprintf(buf, "process2 started running \n");	
	write(1, buf, strlen(buf));

	sleep(4);	

	return 0;
}
