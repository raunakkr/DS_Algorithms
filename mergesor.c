//Merge sort for a simple array( o(n) space)


#include<stdio.h>

int a[]={2,4,3,1,7,9,6};
//int a[]={2,3,8,12,4,7};
int n=7;
int temp[7];



void mergef(int left,int mid,int right){
	int temp_pos=left;
	int left_end=mid-1;
	int i;
	int size=right-left+1;
		 //printf("p");
	while((left<=left_end) && (mid<=right)){

		if(a[left]<=a[mid]) {
		  temp[temp_pos]=a[left];
			temp_pos=temp_pos+1;
			left++;
			//printf("q");
			 }
		 else
		 {
		  temp[temp_pos]=a[mid];
		  temp_pos=temp_pos+1;
		  mid++;
			//printf("r");
		 }
			 }

	 while(left<=left_end){
		 temp[temp_pos]=a[left];
		 temp_pos=temp_pos+1;
			left++;
			//printf("s");
			}

	 while(mid<=right){
		temp[temp_pos]=a[mid];
		temp_pos=temp_pos+1;
			mid++;
		  //printf("t");
	 }

}




  void mergesort(int left,int right){
  int mid;
  if(left<right){
	 mid=(right+left)/2;
    printf("%d--\n",a[mid]) ;

	 mergesort(left,mid);
	 mergesort(mid+1,right);
	 mergef(left,mid,right);
	  //return;
	}

  }












void main(){
int i;
 mergesort(0,n-1);

// for(i=0;i<=6;i++){
  //		a[i]=temp[i];

	//}



	//mergef(0,4,5);

 for(i=0;i<n;i++)
 printf("%d  ",temp[i]);






}