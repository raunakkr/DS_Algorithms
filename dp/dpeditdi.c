#include<stdio.h>
#include<string.h>
  char a[]="spt";
  char b[]="suu";
  int m,n;


  int min(int a,int b){
    return a<b?a:b;
  }


int min_cost_edit_distance(int i,int j){

	int delete_cost,replace_cost,insert_cost;


	  if(i>m-1 && j>n-1)
		 return 0;
	  if(i>m-1)
		 return 1+min_cost_edit_distance(i,j+1);
		 // return n;
		 if(j>n-1)
		 //return m;
		 return 1+min_cost_edit_distance(i+1,j);

	delete_cost= 1+min_cost_edit_distance(i+1,j);
	insert_cost=1+min_cost_edit_distance(i,j+1);

	if(a[i]!=b[j])replace_cost=1+min_cost_edit_distance(i+1,j+1);

	  else replace_cost=min_cost_edit_distance(i+1,j+1);
	return min(min(delete_cost,insert_cost),replace_cost);





}



  int min_cost_edit_distance_DP(){

	 int i,j,p[20][20];


		p[m][n]=0;
		p[m][n-1]=0;
		p[m-1][n]=0;

		  //Insertion base case(when there is no character in 'a')
			  for(i=n-1;i>=0;i--)
				 p[m][i]=1 +p[m][i+1];
		  //Deletion base case(when there is no character in 'b')
		 for(i=m-1;i>=0;i--)
			p[i][n]=1+p[i+1][n];

		 


	  for(i=m-1;i>=0;i--){
		 for(j=n-1;j>=0;j--){
			if(a[i]!=b[j])  p[i][j]=min(min(1+p[i+1][j],1+p[i][j+1]),1+p[i+1][j+1]);
			 else
				 p[i][j]=min(min(1+p[i+1][j],1+p[i][j+1]),p[i+1][j+1]);   }}


        printf(">>>>>>>>>>>>>>>>>\n");

		  for(i=0;i<=m;i++){
			 for(j=0;j<=n;j++){
			  printf("%d ",p[i][j]); }
			  printf("\n"); }


		 return p[0][0];














  }

void main(){

  m=strlen(a);
  n=strlen(b);

printf("Minimum edit distance using Recursion- %d\n",min_cost_edit_distance(0,0));
printf("Minimum edit distance using DP- %d",min_cost_edit_distance_DP());
}