//Program to choose fewer coins as possible
#include<stdio.h>
int a[]={1,2,5,10};
int n=4,v=0,sum=16;

int mint(int a,int b){return a<b?a:b;}
int fcoin(int i){
   if(i>n-1 && sum>v)
	return 99;
   if(i>n-1 || i<0)
	return 0;
	v+=a[i];
  if(v<sum)
	 return fcoin(i+1)+1;
	 else return 1;





}



void main(){
 /*	int i,j,myv=0,min=9999;
	for(i=0;i<n;i++)
	myv+=a[i];
	if(myv<sum)
	min=-1;
  for(i=0;i<n;i++){
	  v=0;
	 if(a[i]>sum){
	 min=1; break;}
	 if(i==n-1)
	 break;
	 j=fcoin(i);
	 if(min>j)
	 min=j;


}  */

printf("%d",fcoin(1));
}