//No. of ways to get sum as x in a Dice throw :: Recursive & Dynamic Programming
#include<stdio.h>


//:: Recursive implementation 
int no_of_ways_get_sum_ret(int n,int m,int x){

int i,count=0;
		if(x==0 && n==0){
		  return 1;}

		  if(n==0)
			 return 0;



	 for(i=1;i<=m;i++)
	 count+=no_of_ways_get_sum_ret(n-1,m,x-i);

	 return count;
}




void main(){
	  printf("\n%d",no_of_ways_get_sum_ret(3,6,8));
}