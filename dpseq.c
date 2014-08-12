//Plese note that that this is not an optimal solution. An optimal solution will be using dynamic programming
#include<stdio.h>
void subs();
void maxsum();
int n=6;
int a[]={1,-2,3,-3,5,-2};
void main(){



  subs();
  maxsum();



}

//function to print maximum sum of subsequence of array elements

void subs(){
	int cur,i,j,max=0;
for(i=0;i<5;i++){
		cur=a[i];
	 for(j=i+1;j<=5;j++) {
		cur+=a[j];
	  if(cur>max)
		 max=cur;

}

}

 printf("%d",max);
}


void maxsum(){
 int sumsofar=0,sumendinghere=0;
 int i;
 for(i=0;i<n;i++) {
  sumendinghere=sumendinghere+a[i];
  if(sumendinghere<0){
		sumendinghere=0;
		continue;

  }
  if(sumsofar<sumendinghere)
		sumsofar=sumendinghere;

 }


  printf("%d",sumsofar);








}
