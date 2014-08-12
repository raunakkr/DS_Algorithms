#include<stdio.h>
int a[]={1, 7, 10, 15, 27, 29};
int n;

 int max(int a,int b){return a>b?a:b;}


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

printf("%d",lap_DP());

}