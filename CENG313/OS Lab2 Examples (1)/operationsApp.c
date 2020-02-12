#include<stdio.h>
#include<stdlib.h>
#include"operations.h"

int main(){

    float num1, num2;

    printf("Enter first number: ");
    scanf(" %f" ,&num1);

    printf("Enter second number: ");
    scanf(" %f" ,&num2);

    printf("The sum: %f + %f = %.3f \n", num1, num2, add(num1,num2));
    printf("The subtraction: %f - %f = %.3f \n", num1, num2, sub(num1,num2));
    printf("The multiplication: %f * %f = %.3f \n", num1, num2, mult(num1,num2));
    printf("The division: %f / %f = %.3f \n", num1, num2, divi(num1,num2));

    return 0;
}
