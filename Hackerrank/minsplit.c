//Program to find minimum splits to get a piece of chocolate of given area
#include<stdio.h>
#include<limits.h>


int min(int a,int b){return a<b?a:b;}
int min_no_splits(int w,int h,int area){

	 int i,j,mint,tint;
	 mint,tint=INT_MAX;
	  if(w*h==area) return 0;

	  if(w*h<area) return 9999;


	 for(i=1;i<w;i++)
		 mint=min(mint,1+min_no_splits(i,h,area));


	for(j=1;j<h;j++)
		 tint=min(tint,1+min_no_splits(w,j,area));

	  return min(mint,tint);
}





int main(){
	int w,h,area;
	w=5;
	h=4;
	area=12;

	printf("Minimum splits needed is  %d",min_no_splits(w,h,area));

return 0;
}
