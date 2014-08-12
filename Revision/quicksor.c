//Implementation of quick sort (Taking leftmost element as PIVOT)
#include<stdio.h>
int a[]={6,65,32,1,23,12,76,17};

void swap(int i,int j){
	 int temp=a[i];
	 a[i]=a[j];
	 a[j]=temp;


}
void quicksort(int left,int right){

	if(left<right)
	{
	  int pivot=partition(left,right);
		quicksort(left,pivot-1);
		quicksort(pivot+1,right);

	}


	 return;
}


//Partition function for quick sort
	int partition(int left,int right){
		  int low=left;
	  int pivot=a[left];

	  while(left<right)
	  {
			while(pivot>=a[left])
				left++;

			while(pivot<a[right])
				right--;

			if(left<right)
			 swap(left,right);

}
  a[low]=a[right];
  a[right]=pivot;

  return right;

}
 void display_array(int n){
	int i;
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);
	  printf("\n");

 }

int main(){
int n=sizeof(a)/sizeof(a[0]);
  display_array(n);
quicksort(0,n-1);
 display_array(n);

return 0;
}