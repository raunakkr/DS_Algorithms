#include<stdio.h>




long int sum_of_multiple(int n){
  long	int i,j,t,f,sum=0;
	if(n<3)return 0;

  for(i=1,j=1;;)
  {	t=3*i;
	f=5*j;
	if(t>=n && f>=n)break;

	if(t<f && t<n){sum+=t;i++;}
	else if(f<t && f<n){sum+=f;j++;}
	else if(f==t & f<n) {sum+=f;i++;j++;}



  }
	return sum;



}


//different solution
long int sum2(long int n){
  long int t,f,p;
	if(n<3)return 0;
	n--;
	t=n/3;t=((3+3*t)*t)/2;
	f=n/5;f=((5+5*f)*f)/2;
	p=n/15;p=((15+15*p)*p)/2;

	return t+f-p;

}


int main(){
 long int i,t;
 long int a[100];
  scanf("%ld",&t);
  for(i=0;i<t;i++)
	 scanf("%ld",&a[i]);

	 for(i=0;i<t;i++)
			printf("%ld-%ld\n",sum_of_multiple(a[i]),sum2(a[i]));

         return 0;
}