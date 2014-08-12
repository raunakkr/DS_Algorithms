#include<stdio.h>
#include<stdlib.h>

int find_missing_element(int a[],int n){
  int i;
  if(!a) return -1;

  for(i=0;i<=n-3;i++)
	if(a[i]+a[i+2]==2*a[i+1])
		continue;
		else if(i==0 && (a[i+1]-a[i])>(a[i+2]-a[i+1]))return (a[i]+a[i+1])/2;
		else if(i==0) return (a[i+1]+a[i+2])/2;
		//this is missing spot when i!=0
	else  return 2*a[i+1]-a[i];

   



}









void main(){
  int i,n,*a;
  printf("Enter no. of array elements");
  scanf("%d",&n);
  a=malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
	 scanf("%d",a+i);

  printf("\nMissing element is %d",find_missing_element(a,n));


}