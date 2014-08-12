//Program to find the position where a[i]=i
#include<stdio.h>




int bsearch(int a[],int left,int right){

 int mid;
	if(left>right) return -1;

 mid=left+(right-left)/2;

 if(a[mid]==mid) return mid;

 if(a[mid]>mid) return bsearch(a,left,mid-1);
  else
       return bsearch(a,mid+1,right);

}







int main(){
	int a[]={-8,-6,-3,2,4,9};
   int n=sizeof(a)/sizeof(a[0]);
	printf("Position where a[i]=i is  %d",bsearch(a,0,n-1));

return 0;
}