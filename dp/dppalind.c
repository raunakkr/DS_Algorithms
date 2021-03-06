//Palindrome partioning :: Recursive and Dynamic Programming solution

#include<stdio.h>
#include<string.h>
//char a[]="ababbbabbababa";
char a[]="ababababab";
int n;

 //Returns minimum of two nos.
 int min(int a,int b){

  return a<b?a:b;

 }

 int is_palindrome(int i,int j){
	if(i<0 || i>n-1 || j<0 || j>n-1 || j<i)
		return 0;

		while(a[i]==a[j] && i<=j){

		 i++;
		 j--;

		}
		if(i>j)
		return 1;
		else
		return 0;

 }



 int min_cut_palindrome_partioning(int p,int q){
	  int i,j,mint=999999;

	  if(p>n-1 || q>n-1)
		  return 0;
           
	  if(is_palindrome(p,q))
		  return 0;

	 for(i=p;i<=q-1;i++){


		 mint=  min(mint,min_cut_palindrome_partioning(p,i)+1+min_cut_palindrome_partioning(i+1,q));
		// printf("%d",mint);
	 }

		  return mint;
 }


  // ::Dynamic Programming Implementation

  /*	int min_cut_palindrome_partioning_DP(){

	  int p[20][20];

		  for(i=n-1;i>=0;i--)
				 for(j=i;j<=n-1;j++)
               mint=min(mint,p[i][j]



	}  */





void main(){

 n=strlen(a);

 printf("Minimum cut needed for palindrome partioning is %d",min_cut_palindrome_partioning(0,n-1));


}