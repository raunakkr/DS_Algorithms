#include<stdio.h>



int is_subset_found(int a[],int n,int i,int sum){

		if(sum==0)return 1;

		if(i>n-1)return 0;


	  return is_subset_found(a,n,i+1,sum-a[i])|| is_subset_found(a,n,i+1,sum);

}

//:: Dynamic Programming implementation
int is_subset_found_DP(int a[],int n,int sum){

	  int i,j,limit;
	  int p[20][20]={0};
	  limit=20;

	  for(i=n-1;i>=0;i--)
			 for(j=i;j<=n-1;j++)
			if(a[j]<limit) p[i][a[j]]=1;

		for(i=0;i<n;i++){
			if(a[i]>sum)continue;
			if(sum<limit && p[i][sum]==1)return 1;
			else
			 sum-=a[i]; }

          return 0;





}





int main(){
  int a[]={3,4,12, 2};
  int sum=19;
  int n=sizeof(a)/sizeof(a[0]);
  is_subset_found(a,n,0,sum)?printf("Subset found\n"):printf("No subset found\n");
  is_subset_found_DP(a,n,sum)?printf("Subset found"):printf("No subset found");

return 0;
}