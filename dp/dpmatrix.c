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

		if(p==q)
          return 0;
		for(i=p;i<q;i++){

		mint=min(mint,min_operation(p,i)+min_operation(i+1,q)+a[p-1]*a[i]*a[q]);

		}
		return mint;

	}




void main(){

  n=sizeof(a)/sizeof(a[0]);
printf("%d",min_operation(1,n-1));

}
