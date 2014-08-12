//Recursive implementation of chain matrix multiplication with minimum operations
#include<stdio.h>
#include<limits.h>

  int a[]={4,3,2,1,7};
         int n;
   int min(int a,int b){return a<b?a:b;}


  int min_matrix(int p,int q){

		int mint=INT_MAX,i;
	 if(q-p==1)
	 return 0;
	 if(p==q)
    return 0;

	 if(p>n-2 || q>n-1)
			 return 0;


	 for(i=p+1;i<q;i++)

		  mint= min(mint,min_matrix(p,i)+min_matrix(i,q)+a[p]*a[i]*a[q]);


	  return mint;
  }


//Dynamic programming implementation
 int min_matrix_DP(){

	int i,j,mint,p[7][7];

	/*Fill all values wit max value initially
	  for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
			  p[i][j]=INT_MAX; */



  //Zero operations for one matrix
	for(i=0;i<n-1;i++)
		 p[i][i+1]=0;
   // cost is zero when multiplying one matrix(nXn).
	 for (i = 0; i < n; i++)
        p[i][i] = 0;

  //for two matrix,only one way is possible
	  for(i=n-3;i>=0;i--)
			p[i][i+2]=a[i]*a[i+1]*a[i+2];

  //Now fill up all values
	 for(i=n-4;i>=0;i--) {
		  mint=INT_MAX;
		 for(j=i+1;j<n-1;j++)
				mint=min(mint,p[i][j]+p[j][n-1]+a[i]*a[j]*a[n-1]);
		  p[i][n-1]=mint;
		 // printf(">>>>>>>>>>>>>>%d\n",p[i][n-1]);
							  }



        for(i=0;i<n;i++) {
		  for(j=0;j<n;j++)
			 printf("%d ",p[i][j]);
			  printf("\n");}

      return p[0][n-1];

 }



void main(){
  n=sizeof(a)/sizeof(a[0]);

printf("%d\n",min_matrix(0,n-1));
printf("%d",min_matrix_DP());

}