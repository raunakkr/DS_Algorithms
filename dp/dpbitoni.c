//Longest bitonic subsequence :: Recursive & Dynamic Programming implementation
#include<stdio.h>
	int a[]={8,7,6,5,9};
	 int n,lis_a[20],dis_a[20];
  //Returns maximum of two nos.
  int max(int a,int b){
  return a>b?a:b;}


  //>>>>>>>>>>We can compute in top down way from i=0...only one loop is required
int lis(int p){
  int i,j,maxt=0;
if(p==0)
return 0;

if(p<0)
	return 0;

for(i=p-1;i>=0;i--){
	if(a[i]<a[p])
  maxt= max(maxt,1+lis(i)); }



  return maxt;

 }

 //Lis_main

 int lis_main(){
	 int i,maxt=0;
	 if(n==0)
	 return 0;
  for(i=n-1;i>=0;i--){
	  lis_a[i]=1+lis(i);
 maxt=max(maxt,lis_a[i]);}

	return maxt;

 }

 //longest decreasing subsequence utility
 int dis(int p){
  int i,j,maxt=0;
if(p==n-1)
return 0;

if(p>n-1)
	return 0;

for(i=p+1;i<=n-1;i++){
	if(a[i]<a[p])
  maxt= max(maxt,1+dis(i)); }



  return maxt;

 }

//Dis_main

 int dis_main(){
	 int i,maxt=0;
	 if(n==0)
	 return 0;
  for(i=n-1;i>=0;i--){
  dis_a[i]=1+dis(i);
 maxt=max(maxt,dis_a[i]); }

	return maxt;

 }

//Longest bitonic subsequence
	int longest_bitonic_subsequence(){
  //uncomment these lines if below functions not called in main
	//lis_main();
	//dis_main();

  int i,j,maxt=0;
  for(i=0;i<n;i++)
	  maxt=max(lis_a[i]+dis_a[i]-1,maxt);

	  return maxt;
	}


void main(){

n=sizeof(a)/sizeof(a[0]);

printf("Longest increasing sequence is %d\n",lis_main());
printf("Longest decreasing sequence is %d\n",dis_main());
printf("Longest bitonic sequence is %d\n",longest_bitonic_subsequence());
}