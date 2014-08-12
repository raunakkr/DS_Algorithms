//Program to print subset of array in equal halves such that sum of both subset is as minimum as possible(TUG OF WAR)
#include<stdio.h>
#include<limits.h>
int a[4]={3, 4, 5, 2};

int ztrack[4];
int otrack[4];
int min_so_far=INT_MAX;
int zero[10];
int one[10];

 void update_output(){
	  int i,j,k;
	for(i=0,j=0,k=0;i<n;i++){
		  if(track[i]==0){
			 zero[j]=a[i];
			 j++;  }
			 else {
			 one[k]=a[i];
			 k++;}

	  }
 }





  void update_minimum(){
	  int i,lsum=0,rsum=0;




	for(i=0;i<n;i++)
	  {	if(track[i]==0)
		 lsum+=a[i];
	  else
			rsum+=a[i];  }

	  if(abs(lsum-rsum)<min_so_far){
			min_so_far=abs(lsum-rsum);
			update_output();  }






  }




void tug_of_war(int start,int count,int z,int o){
	 int i;
	 if(count==n){
		 update_minimum();
		  return;}


	 for(i=start;i<n;i++){
			ztrack[z]=a[i];
			tug_of_war(i+1,count+1,z+1,o);


			otrack[o]=a[i];
			tug_of_war(i+1,count+1,z,o+1);


		}



}










void main(){}
