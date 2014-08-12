//Program to rotate a matrix by 90 degree
#include<stdio.h>
#include<stdlib.h>
int a[3][3]={{5,3,4},
				 {2,7,8},
				 {9,1,1}};
int m=3,n=3;
int *p;
int t=0;
void rotatematrix(int m,int n){
 int i,j;

 for(i=0;i<n;i++)
  for(j=m-1;j>=0;j--){
	 *(p+t)=a[j][i];
	 t++; }


}


void main(){
  int i,j;
  p=(int*)malloc(sizeof(int)*m*n);
 rotatematrix(3,3);
	for(i=0;i<3;i++){
	for(j=0;j<3;j++)
  printf("%d",*(p+i*2+j));
  printf("\n"); }
  }
