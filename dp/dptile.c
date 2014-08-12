//Program to find no. of ways to tile a floor of "2XN" using 1x2 & 2x1 tiles
#include<stdio.h>


//Recursive Implementation
int count_tiling_ways(int n){

  if(n<=0)
  return 0;
  if(n==1)return 1;
  if(n==2)return 2;



	 return count_tiling_ways(n-2)+count_tiling_ways(n-1);

}
//We can easily convert this recursive implementation into dynamic programming approach


void main(){

	 printf("No.of ways to tile a floor- %d",count_tiling_ways(5));


}