#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){

	int *hash_t=(int*)calloc(26,sizeof(int));

	int i,len;

char *a="abbcdc";
	 len=strlen(a);


	for(i=0;i<len;i++)
	  hash_t[*(a+i)]++;


	 for(i=0;i<26;i++){
		 if(hash_t[i]>1)
		 printf("%c\n",i);

                   }



	 }