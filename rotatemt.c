//Program to rotate a MxN matrix by 90 degree
#include<stdio.h>
#include<stdlib.h>
//#define m 2;
//#define n 3;
 int m=2;
	int n=2;
int a[2][2]=  {{5,3},
				 {2,7}
				 };


  void rotate_matrix(){

	int *p,i,j,k=0;

	//Allocate space for m*n integers
	p=malloc(sizeof(int)*m*n);

  for(j=0;j<=n-1;j++) {
	for(i=m-1;i>=0;i--){
         
		*(p+k)=a[i][j];

		  k++;}}


		  for(i=0;i<m;i++){
		  for(j=0;j<n;j++)
			 printf("%d ",*(p+i*n+j));
			 printf("\n"); }
  }




void main(){

rotate_matrix();


}


