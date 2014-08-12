#include<stdio.h>
void main(){

  int i=4;
  int *p=&i;

  if(p)
  printf("there is address in p");
  else
  printf("Address not found");




}