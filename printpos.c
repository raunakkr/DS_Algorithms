//Print postorder from given inorder and preorder
#include<stdio.h>
#include<stdlib.h>

int ino[]={7,8,4,1,6,2,5};
int pre[]={1,4,7,8,2,6,5};
int n=7;

int preindex=0;

	void printpostorder(int low,int high){

	  int mid;


		 if(low>high || low>n-1|| low<0 || high>n-1 ||high<0)
			  return;






		  mid=getindex(pre[preindex]);
			 if(preindex<n-1)
				 preindex++;


		 printpostorder(low,mid-1);
		 printpostorder(mid+1,high);

				 printf("%d ",ino[mid]);


}


  int getindex(int data){
	  int i;
	  for(i=0;i<n;i++){
		 if(ino[i]==data)
			  return i;
			  }
}







void main(){

	printpostorder(0,n-1);


}