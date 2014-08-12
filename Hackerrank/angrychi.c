#include <stdio.h>
#include <string.h>
#include <math.h>
#include<limits.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_VAL 1000000001

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/
	int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int min_val(int a,int b){return a<b?a:b;}

int max_fair(int n,int k){

	int i,mint;
	mint=INT_MAX;
	qsort(candies,n,sizeof(candies[0]),compare);

	for(i=0;i<=n-k;i++)
	  mint=min_val(mint,abs(candies[i+k-1]-candies[i]));

	  return mint;


}




int main() {

	 int N,K;
	 int i,unfairness;

	 scanf("%d %d",&N,&K);
	 for(i = 0;i < N;i++)
		  scanf("%d",candies + i);

	 unfairness =max_fair(N,K); // Compute the min unfairness over here, using N,K,candies

	 printf("%d",unfairness);
	 return 0;
}
