//Permutation program (recursion based)
#include<stdio.h>
 char a[]="abc";
 int n=3;

 void swap(int i,int j){
 char temp;
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;}

 void permute(int j){
	int i;
	if(j==n){
	printf("%s\n",a);
	return;}

	for(i=j;i<n;i++){
	swap(j,i);
   permute(j+1);
	swap(j,i);
	}
}




void main(){
 permute(0);

}