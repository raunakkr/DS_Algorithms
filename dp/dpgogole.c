//Partitioning a set such that sum of maximum in all partitions is minimum :: Recursive & DP Implementation
#include<stdio.h>
#include<limits.h>
 int a[]={5,1,4,2,3};
 int n,m;

 int min(int a,int b){return a<b?a:b;}
 int max(int a,int b){return a>b?a:b;}
 //Find maximum b/w inde 'i' & 'k' inclusive
 int max_till(int i,int k){
 int j,maxt=INT_MIN;
 for(j=i;j<=k;j++)
  maxt=max(maxt,a[j]);
  return maxt;}

//::Recursive Implementation
  int min_sum_partition(int j,int m){
            int i,mint=INT_MAX;

					 if(j>n-1)return INT_MAX;
					 if(m==1)return max_till(j,n-1);


					 //if(j==n-1)return a[j];

		 for(i=j;i<=n-m;i++){
			 mint=min(mint,max_till(j,i)+min_sum_partition(i+1,m-1));

			 printf(">>>%d-%d-%d\n",j,i,mint);}
                                               
			 return mint;
}

//::Dynamic Programming implementation

	int min_sum_partition_DP(){

	  int i,j,k;
	  int gap=n-2;
	  int mint=INT_MAX;
	  int p[10][10];   //A 2d-array of dimension n*m preferably

	  for(i=0;i<=n;i++)
		  for(j=0;j<=m;j++) //Intitially all fields at their maximum
		  p[i][j]=INT_MAX;

		for(i=1;i<=n-1;i++)
			p[i][1]=max_till(i,n-1);   //When we have reached required partition, just store maximum till last

         for(i=0;i<=n;i++){
		  for(j=0;j<=m;j++)
		  printf("%d ",p[i][j]);
				 printf("\n"); }
				 printf(">>>>>>>>>\n");

		//Now start filling fields diagonal-wise
		for(j=2;j<=m;j++)
		  for(i=0;i<=n;i++)
			  for(k=i+1;k<m-j;k++){
				  p[i][j]=  min(p[i][j],p[k][j-1]+max_till(i,k));
              printf(">>>>>>%d\n",p[i][j]);
				  printf("%d>>%d\n",k,j-1);
				  printf(">>>>>>%d\n",p[i][j]);
					}

			 //Now find minimum in column 'm'
			 //for(i=0,j=m;i<=n;i++)
				 // mint=min(mint,p[i][j]);


			  for(i=0;i<=n;i++){
		  for(j=0;j<=m;j++)
		  printf("%d ",p[i][j]);
				 printf("\n"); }


				  return p[0][m];










	}


void main(){

  n=sizeof(a)/sizeof(a[0]);
  m=3;
 printf("Using Recursive implementation %d\n",min_sum_partition(0,m));
 printf("Using Dynamic Programming implementation %d\n",min_sum_partition_DP());
  // printf("%d",max_till(2));

}