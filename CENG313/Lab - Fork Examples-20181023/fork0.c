/*
Fork system call use for creates a new process, which is called child process, which runs concurrently with process (which process called system call fork) and this process is called parent process. After a new child process created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.

It takes no parameters and returns an integer value. Below are different values returned by fork().

Negative Value: creation of a child process was unsuccessful.

Zero: Returned to the newly created child process.

Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
  
    printf("1!\n"); 
    // make two process which run same 
    // program after this instruction 
    int i;
    for (i = 0; i < 2; i++) {
        printf("2!\n"); 
        fork();
        printf("3!\n"); 
    }
  
    printf("4!\n"); 
    return 0; 
}

/*
Retrieved from:
https://www.geeksforgeeks.org/fork-system-call/
*/
