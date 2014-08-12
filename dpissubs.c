//Set Partition problem ::  Dynamic Programming & Recursive implementation
#include<stdio.h>

 int a[]={3,5,6,3,7};
 int n;
 


 //Check whether there exists two partitions in set having equal sum and half of total sum
	int is_partition_possible_util(int n,int sum){

		 if(n<0 & sum!=0)
			return 0;

	  if(sum==0)
		 return 1;



	 return is_partition_possible_util(n-1,sum) || is_partition_possible_util(n-1,sum-a[n]);


	}

//Is_partition main function :: Calculates sum

  int is_partition_possible(){
		  int i,sum=0;
	 for(i=0;i<n;i++)
		  sum+=a[i];
//There can't be any no. whose double is odd
	 if(sum%2!=0)
	  return 0;

 //If we are here :: Simply return
	return is_partition_possible_util(n-1,sum/2);


  }

// :: Dynamic Programming implementation

int is_partition_possible_DP(){

		int i,j,sum=0,p[8][20];

		for(i=0;i<n;i++)
		  sum+=a[i];

		if(sum%2!=0)
         return 0;



		// :: Base case
		  for(i=0;i<n;i++)
				p[i][0]=1;

				for(i=1;i<=sum/2;i++)
					p[0][i]=(i==a[0])?1:0;



	 //>>>>Fill up the matrix in top down manner
	  for (i = 1; i < n; i++) {
	  for (j = 1; j <= sum/2; j++){
		if(j>=a[i]) p[i][j]=p[i-1][j] || p[i-1][j-a[i]];
			 else
			 p[i][j]=p[i-1][j]; }}



		  


		for (i = 0; i < n; i++)
	  {
		 for (j = 0; j <= sum/2; j++)
			 printf ("%d ", p[i][j]);
		 printf("\n");
	  }

	



	 return p[n-1][sum/2];

}








void main(){

  n=sizeof(a)/sizeof(a[0]);
  is_partition_possible()?printf("Subset exists\n"):printf("No subset exists\n");
  is_partition_possible_DP()?printf("Subset exists"):printf("No subset exists");

}