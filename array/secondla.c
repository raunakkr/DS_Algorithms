#include<stdio.h>

int second_largest_no(int a[],int n){
	int i,l,s;

	l=a[0];s=-1;
   if(n==1)return s;
	for(i=1;i<n;i++){
	  if(a[i]>l){s=l;l=a[i];}
	 else if(a[i]>s && a[i]<l){s=a[i];}


	  }

	return s;


}


int main(){
  int a[]={8,4,2,1,5,3,6,4,9,7,22};
  int n=sizeof(a)/sizeof(a[0]);

  printf("Second largest no is  %d",second_largest_no(a,n));



}