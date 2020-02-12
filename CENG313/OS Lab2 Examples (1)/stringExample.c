#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char s1[6] = {'h','e','l','l','o', '\0'};
    char s2[6] = "hello";

    char s3[6];
    char s4[6];

    printf("Enter string s3: ");
    scanf(" %s",s3);
    printf("Enter string s4: ");
    scanf(" %s",s4);

    printf("Size of s1= %ld ",strlen(s1));

    if(!strcmp(s1,s2)) //if same:0, if s1<s2:negative, if s1>s2:positive 
        printf("The strings are equal \n");

    strcat(s1,s3); //concats s3 to the end of s1
    printf("%s \n",s1);

    strcpy(s4, "Copy"); //copies "Copy" to s4
    puts(s4);

    if(strchr("hello",'e')) //returns the first occurrence of char 'e'
        printf("e is in hello \n");
    if(strstr("hi there", "hi")) //returns the first occurrence of string 'hi'
        printf("found hi \n");

    return 0;

}
