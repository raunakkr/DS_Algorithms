//Program to convert a float number to string without any  inbuilt function

#include<stdio.h>

 char ot[10];
 int k,numsize;

 void ins(int num){

	while(num>0)
	{
	  ot[numsize]=(char)num%10;
	  num=num/10;
	  numsize--;
	}

 }

 int findsize(int num){

	 int count=0;
	 while(num>0){

		num=num/10;
		count++;

	 }

	 return count;

 }

 void insutil(int befo,int aft){

	  ot[numsize+1]='\0';
	  ins(aft);
	  ot[numsize]='.';
	  ins(befo);
 }

void main(){

 float i=23.45;
  //Get the number before decimal here
 int befo=(int)i;
  //Get the number after decimal here
 float aft=(i-befo);

 //Get the total length of number
    printf("%d  %d",befo,(int)aft);
	 numsize=findsize(befo)+findsize(aft)+1;  //Plus 1 for decimal

	 insutil(befo,aft);

    printf("%s",ot);



}