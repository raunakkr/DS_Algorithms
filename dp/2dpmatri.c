//Minimum operations in matrix chain multiplication :: Recursive and Dynamic programming implementation

#include<stdio.h>
#include<limits.h>

 int a[]={2,3,4,5};
 int n;

	int min(int a,int b){

	return a<b?a:b;
	}


	int min_operation(int p,int q){
		int i,mint=INT_MAX;
		if(p>q || p>n-1 || q>n-1 || p<0 || q<0)
		return 0;
	 if(p==q)
			 return 0;

			 if(q-p==1)
			 return a[q];
			// if(q-p==2)
			// return a[p]*a[p+1]*a[q];


		for(i=p;i<q;i++){


		mint=min(mint,min_operation(p,i)+min_operation(i+1,q)+a[p]*a[i+1]*a[q]);

		}
		return mint;

	}




void main(){

  n=sizeof(a)/sizeof(a[0]);
printf("%d",min_operation(0,n-1));

}