#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

//determine the biggest number of an array

int a[SIZE] = {100, 140, 7, 190, 5, 1, 17, 390, 245, 112};

int main(){

    int max, i;

    max = a[0];

    for(i=1; i<SIZE; ++i){
        if(a[i]>max)
            max = a[i];
    }

    printf("\n The max element %d \n", max);
    
    return 0;
}
