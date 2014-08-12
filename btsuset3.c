//Backtracking :: Selection of equal half subsets
#include<stdio.h>
#include<limits.h>
 int a[]= {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
 int n;
 int track[11];
 int min_so_far=INT_MAX;

 void print_partition(){
  int i;
	int lsum=0,rsum=0;
  for(i=0;i<n;i++)
	  if(track[i]==1){
		 lsum+=a[i];  }
		// printf("%d",a[i]); }
		 printf("  ");

		  for(i=0;i<n;i++)
	  if(track[i]==0){
		 rsum+=a[i]; }
		// printf("%d",a[i]);}
		 //printf("\n");

	 if(abs(lsum-rsum)<min_so_far)
			min_so_far=abs(lsum-rsum);

 }





 void tug(int i,int count){



	 if(i>n-1 || count>n/2)
		 return;
				  // printf("n");
 // for(i=start;i<n;i++)

		if(count==n/2){
		 //  printf("Are we here");
		  print_partition();
		  return;}

		//include it
		track[i]=1;
		tug(i+1,count+1);

		//Exclude it
		track[i]=0;
		tug(i+1,count);



 }





 void main(){
 int i;
 n=sizeof(a)/sizeof(a[0]);
 //Mark each element zero intitially
 for(i=0;i<n;i++)
		track[i]=0;

	 tug(0,0);
printf("Minimum distance b/w two equal subsets is %d",min_so_far);
 }