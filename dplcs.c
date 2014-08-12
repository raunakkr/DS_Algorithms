//Longest common substring using dynamic programming

#include<stdio.h>
#include<string.h>
  char a[]="abab";
  char b[]="ammb";
  int n,m,maxt,imax;
  int p[20][20]={0};

  int max(int a,int b){

    return a>b?a:b;

  }



  //Recursive implementation
 //'i' and 'j' corresponds to first string and second string position respectively
 int lcs(int i,int j){


	 if(i>n-1)
	 return 0;

	 if(j>m-1)
	 return 0;


  if(a[i]==b[j]){

  return 1+lcs(i+1,j+1); }
  else
	return 0;


 }

//Dynamic programming implementation
	int lcs_DP(){

	int i,j;

	 for(i=n-1;i>=0;i--){
	  for(j=m-1;j>=0;j--){
			if(a[i]==b[j])
		  p[i][j]=1+p[i+1][j+1];

		  //printf("%d",p[i][j]);
			imax=max(imax,p[i][j]);

		  }}

		/* for(i=0;i<n;i++){
	  for(j=0;j<m;j++)
			printf("%d ",p[i][j]);
			printf("\n");
			}  */

	  return imax;
 }






void main(){
 int i,j;

  n=strlen(a);
  m=strlen(b);
 for(i=0;i<=n-1;i++){
  for(j=0;j<=m-1;j++){

	maxt=max(maxt,lcs(i,j));  }


 }


 printf("Longest Common Subsequence Using Recursion %d \n",maxt);
	 lcs_DP();
  printf("Longest Common Subsequence Using DP %d",imax);

}