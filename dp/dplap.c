//Longest arithmetic progression ::Recursive & Dynamic programming
#include<stdio.h>

//for simplicity array is sorted
int a[]={2, 4, 6, 8, 10};
 int n;
 int maxt;

  int max(int a,int b){return a>b?a:b;}

 int lap(int j,int k){
	 int maxt=0,i;
	  if(j<1 || k<2)
		 return 0;

		for(i=j-1;i>=0;i--){
	 if(a[i]+a[k]==2*a[j])
		  maxt=max(maxt,1+lap(i,j));

	  else if(a[i]+a[k]<2*a[j])
				  break;

				  }
			return maxt;
}


int lap_util(){
  int k,j,maxt=0;
	if(n<=2)
	  return n;

for(k=n-1;k>=0;k--){
  for(j=k-1;j>=1;j--){
	maxt=max(maxt,lap(j,k));
 printf("%d>>>\n",maxt);
 }

 }
  return maxt+2;

}





 int lap_DP(){

 int i,j,k,p[12][12],maxt=2;

 //A minimum LAP would be 2 in each case
	  for(i=0;i<n;i++)
			for(j=0;j<n;j++)
		  p[i][j]=2;

 //i-j gap of size '1' have 1 as lap
	for(i=0;i<n;i++)
		  p[i][i]=1;

 //Now start filling from bottom up

	for(k=n-1;k>=2;k--){
		 for(j=k-1;j>=1;j--){
		  for(i=j-1;i>=0;i--) {

		 if(a[i]+a[k]==2*a[j]){
			  p[i][j]=p[j][k]+1;
			  maxt=max(maxt,p[i][j]); }

		  else if(a[i]+a[k]<2*a[j])
						break;




	  }}

	}

	return maxt;

 }




void main(){

n=sizeof(a)/sizeof(a[0]);

		printf("Longest arithmetic progression using Recursion is  %d\n",lap_util());
		printf("Longest arithmetic progression using DP is  %d",lap_DP());

}