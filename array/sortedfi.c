//Given a sorted array in decreasing order, find the fotst occurence of given key
#include<stdio.h>

int a[]={50,48,46,23,23,23,12,9,9,6};

int find_first_occurence(int left,int right,int data){

	  int mid;
		if(left>right) return -1;


mid=left+(right-left)/2;

if(a[mid]==data && a[mid-1]>data ) return mid;
else if(a[mid]<=data) return find_first_occurence(left,mid-1,data);
else
      return find_first_occurence(mid+1,right,data);





}



void main(){
int n= sizeof(a)/sizeof(a[0]);
printf("First occurence is   %d", find_first_occurence(0,n-1,6));


}