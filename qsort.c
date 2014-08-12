//Quick sort recursion based
#include<stdio.h>
 int a[25]={343,565,45,56,766,32,35,899,765,65,433,14,244,3555,654,326,787,90,0,0,12,12,433,233,455};
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
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
 int partition(int low,int high){
	int left=low;
	int right=high;
	int pivot=a[low];

	while(left<right){

		while(a[left]<=pivot)
				 left++;

		 while(a[right]>pivot)
				  right--;
		 if(left<right)
		 swap(left,right);
}
	 a[low]=a[right];
	 a[right]=pivot;
	 return right;

 }


void main(){

int i;
	qsort(0,24);

for(i=0;i<25;i++)
	 printf("%d ",a[i]);
}