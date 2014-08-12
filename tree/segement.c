//Segement Tree :: MINIMUM RANGE QUERY
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 //original array
 int a[6]={2,5,1,4,9,3};
 int n;

 int mint(int a,int b){
	 return a<b?a:b;

 }

 int *allocate_space(){

	int *p=(int*)malloc(sizeof(int)*(2*n-1));
	if(!p){printf("Memory Error");return NULL;}
		 
	return p;
 }





int build_segement_tree(int left,int right,int *p,int i){


	int mid;
  //if(!p)
  //return -1;
	 printf("%d-%d  %d>>>>>\n",left,right,i);
  if(left==right){
  //printf("%d-%d",i,left);
 *(p+i)=a[left];return a[left]; }
  if(i>2*n-2 || left>right){
	// printf("%d-%dm",left,i);
	 return 9999;            }


  mid=left+(right-left)/2;

 *(p+i)= mint(build_segement_tree(left,mid,p,2*i+1),build_segement_tree(mid+1,right,p,2*i+2));

	  return *(p+i);



}











void main(){
int i,*p;
n=sizeof(a)/sizeof(a[0]);
p=allocate_space();
build_segement_tree(0,n-1,p,0);
for(i=0;i<=2*n-2;i++)
	  printf("%d ",*(p+i));






}