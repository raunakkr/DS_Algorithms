 //Though it;s working but not a good approach
#include<stdio.h>
int *f();

void main()
{
printf("%d",*f());
 }

int *f(){
int a=2;
int *p=&a;
return p;

}