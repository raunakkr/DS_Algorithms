//Program to reach destination with minimum distance in a matrix
#include<stdio.h>
#include<limits.h>

  int min(int a,int b){return a<b?a:b;}


int min_distance(int i,int j,int m,int n){

	 int a[21][21];
	 int p,q;
	 if(i==m && j==n) return 0;

	 //fil all fields with possible maximum values
	 for(p=0;p<=20;p++)
		 for(q=0;q<=20;q++)
		 a[p][q]=999;

	 a[i][j]=0;


	 for(p=1;p<=19;p++){
		 for(q=1;q<=19;q++)
		 {
			if(a[p][q]!=0) a[p][q]=1+min(min(a[p+1][q],a[p-1][q]),min(a[p][q+1],a[p][q-1]));



		 }
		 }


		return a[m][n];



	 }






int main(){

 printf("Minimum Distance is  %d", min_distance(1,1,3,3));


return 0;
}