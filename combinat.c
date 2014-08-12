#include<stdio.h>

int a[5]={1,2,3,4,5};
int data[5];
int r=4;
int n=5;


void comb(int pos,int start,int end,int num){
  int i,j,k;

  if(num==r)
	{
	for(k=0;k<r;k++)
	printf("%d",data[k]);
	printf("\n");
	return;}

  for(i=start,j=pos;i<=end && end<=n-1;i++){
	  data[j]=a[i];
	  comb(pos+1,i+1,end+1,num+1);  }


}



void  main(){

comb(0,0,n-r,0);


}