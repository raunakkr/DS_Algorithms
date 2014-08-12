//Longest increasing subsequence :: Recursive and dynamic programming implementation
#include<stdio.h>
  int a[]={2,4,6,8,1};
  int n;
//Rteurns maximum of two nos.
int max(int a,int b){return a>b?a:b;}

//Longest increasing subsequence ::  Recursive implementation
int lis(int p){
 int i,maxt=0;

 if(p==0)
	return 1;

	if(p>n-1 || p<0)
	 return 0;

 for(i=p-1;i>=0;i--){
	 if(a[i]<a[p])

	 maxt=max(maxt,lis(i));




 }

	 return maxt+1;


}

//:: Dynamic programming implementation

int lis_DP(){
 int p[20];
 int maxt=1,i,j;
  //minimum 1 as lis
 for(i=0;i<n;i++)
	  p[i]=1;


 for(i=1;i<=n-1;i++){

	  for(j=i-1;j>=0;j--){
		 if(a[j]<a[i] && p[i]<p[j]+1) 
		  p[i]=p[j]+1;

}


		maxt=max(maxt,p[i]);


 }

  return maxt;

}


void main(){
 int i,maxt=1;
n=sizeof(a)/sizeof(a[0]);

 for(i=0;i<n;i++)
	maxt=max(maxt,lis(i));


printf("Longest increasing subsequence using Recursion %d\n",maxt);
printf("Longest increasing subsequence using DP %d",lis_DP());


}