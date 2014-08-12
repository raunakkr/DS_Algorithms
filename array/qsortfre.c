//Quick sort recursion based based on frequency of elements
#include<stdio.h>
 int a[4][2]={{7,3},{1,12},{6,2},{8,7}};



 void qsort(int low,int high){
  int pivot;
  if(high>low){
	pivot=partition(low,high);
	qsort(low,pivot-1);
	qsort(pivot+1,high);
}

 }

 void swap(int i,int j){
	int temp;
	temp=a[i][0];
	a[i][0]=a[j][0];
	a[j][0]=temp;

	temp=a[i][1];
	a[i][1]=a[j][1];
	a[j][1]=temp;


}
 int partition(int low,int high){
	int left=low;
	int right=high;
	int pivot=a[low][1];
	//*********Take care of considering pivot of first column as well**************
	int pivot2=a[low][0];

	while(left<right){

		while(a[left][1]<=pivot)
				 left++;

		 while(a[right][1]>pivot)
				  right--;
		 if(left<right)
		 swap(left,right);
}
	 a[low][1]=a[right][1];
	 a[right][1]=pivot;
    //****************************Swap here as well with "PIVOT2"*******************
	 a[low][0]=a[right][0];
	 a[right][0]=pivot2;
	 return right;

 }


void main(){

int i;
	qsort(0,3);

for(i=0;i<4;i++)
	 printf("%d ",a[i][0]);
}