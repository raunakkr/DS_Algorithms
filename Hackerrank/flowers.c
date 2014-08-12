/* Sample program illustrating input/output methods */
#include<stdio.h>

//compare function
  int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int min_cost(int a[],int n,int p){

	 int i,k,x,cost;
	 i=0;cost=0;x=0;k=0;
	 qsort(a,n,sizeof(a[0]),compare);

	 while(i<n){

		while(k<p && i<n){

			cost+=(x+1)*a[i];k++; i++;
		  // printf(">>>>%d\n",cost);
		}
		k=0;x++;

	 }
	 return cost;
}




int main(){

//Helpers for input/output
   int i, N, K;
   int C[102];
    int result;
   scanf("%d %d", &N, &K);
   for(i=0; i<N; i++){
      scanf("%d", &(C[i]));
   }
   
          result=min_cost(C,N,K);
   printf("%d\n", result);

}
