//Longest increasing subsequence
#include<stdio.h>
int a[]={2,1,5,7,6,3,9};
int n;

//Returna maximum of two nos.
int max(int a,int b){
return a>b?a:b;}

	//Longest increasing subsequence including a[p]
int lis(int p){

  int i,maxt=1;
  if(p==0)
	 return 1;
	 if(p<0 || p>n-1)
	 return 0;


  for(i=p-1;i>=0;i--){
	  if(a[i]<a[p])
	 maxt=max(maxt,1+lis(i));
	 }

	return maxt;



}














void main(){
n=sizeof(a)/sizeof(a[0]);

printf("%d",lis(6));


}