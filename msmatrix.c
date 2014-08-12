#include<stdio.h>
int a[3][4] = {  
 {7, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
 {4, 0, 6, 7} ,   /*  initializers for row indexed by 1 */
 {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

//for optimal solution with no extra space. start with (0,0) to (row,column) till we reach at min(row,column)*min(row,column)
void main(){
	int row,col,i,j,k;
for(i=0;i<3;i++)
	for(j=0;j<4;j++)
	{
		if(a[i][j]==0)
		 {
			 row=i;
			 col=j;
			for(k=0;k<4;k++)
				 a[1][k]=0;
			  for(k=0;k<3;k++)
				  a[k][1]=0;

		 }
			}


	for(i=0;i<3;i++){
	for(j=0;j<4;j++){
		printf("%d\t",a[i][j]);
		}
		printf("\n");}

}