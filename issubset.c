//Program to check if there is a subset with given sum in an array
#include<stdio.h>

int n;

int is_subset_sum(int a[],int i,int j,int sum){

	 if(sum==0){
     printf("%d%d",i,j);
	  return 1;
					}
	  if(i>j || i>n-1)
	  return 0;







	return is_subset_sum(a,i+1,j,sum-a[i]) || is_subset_sum(a,i+1,j,sum);



}







void main(){


  int a[]={14,2,3,4,7,3};
int sum=12;
n=sizeof(a)/sizeof(a[0]);
  if(is_subset_sum(a,0,n-1,sum))
	printf("Subset with sum %d found",sum);
	else
   printf("No subset with sum %d found",sum);



}