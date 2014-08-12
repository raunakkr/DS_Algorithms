//Check whether a string is interleaved of two or not
#include<stdio.h>
#include<string.h>
	char a[]="ab";
	char b[]="cd";
	char c[]="acbd";
int checkinterleaving(){
char *p=a,*q=b,*r=c;
  if(strlen(a)<0 && strlen(b)<0)
	return 0;

	if(strlen(c)!=strlen(a)+strlen(b))
	return 0;


	while(*r!='\0'){
	  if(*r==*p){
		 p++;
		 r++;}

	 else if(*r==*q){
		 q++;
		 r++;}

		 else return 0;
	}

	return 1;



}


void main(){

	if(checkinterleaving())
		printf("yes");
		else
      printf("no");


}