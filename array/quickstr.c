//Program for quick sort implemented on strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[5][4] = { "cat", "rar", "ca", "cap", "can" };
  int n;



 //Compare function
 int compare (const void * a, const void * b)
{
 // return strcmp(  *(((char*)a)+0),*(((char*)b)+0)  )<0?1:0;

 return( strcmp((char *)a,(char *)b) );
 }


  void main(){

		int i;
	  n=sizeof(a)/sizeof(a[0]);
		// printf("%d\n",compare(a[0],a[3]));
for(i=0;i<n;i++)
  printf("%s ",a[i]);
  printf("\n");
  qsort(a,n,sizeof(a[0]),compare);

  for(i=0;i<n;i++)
  printf("%s ",a[i]);
  printf("\n");
}


