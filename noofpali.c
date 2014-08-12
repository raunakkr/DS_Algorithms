#include<stdio.h>
#include<string.h>
char a[]="aaabbbb";
int n;
int count=0;
void swap(char *p,char *q){
	char temp;
	temp=*p;
	*p=*q;
	*q=temp;
}


int is_palindrome(int i,int j){
	if(i<0 || i>n-1 || j<0 || j>n-1 || j<i)
		return 0;

		while(a[i]==a[j] && i<=j){

		 i++;
		 j--;

		}
		if(i>j)
		return 1;
		else
		return 0;

 }









void permute(int j){
	 int i;
	if(j==n) {
	if(is_palindrome(0,n-1)){count++;}
	//printf("%s\n",a);
	return;}
 for(i=j;i<n;i++){
swap(a+j,a+i);
permute(j+1);
swap(a+j,a+i);    }
}

void main(){
n=strlen(a);
permute(0);
//is_palindrome(0,n-1)?printf("yes"):printf("No");

printf("%d",count);}