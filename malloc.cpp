//program making use of four functions: malloc(),calloc(),realloc(),free()
#include<stdio.h>
#include<stdlib.h>
void main(){

int *p;
p=(int*)malloc(sizeof(int));
printf("Enter any no. to be allocated dynamically using malloc");
scanf("%d",p);

printf("%d%d%d",p,*p);



}