#include<stdio.h>
#include<limits.h>

//compare function
  int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

 int min(int a,int b){return a<b?a:b;}

  void print_closest(int a[],int n){
	int i,min_diff;
	min_diff=INT_MAX;
	qsort(a,n,sizeof(a[0]),compare);

	for(i=0;i<n-1;i++)
	  min_diff=min(min_diff,abs(a[i+1]-a[i]));

	  for(i=0;i<n;i++)
		 if(abs(a[i+1]-a[i])==min_diff)
			printf("%d %d ",a[i],a[i+1]);




	}


int main(){
  int n,i,a[100];

  scanf("%d",&n);

  for(i=0;i<n;i++)
	scanf("%d",&a[i]);

	print_closest(a,n);


return 0;
}