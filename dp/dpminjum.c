#include<stdio.h>
#include<limits.h>

int a[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
int n;

 int min(int a,int b){

   return a<b?a:b;

 }



//:: Recursive implementation for finding min. jump needed to reach an end

	int min_jum_needed(int i){
	int mint=INT_MAX,j;
	if(i>=n-1)
	return 0;

	if(i<0)
     return INT_MAX;
	if(a[i]==0)
	return INT_MAX;

  for(j=i+1;j<=i+a[i];j++)
	 mint=min(mint,1+min_jum_needed(j));

	 return mint;



	}
  int min_jum_needed_DP(){

  int p[20],i,j,mint=INT_MAX;

  //Zero jump neeeded from last element
		p[n-1]=0;

	 for(i=n-2;i>=0;i--){
		mint=INT_MAX;
      //a[i]=0 , End can't be reached from here
			if(a[i]==0){
				p[i]=INT_MAX;
				continue;}
		for(j=i+1;j<=i+a[i];j++){
				 if(j>n-1)
               break;
		  mint=min(p[j],mint);}
		 p[i]=mint+1;
		 printf("r-%d\t",p[i]); }


	 return p[0];
  }



 void main(){

	n=sizeof(a)/sizeof(a[0]);

	printf("Min. no. of jumps needed to end reach using Recursion %d\n",min_jum_needed(0));
	printf("Min. no. of jumps needed to end reach using DP %d",min_jum_needed_DP());

 }


