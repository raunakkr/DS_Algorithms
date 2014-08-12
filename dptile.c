#include<stdio.h>

	int count=0;

	 int c,n;


void count_tiling_ways(int area){

  if(area==0)        {
		count++;return;}

  if(area<0)
  return;

	  //count_tiling_ways(area-c);
	  //>>>>>>>>>>>>>>>>>>>>>
	  count_tiling_ways(c,n-c);
	  count_tiling_ways(c-1,n-c);

}


void main(){
	 c=4;
	 n=7;
	 	count_tiling_ways(28);
		printf("%d",count);




}