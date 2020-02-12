#include<stdio.h>


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("argument count does not match\n");
		return -1;
	}

	printf("exec.c file is running!!\n");
	printf("message from parent is: %s", argv[1]);
}
