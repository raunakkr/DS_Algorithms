//Maximum product :: rod cutting problem (recursive)
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}

int maxprod(int n){
int maxt=0;
	int i;
  if(n==2 || n==1)
	 return 1;

  for(i=1;i<=n-1;i++)
  maxt=max(maxt,max(i*(n-i),i*maxprod(n-i)));

  return maxt;



}
int maxprodDP(int n){
int a[10],i,j,maxt=0;
a[1]=1;
a[2]=1;
  if(n==2 || n==1)
	 return 1;
  for(j=3;j<=n;j++) {
  for(i=j-1;i>=1;i--){
  maxt=max(maxt,max(i*(j-i),i*a[j-i]));

  a[j]=maxt;

 }
 }
 return a[n];


}

//Usually maximum product is found by cutting pieces of '3' except last piece of length less than 3
void main(){

printf("Using Recursion %d\n",maxprod(5));
printf("Using DP %d",maxprodDP(5));

}