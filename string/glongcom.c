// :: Fing longest prefix commin in all given strings
#include<stdio.h>
#include<string.h>




void print_longest_prefix(char *a[],int n){

	 char c;
	 int i,j,flag,count;
	 i=0;flag=0;count=0;
	 

	 while(*(a[0]+i)){
			c=*(a[0]+i);
				j=1;
		  while(j<n){
			 if(*(a[j]+i) && c==*(a[j]+i)){
				j++;}
			  else {flag=1;break;} }

			if(flag)break;
			count++;  i++;


		  }

	  i=0;
	  while(i<count){

		printf("%c",*(a[0]+i));i++;
	  }




}










int main(){

  char *a[]={"abc" ,"abd" ,"abcd" ,"abcd"};
  int n=sizeof(a)/sizeof(a[0]);

	 print_longest_prefix(a,n);
return 0;
}