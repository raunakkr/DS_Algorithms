#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

   int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


 int max_toys(int a[],int n,int k){

	 int i,c=0;
	 qsort(a,n,sizeof(a[0]),compare);
       i=0;
	 while(k>=0){
		 k-=a[i];
		 c++;
		 i++;}


		 return c-1;

 }







int main() {
	 int n, k, i, count,answer,*prices;
    scanf("%d%d", &n, &k);
    prices = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &prices[i]);
    }
     
   
	  answer = max_toys(prices,n,k);
    // Compute the answer
    printf("%d\n", answer);
      
    return 0;
}
