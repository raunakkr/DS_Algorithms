//Program to find the person who will get alive
#include<stdio.h>





  int find_alive_person(int start,int count,int x){
	int m;

	if (count==n-2) return start;

         if(count


		m= ((start+x)%n==0)?1:(start+2)%n;
		printf("%d>>\n",m);
	 find_alive_person(n,m,count-1,x,tc);






  }


void main(){
	  int n=10;
printf("%d",find_alive_person(6,1,6,2,6));

}