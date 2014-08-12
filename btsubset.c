// BACKTRACKING :: Program to print all subsets of an array having sum 'K'
#include<stdio.h>

int a[]={10, 7, 5, 18, 12, 20, 15};
int n;
int sum=35;
int ot[7];


  void print_output(int pos){
	  int i;
	  //printf("kk%d",pos);
	  //printf("%dooooo",ot[0]);
	  for(i=0;i<pos;i++)
		  printf("%d ",ot[i]);
		printf("\n");
  }





  void print_subset(int i,int sum,int pos){


	 if(sum==0){
     // printf("%dmmmmm>>>>",ot[0]);
	  print_output(pos);
	  return ;}
		 if(sum<0 || i>n-1)
		  return;
	//include element
	  ot[pos]=a[i];
    // printf("ll");
	  print_subset(i+1,sum-a[i],pos+1);

	//Exclude element
	  print_subset(i+1,sum,pos);





  }







void main(){
 n=sizeof(a)/sizeof(a[0]);
  print_subset(0,sum,0);


}