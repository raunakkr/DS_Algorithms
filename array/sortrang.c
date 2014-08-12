//Sorting time interval based on start time
#include<stdio.h>

struct range{
 int s;
 int e;
};


 void quicksort(struct range a[],int left,int right){
	 int pivot;
	if(left<right){

	  pivot=partition(a,left,right);
	  quicksort(a,left,pivot-1);
	  quicksort(a,pivot+1,right);


	}

 }

 void swap(struct range a[],int left,int right){

		 
		 struct range temp=a[left];
			a[left]=a[right];
			a[right]=temp;





 }

//Partition function

int partition(struct range a[],int left,int right){

		 int pivot=a[left].s;
		 struct range t;
		 int low=left;
	 while(left<right){

		 while(a[left].s<=pivot)
					 left++;

		 while(a[right].s>pivot)
					 right--;


		 if(left<right)
		  swap(a,left,right);


	 }


		 t=a[right];
		a[right]=a[low];
		a[low]=t;

		 return right;



}



  void display_range(struct range a[],int n){

  int i;
  for(i=0;i<n;i++)
	 printf("{%d,%d} ",a[i].s,a[i].e);

	 printf("\n");


  }



int main(){
	struct range a[5];
   int n=5;
	int i,start,end;

	for(i=0;i<5;i++){
		 scanf("%d",&start);
		 scanf("%d",&end);
		 a[i].s=start;
		 a[i].e=end;
					 }


		 display_range(a,n);
        quicksort(a,0,n-1);

		 display_range(a,n);

return 0;
}