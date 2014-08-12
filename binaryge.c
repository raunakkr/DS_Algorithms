//Print binary equivalent of  a decimal number
#include<stdio.h>

void printbinary(int num){
 int i;
 for(i=4;i>=1;i--)
	  num&(1<<i-1)?printf("1"):printf("0");


}

void main(){

 printbinary(7);
}