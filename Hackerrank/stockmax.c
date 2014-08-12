//Stock buy-sell for maximum profit
#include<stdio.h>
#include<stdlib.h>


long int max_profit(long int a[],long int n){

 long	int i,count,prev,flag,pf,sum,newsum,sum_index,profit=0;
		i=0;flag=0;count=0; sum_index=0;
		prev=a[0];
      newsum=0;sum=0;pf=0;
	while(i<n){


		//sell
	  while(i<n &&  a[i]>=prev){

			 prev=a[i];
			 i++;
			 profit+=-prev;
			 count++;

	  }
		  if(i<n){ profit+=prev;count--;profit+=count*prev; prev=a[i]; count=0;}  }

			if(i>=n){profit+=prev;count--;profit+=count*prev;}


			i=0;
			while(i<n){if(a[i]>sum){sum=a[i];sum_index=i;}i++;} i=0;

			while(i<sum_index){newsum+=a[i];i++;}


			pf=(sum_index)*a[sum_index]-newsum;

			 if(profit<pf)return pf;

	 return profit;
}







int main(){

	long	int t;
  long	 int i,j,n[10];
  long	int *a[10];

	scanf("%ld",&t);


	for(i=0;i<t;i++) {
	  scanf("%ld",&n[i]);
	  a[i]=(long int *)malloc(sizeof(long int)*n[i]);
	  for(j=0;j<n[i];j++){
		 scanf("%ld",a[i]+j);
		 //printf("%d-",*temp+j);

		 }
		 }

	 for(i=0;i<t;i++)
		 printf("%ld\n",max_profit(a[i],n[i]));
	  //	n=sizeof(a)/sizeof(a[0]);
		// printf("%d\n",max_game_score_DP(a,9));
		// printf("%d\n",max_game_score(a,0));



return 0;
}
