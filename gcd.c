#include<stdio.h>






int gcd(n,m) {
if (n%m ==0)
 return m;
 n = n%m;
 return gcd(m,n); }


 void main(){
	int a;
	int b;
	printf("Enter two nos.\n");
	scanf("%d%d",&a,&b);
	printf("HCF is %d", gcd(a,b)) ;
}