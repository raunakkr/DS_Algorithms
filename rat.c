//Rat in a maze :: Backtracking
#include<stdio.h>
int a[4][4]= 
					{ {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
	 };

int m=4;
int n=4;
//Checks if cell is dead or not
 int is_open(int i,int j){
	if(i>m-1 || j>n-1 || i<0 || j<0)
		return 0;

	 return a[i][j];

 }

//Generates solution matrix (returns true if path is possible)
 int is_path(int i,int j){
	int p,q;
         printf("%d-%d\n",i,j);
	if(i==m-1 && j==n-1)
		return 1;
	 if(!is_open(i,j)) return 0;

	 p=is_open(i+1,j);
	 q=is_open(i,j+1);

			a[i][j]=(p && is_path(i+1,j)) || (q && is_path(i,j+1));

	if(!p && !q){
			 a[i][j]=0;
			 return 0;
			 }



 }




void main(){

is_path(0,0)?printf("Yes"):printf("No");



}