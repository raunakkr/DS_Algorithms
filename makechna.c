#include<stdio.h>
	int count=0;
	 char ot[20];
    //>>Function starts here
	 int count_ways_for_change(int i,int pos){
	if(i==0){
	count++;
   ot[pos]='\0';
	printf("%s\n",ot);
	return;}


  	if(i>=1) {
	 ot[pos]='1';
	 count_ways_for_change(i-1,pos+1);
	 }

	 if(i>=2){
	 ot[pos]='2';
	 count_ways_for_change(i-2,pos+1);
	 }

	if(i>=3){
	 ot[pos]='3';
	count_ways_for_change(i-3,pos+1); }

}



void main(){

	 count_ways_for_change(4,0);

	 printf("No. of ways to make change-  %d\n",count);

}