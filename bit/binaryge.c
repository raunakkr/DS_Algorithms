//Program to produce binary equivalent of a decimal number
#include<stdio.h>




int binary_equivalent(int n){

  int i;

  for(i=4;i>=1;i--){

		(n & 1<<i-1) ?printf("1"):printf("0");

  }




}


int main(){

	  binary_equivalent(8);

	  printf("\n%d",10);

return 0;
}