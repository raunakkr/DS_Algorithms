//Sum of all even fibonacci nos. not exceeding N
#include<stdio.h>


long int sum_even(unsigned long int n){

	unsigned long int a,b,temp,sum=2;
	a=1;b=2;
	while(b<=n)
	{
		temp=b;
		b=a+b;
		a=temp;
		if(b%2==0 && b<=n)sum+=b;
	  // printf("%d ",b);

	}
  return sum;
}


int main(){
  unsigned	long int i,t;
unsigned long int a[100000];
  scanf("%ld",&t);
  for(i=0;i<t;i++)
	 scanf("%ld",&a[i]);

	 for(i=0;i<t;i++)
			printf("%ld\n",sum_even(a[i]));



}