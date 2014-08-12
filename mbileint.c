//Print all possible interleaving combination from a mobile keypad

#include<stdio.h>

char *str[]={"abc","def","ghi"};
int n;
 char ot[20];


void print_mobile_interleavings(int i,int pos){

	 int j=0;

	 if(i>n-1){
	 printf("%s",ot);
	 printf("\n");
	 return;

	 }
	  while(*(str[i]+j)!='\0'){
	 ot[pos]=*(str[i]+j);
	 print_mobile_interleavings(i+1,pos+1);
		 j++;

  }


}



void main(){

  n=sizeof(str)/sizeof(str[0]);
  print_mobile_interleavings(0,0);
}