//Program to print permutation of given nos. with repeation
#include<stdio.h>
char a[]="abc";
char b[3];
int n=3;
void permwithrep(int pos){
int i;
  if(pos==n){
	 printf("%s\n",b);
	 return;
}

for(i=0;i<n;i++){
	 b[pos]=a[i];
	 permwithrep(pos+1);
}


}

void main(){

  permwithrep(0);



}