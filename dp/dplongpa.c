//Longest Palindrome Substring ::Recursive & Dynamic Programming
#include<stdio.h>
#include<string.h>
char str[]="geegtrmadxamrtgeeg";
  int n;

//Returns maximum of two nos.
  int max(int a,int b){

  return a>b?a:b;
  }

 //::Dynamic Programming Implementation
	int longest_palindrome_substring_DP(){

			int p[20][20]={0},i,j,m,r,max_count=1;

         //Initially make all of them zero
			for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
            p[i][j]=0;

		//Each character is a palindrome of length 1
		 for(i=0;i<n;i++)
			 p[i][i]=1;

		//Two (equal) consecutive characters are palindrome
			 for(i=0;i<=n-2;i++)
			  p[i][i+1]=(str[i]==str[i+1])?2:0;
            
		 //Three characters are palindrome
			  for(i=1;i<=n-2;i++)
				  p[i-1][i+1]=(str[i-1]==str[i+1])?3:(p[i-1][i]+p[i][i+1]);

			 //>>>>>>>>>>>>>>>>>>>>>> consider "assa" four charcter palindrome
			 for(i=1;i<=n-2;i++){

				 if(p[i][i+1]==2){
					  m=i-1;r=i+2;
					  while(m>=0 && r<=n-1 && str[m]==str[r]){
					  p[m][r]=p[m+1][r-1]+2;
						 m--;r++;
					  }
						}
						 }


//>>>>>>>>>>>>>>>>>>>>> Generic cases for n>=4

 for(i=1;i<=n-2;i++){

				 if(p[i-1][i+1]==3){
					  m=i-2;r=i+2;
					  while(m>=0 && r<=n-1 && str[m]==str[r]){
					  p[m][r]=p[m+1][r-1]+2;
						 m--;r++;
					  }
						}
					    }

	  for(i=0;i<n;i++) 
		 for(j=0;j<n;j++)
			 max_count=max(max_count,p[i][j]);














		 return max_count;

	}

void main(){
int i;
n=strlen(str);

	printf("Longest Palindrome substring is %d",longest_palindrome_substring_DP());


}