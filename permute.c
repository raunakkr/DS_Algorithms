#include<stdio.h>
char a[]="abc";
int n=3;
void swap(char *p,char *q){
	char temp;
	temp=*p;
	*p=*q;
	*q=temp;
}


void permute(int j){
	 int i;
	if(j==n) {
	printf("%s",a);
	printf("\n");
	return;}
 for(i=j;i<n;i++){
swap(a+j,a+i);
permute(j+1);
swap(a+j,a+i);    }
}

void main(){
permute(0);}