//Program to count no. of ways to make a change (Order matters)
#include<stdio.h>
  int a[]={1,2,3,4};
  int n;




int no_of_ways_to_make_change(int sum){

	 int t=0,i;

	 if(sum==0)return 1;
    if(sum<0)return 0;

	 for(i=0;i<n;i++)
		t+=no_of_ways_to_make_change(sum-a[i]);

		return t;





}



void main(){

n=sizeof(a)/sizeof(a[0]);
printf("No. of ways to make a change  %d",no_of_ways_to_make_change(3));


 }



