//An in-place run-length encoding. Encoded string length must be less than equal to input string
#include<stdio.h>
#include<string.h>
char a[]="abcccd";
int n;

char c[12]={'0','1','2','3','4','5','6','7','8','9','10','11'};



	void inplace_run_length_encoding(){
		int i=0,f,b;
		char curr=a[i];
		int count=0;
		b=i;

	  while(a[i]!='\0'){
			 a[b]=a[i];
			 count=0;
			 curr=a[i];
		  while(a[i]==curr){

				 i++;
				 count++;

		  }
		  b++;
		  if(count>1 && count<9){
			  a[b]=c[count];
			  b++;}

			

	  }

		a[b]='\0';

	}







void main(){
	  printf("Original string-  %s\n",a);
	  inplace_run_length_encoding();
       printf("Encoded string-  %s",a);


}