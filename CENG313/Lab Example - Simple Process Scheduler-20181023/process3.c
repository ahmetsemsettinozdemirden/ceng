#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){

	char buf[30];
	sprintf(buf, "process3 started running \n");	
	write(1, buf, strlen(buf));

	sleep(3);

	return 0;
}
