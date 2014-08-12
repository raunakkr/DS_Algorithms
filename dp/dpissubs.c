//Set Partition problem ::  Dynamic Programming & Recursive implementation
#include<stdio.h>

 int a[]={5,5,1,13};
 int n;
 


 //Check whether there exists two partitions in set having equal sum and half of total sum
	int is_partition_possible_util(int n,int sum){

		 if(n==0 && sum!=0)
			return 0;

	  if(sum==0)
		 return 1;



	 return is_partition_possible_util(n-1,sum) || is_partition_possible_util(n-1,sum-a[n-1]);


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
	return is_partition_possible_util(n,sum/2);


  }

// :: Dynamic Programming implementation

int is_partition_possible_DP(){

	int i,j,sum=0;
   int p[50][10];
	  for(i=0;i<n;i++)
			 sum+=a[i];

	if(sum%2!=0)
	return 0;

  //Set up base case
  for(i=0;i<=n;i++)
		 p[0][i]=1;

	for(i=1;i<=sum/2;i++)
		 p[i][0]=0;

  for(i=1;i<=sum/2;i++){
	 //j starts from else j-1 would be -ve
	 for(j=1;j<n;j++){
	 p[i][j]=p[i][j-1];
	 //Handle if sum is less than element(negative index)
	 if (i >= a[j-1])
		 p[i][j]=p[i][j-1] || p[i-a[j-1]][j-1]; }}


	 	for (i = 0; i <= sum/2; i++)
     {
       for (j = 0; j <= n; j++)  
          printf ("%d ", p[i][j]);
       printf("\n");
	  }





	 return p[12][4];

}








void main(){

  n=sizeof(a)/sizeof(a[0]);
  is_partition_possible()?printf("Subset exists\n"):printf("No subset exists\n");
  is_partition_possible_DP()?printf("Subset exists"):printf("No subset exists");

}