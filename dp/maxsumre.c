//Program to find maximum sub submatrix in matrix
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
  int top,bottom;
 int a[4][5] = {{1, 2, -1, -4, -20},
							  {-8, -3, 4, 2, 1},
							  {3, 8, 10, 1, 3},
							  {-4, -1, 1, 7, -6}
							 };
	int row=4;
	int col=5;

 int maxt(int a,int b){return a>b?a:b;}

 int kadane(int a[],int n){
	 //Ensure there is at least one element in the given array
	 int i,curr_sum=a[0];
	 int max_sum=curr_sum;
	 int L-top=0;
	 int L_bottom=0;

	 for(i=1;i<n;i++){
		//  printf("%d ",a[i]);
		 curr_sum=curr_sum+a[i];
		 if(curr_sum<a[i]){curr_sum=a[i];L_top=i;}

		 if(max_sum<curr_sum){max_sum=curr_sum;L_bottom=i};

			}return max_sum;}


int max_sum_rectangle(){

	 int i,j,k;
		int *temp;
		int max_sum=INT_MIN;

	 for(i=0;i<col;i++) {
		  temp=calloc(row,sizeof(int));
		 for(k=i;k<col;k++)  {
			for(j=0;j<row;j++)
		 *(temp+j)=*(temp+j)+a[j][k];
		  max_sum=maxt(kadane(temp,row),max_sum);   }


				 free(temp);


	 }

	 return max_sum;
}





void main(){



  printf("%d",max_sum_rectangle());





}