//check whether sum or subtraction yields zero or not
#include<stdio.h>
#include<stdlib.h>

int a[]={1,2,3};
int n=3,flag=0;

  int checksum(int i,int j){
		 int lsum=0,rsum=0;
	  if(i==n-1)
	  return a[i];
	 if(i>j || j>n-1)
	 return 0;

	  if(a[i]+checksum(i+1,j)==3)
	  printf("y");


//rsum=a[i]-checksum(i+1,j);


		  // return 0;


}

void main(){
checksum(0,2);
//?printf("");printf
//if(!flag)
//printf("No");
	 }
