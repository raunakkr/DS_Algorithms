//Dynamic programming based(recursive) solution for "LONGEST PALINDROME SUBSEQUENCE"
#include<stdio.h>
char a[]="matmm";
int n = sizeof(a)/sizeof(a[0]);
 int max(int a,int b){
 return a>b?a:b;
 }
int pal(int i,int j){
 if(j-i==0)
	return 1;
	if(i>j)
	return 0;
 if(a[i]==a[j])
  return 2+pal(i+1,j-1);
  else
  return max(pal(i,j-1),pal(i+1,j));



}
void main(){

  printf("%d",pal(0,n-1));

}