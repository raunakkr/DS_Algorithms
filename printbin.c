//Binary no. of a decimal
#include<stdio.h>


 void print_binary(int n){

	int mask=1,i;
	mask=mask<<3;
	for(i=1;i<=4;i++) {
	  if(n&mask)printf("1");
	  else printf("0");
	  mask=mask>>1;
          }

 }



void main(){
 int i;
 for(i=0;i<10;i++){
 print_binary(i);
 printf("\n");}
}