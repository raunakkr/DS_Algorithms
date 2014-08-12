//Maximize stock trading profit :: Three actions 1>buy one share 2>sell any no. of shares you own 3>No transaction at all
#include<stdio.h>
#include<limits.h>

  int max(int a,int b){return a>b?a:b;}

int max_profit(int a[],int n,int balance,int i,int noofshare){

  int j,p,q,r;
  int maxt=INT_MIN;

		if(i==n-1 && noofshare>=1) return balance+(noofshare*a[i]);
		if(i==n-1 && noofshare<=0) return balance;

	p= max_profit(a,n,balance-a[i],i+1,noofshare+1);
	q=max_profit(a,n,balance,i+1,noofshare);

 if(noofshare>=1){ for(j=1;j<=noofshare;j++) {
		 r=max_profit(a,n,balance+j*a[i],i+1,noofshare-j);
		 maxt=max(max(max(p,q),r),maxt);  }     }

		 else maxt= max(max(p,q),maxt);

		 return maxt;
}


// ::Dynamic programming implementation
 int max_profit_DP(int a[],int n){
	  int r,s,t,balance=0;
	  int noofshare=0;
	  int p[50][50];

  for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
		 p[i][j]=INT_MIN;

		for(j=n-1;j>=0;j--)
		  p[n-1][]



 }




int main(){
  int a[]={5,3,2};
	int n=sizeof(a)/sizeof(a[0]);
	printf("%d",max_profit(a,n,0,0,0));
}