//Print how many ways can a string be decoded  using dynamic programming
#include<stdio.h>

  int a[]={3,1,1,3,1,6};
  char d[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
	int n;

	int p[7]={1};

		 int max(int a,int b){

         return a>b?a:b;
		 }


 int find_decode_ways(){
	  int i;
	 p[n]=0;
	 p[n-1]=1;


	//from second last element
	 for(i=n-2;i>=0;i--){

		 if(a[i]==1 && i+1<=n-1)
			p[i]=max(1,p[i+1])+max(1,p[i+2]);

		 else  if(i+2<=n-1 && a[i]==2  && a[i+1]<7)
				  p[i]=max(1,p[i+1])+max(1,p[i+2]);

			else if(i+1<=n-1)
			  p[i]=max(1,p[i+1]);



	 }

	  return p[0];
 }









void main(){

n=sizeof(a)/sizeof(a[0]);
printf("No. of ways to decode a given string - %d",find_decode_ways(0,n-1,0));



}