//Convert incoming characters to integer(number)
#include<stdio.h>

int convert_to_integer(char a[],int n){  //Consider positive nos. only

	int i,res=0;
	if(n==0)return 0;

	for(i=0;i<n;i++)
		res=(res*10)+(int)((int)a[i] + 0);
		

		return res;






}

int main(){

  char a[]={9,3,0};
  int n=sizeof(a)/sizeof(a[0]);
  printf("Number formed so far is  %d",convert_to_integer(a,n));

return 0;


}