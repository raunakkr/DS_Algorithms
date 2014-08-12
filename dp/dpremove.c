//Min. Elemnet Removal such that 2*min>max :: Recursive & Dynamic Programming
#include<stdio.h>
#include<limits.h>
int arr[]={2,4,99,50,20,75};
int n;

int min(int a,int b){return a<b?a:b;}

// A utility function to find minimum in arr[l..h]
int min_between(int l, int h)
{    int i;
	 int mn = arr[l];
	 for ( i=l+1; i<=h; i++)
		 if (mn > arr[i])
			mn = arr[i];
	 return mn;
}

// A utility function to find maximum in arr[l..h]
int max_between(int l, int h)
{    int i;
	 int mx = arr[l];
	 for (i=l+1; i<=h; i++)
		 if (mx < arr[i])
			mx = arr[i];
	 return mx;
}
// ::Recursive Implementation
int min_removal(int p,int q){
	 if(p>=q)
	 return 0;

	if(2*min_between(p,q)>max_between(p,q))
		return 0;

	return 1+min(min_removal(p+1,q),min_removal(p,q-1));
}

// ::Dynamic Programming implementation
 int min_removal_DP(){
	  int i,j,gap;
	 int p[10][10];

 for(i=0;i<n;i++)
	 for(j=0;j<n;j++) //initially mark each cell as maximum
	 p[i][j]=9;

 for(i=0;i<n;i++)    //For one elemnet,No removal needed as it will always satisfy the given property
	 p[i][i]=0;

 //for remaining elements
	gap=n;
  while(gap>=0){

		for(i=gap-2,j=n-1;i>=0;i--,j--)
			p[i][j]=(2*min_between(i,j)>max_between(i,j))?0:1+min(p[i+1][j],p[i][j-1]);

		 gap--;

  }

	for(i=0;i<n;i++){
	 for(j=0;j<n;j++)
	  printf("%d ",p[i][j]);
		printf("\n"); }

  return p[0][n-1];
 }







void main(){
 n=sizeof(arr)/sizeof(arr[0]);
printf("Minimum elements need to be removed using Recursive- %d\n",min_removal(0,n-1));
printf("Minimum elements need to be removed using DP- %d",min_removal_DP());
}