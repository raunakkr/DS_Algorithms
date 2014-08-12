//Finds maximum contigous sum in an array
#include<stdio.h>

int a[]={-2, -3, -4,-1};
int n;

//Returns maximum of two nos.
  int max(int a,int b){
	 return a>b?a:b;
  }


 int find_max_sum(){

	int i,cur_sum,max_sum;
	cur_sum=a[0];
	max_sum=a[0];

	for(i=1;i<n;i++){

		cur_sum=max(a[i],a[i]+cur_sum);
		max_sum=max(max_sum,cur_sum);
}

  return max_sum;



 }


void main(){

  n=sizeof(a)/sizeof(a[0]);
  printf("Maximum contiguous sum in given array is  %d",find_max_sum());

}