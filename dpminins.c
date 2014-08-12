//Minimum insertions to form a palindrome using Recursion and DP
#include<stdio.h>
#include<string.h>

 char str[]="pabcp";
  int n;
 int min(int a,int b){

 return a<b?a:b;

 }
 int p[5][5];

 //Recursive implementation
  int min_no_insertion(int i,int j){


	  if(j<0 || i>n-1 || i>j)
		return 0;

  if(i==j)
  return 0;
	 if(str[i]==str[j])
		 return min_no_insertion(i+1,j-1);
	 else
  return min(1+min_no_insertion(i+1,j),1+min_no_insertion(i,j-1));

  }

//Dynamic Programming implementation
 int min_no_insertion_DP(){
       int i,j;
	 //Fill all fieds with zero where i==j
	  for(i=0;i<=n-1;i++)
		 p[i][i]=0;



		 for(i=3;i>=0;i--){
			for(j=i+1;j<=n-1;j++) {
			  //printf("%d-%d\n",i,j);
				if(str[i]==str[j])
				  p[i][j]=p[i+1][j-1];
              else
			 p[i][j]=min(p[i+1][j],p[i][j-1])+1;


			 }}


          return p[0][n-1];
 }


void main(){
	n=strlen(str);
printf("Minimum insertions required to form a palindrome (Recursion) - %d\n",min_no_insertion(0,n-1));
printf("Minimum insertions required to form a palindrome (Dynamic Programming) - %d",min_no_insertion_DP());
}
