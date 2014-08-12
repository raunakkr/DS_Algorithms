#include<stdio.h>
	int a[]={1,2,3};
 int ot[10];
 int n;
void unique_t(int j,int pos,int sum){


  int i;


  if(sum==0){
	 for(i=0;i<pos;i++)
	 printf("%d",ot[i]);
	 printf("\n");
	 return;
  }

  if(j>n-1 || sum<0)
 return;

		ot[pos]=a[j];
  unique_t(j,pos+1,sum-a[j]);
  unique_t(j+1,pos,sum);


}




void main(){
n=sizeof(a)/sizeof(a[0]);
unique_t(0,0,4);


}