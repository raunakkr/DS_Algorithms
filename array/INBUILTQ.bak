//Program for quick sort implemented on strings
#include<stdio.h>
//#include<stdlib.h>

int a[]={5,7,1,3,2};
  int n;


  //compare function
  int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


  void main(){
		int i;
		n=sizeof(a)/sizeof(a[0]);
for(i=0;i<n;i++)
  printf("%d ",a[i]);
  printf("\n");
	qsort(a,n,sizeof(a[0]),compare);

  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  printf("\n");
}


