// Maximum sum increasing subsequence :: Recursive & Dynamic Programming
#include<stdio.h>
int a[]={10,5,4,3};
int n;
int max(int a,int b){return a>b?a:b;}



  //>>>>>>>>>>We can compute in top down way from i=0...only one loop is required
int lis(int p){
  int i,j,maxt=a[p];
if(p==0)
return a[0];

if(p<0)
	return 0;

for(i=p-1;i>=0;i--){
	if(a[i]<a[p])
  maxt= max(maxt,a[p]+lis(i)); }



  return maxt;

 }

 //Lis_main

 int lis_main(){
	 int i,maxt=0;
	 if(n==0)
	 return 0;
  for(i=n-1;i>=0;i--){
 maxt=max(maxt,lis(i));}

	return maxt;

 }




void main(){

n=sizeof(a)/sizeof(a[0]);
  printf("%d",lis_main());

}