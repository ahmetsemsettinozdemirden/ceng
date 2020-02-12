#include <stdio.h>
#include <stdlib.h>

int addition(int x, int y);

int main()
{

    int a, b, c;

    printf("\n insert a= ");
    scanf(" %d", &a);

    printf("\n insert b= ");
    scanf(" %d", &b);

    c = addition(a,b);

    printf("\n a+b = %d", c);
    printf("\n");

    return 0;
}

int addition(int x, int y){
    int z;
    z= x+y;
    return z;
}
