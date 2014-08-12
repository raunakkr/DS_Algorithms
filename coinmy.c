#include<stdio.h>

int a[]={1,2,3};
int ot[10];

int populate(sum,pos){
	int i;
  if(sum==0){
	 for(i=0;i<pos;i++)
		printf("%d",ot[i]);

		printf("\n");
		return;
  }

 if(sum<0)
  return 0;

	if(sum>=1){
	 ot[pos]=1;
	 populate(sum-1,pos+1);}

	if(sum>=2){
	 ot[pos]=2;
	 populate(sum-2,pos+1);}

	 if(sum>=3){
	 ot[pos]=3;
	 populate(sum-3,pos+1);}





}







void main(){



populate(4,0);



}