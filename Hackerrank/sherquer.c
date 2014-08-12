//Sherlock & queries:: Complexity analysis & reduction
#include<stdio.h>
#define mod 1000000007;



 void chang_array(long int a[],long int b[],long int c[],long int m,long int n){
    int i,j;
 for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			if(j%b[i-1]==0)
			a[j-1]=a[j-1]*c[i-1];

			for(i=0;i<n;i++)
		printf("%ld ",a[i]);

		}


 void change_array(long int a[],long int b[],long int c[],long int m,long int n){

	long int i,j;

	 for(i=1;i<=m;i++)
			for(j=b[i-1];j<=n;j+=b[i-1])
		  a[j-1]=(a[j-1]*c[i-1])%mod;



	 for(i=0;i<n;i++)
		printf("%ld ",a[i]);









 }







int main(){

  long	int i,n,m,a[10],b[10],c[10];

	scanf("%ld",&n);
	scanf("%ld",&m);

	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	for(i=0;i<m;i++)
		scanf("%ld",&b[i]);


	for(i=0;i<m;i++)
		scanf("%ld",&c[i]);


	 change_array(a,b,c,m,n);

return 0;

}