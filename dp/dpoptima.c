//Compute optimal strategy for game :: Recursive & Dynamic Programming implementation
#include<stdio.h>

 int a[]={2,2};
  int n;

int max_value_at_index(int left,int right){

	 return a[left]>a[right]?0:1;
}

int max(int a,int b){return a>b?a:b;}

  //  :: Recursive implementation
 int compute_optimal_turn(int i,int j){
		int sum_one=0,sum_two=0;
		 if(j<i)
          return 0;

		if(j-i==1)
			return max(a[i],a[j]);

	  if(i>n-1 || j>n-1 || i<0 || j<0)
		  return 0;

		if(!max_value_at_index(i+1,j))
		 sum_one= max(sum_one,a[i]+ compute_optimal_turn(i+2,j));
				else
			sum_one= max(sum_one,a[i]+compute_optimal_turn(i+1,j-1));


		if(!max_value_at_index(i,j-1))
		 sum_two= max(sum_two,a[j]+ compute_optimal_turn(i+1,j-1));
				else
			sum_two= max(sum_two,a[j]+compute_optimal_turn(i,j-2));


		return max(sum_one,sum_two);
 }

  // :: Dynamic Programming implementation

 int compute_optimal_turn_DP(){

	 int p[10][10],i,j,sum_one=0,sum_two=0;

	 //Filling :: Base Cases

	 for(i=0;i<n-1;i++)
		 p[i][i+1]=max(a[i],a[i+1]);

	  for(i=0;i<=n;i++)
			p[i][n]=0;
		//for i=j set p[i][i]=a[i]
	  for(i=0;i<n;i++)
			 p[i][i]=a[i];
	  for(i=0;i<n;i++)
		  for(j=0;j<=i-1;j++)
			p[i][j]=0;
	  for(i=0;i<n;i++) {

		  for(j=i+1;j<=n-1;j++){
		if(!max_value_at_index(i+1,j)){
		 sum_one=max(sum_one,(i+2>n-1)?0+a[i]:p[i+2][j]+a[i]);
			  }	else
				 sum_one=max(sum_one,(j-1<0)?0+a[i]:p[i+1][j-1]+a[i]);


		if(!max_value_at_index(i,j-1))
		 sum_two=max(sum_two,(j-1<0)?0+a[j]:p[i+1][j-1]+a[j]);
				else
			sum_two=max(sum_two,(j-2<0)?0+a[j]:p[i][j-2]+a[j]);

		 p[i][j]=max(sum_one,sum_two); }}

       return p[0][n-1];

 }

void main(){
n=sizeof(a)/sizeof(a[0]);

printf("Maximum value user can earn is %d (RECURSION)\n",compute_optimal_turn(0,n-1));
printf("Maximum value user can earn (DYNAMIC PROGRAMMING) is %d",compute_optimal_turn_DP());





}