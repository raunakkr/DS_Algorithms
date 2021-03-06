//Program to find minimum no. of coins to make a sum
#include<stdio.h>
#include<limits.h>
//Coin array
int a[]={1,2,5,10,50};
int n;


//Returns minimum of two nos.
int min(int a,int b){
 return a<b?a:b;
}

//Recursive implementation
int min_coin(int sum){

 int i,mint=INT_MAX;
  if(sum==0)return 0;
  if(sum<0) return 9999;  //Prefer sufficiently large value as adding to INT_MAX will make it somehow -ve
for(i=0;i<n;i++)
  mint=min(mint,1+min_coin(sum-a[i]));

  return mint;
}

//Dynamic Programming Implementation
int DP_min_coin(int sum){
	int s[51],i,j,mint;
	if(sum==0)return 0;
	  s[0]=0;

  for(i=1;i<=sum;i++)
		  s[i]=INT_MAX;

  for(i=0;i<n;i++)
	 //if(a[i]==sum)
	 s[a[i]]=1;

  for(i=1;i<=sum;i++) {
	  mint=9999;
	  for(j=0;j<n;j++){
				if(a[j]<i){
				mint=min(s[i-a[j]]+1,mint);
			  //printf(">>>%d  ",mint);
				  }}
		if(s[i]!=1)s[i]=mint;
	  	//printf(">>>>>>>>>>>>%d--%d\n",i,s[i]);
		//print_array(s,sum);
		}


		return s[sum];



}

void main(){
n=sizeof(a)/sizeof(a[0]);
printf("Minimum no. of coins needed to make sum- %d\n",min_coin(25));
printf("Minimum no. of coins needed to make sum -%d",DP_min_coin(25));
}