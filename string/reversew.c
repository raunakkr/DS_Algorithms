//Program to reverse each woords of given sentence
#include<stdio.h>
#include<string.h>

//Swaps characters sent by address
 void swap_char(char *p,char *q){
	  char temp;
	  if(!p || !q)return;

		temp=*p;
		*p=*q;
		*q=temp;

	  return;
 }

//Reverse individual words
	char *reverse_word(char *a,int len){
		int i;
		if(!a)return NULL;
		  i=0;
		while(i<=len){
			  swap_char((a+i),(a+len));
			  i++;len--;

									  }

		  return a;}



//Reverse each word
char *reverse_each_word(char *a){
  int i=0,len=-1,tl;
  char *buffer=a;
  if(!a)return NULL;
  tl=strlen(a)-1;
 //reverse_word(a,tl);
  while(*(a+i)){


			len++;

	  if(*(a+i)==' ' || i==tl){ reverse_word(buffer,len-1);
			printf("\n%d",len);

	  len=0;buffer=a+i+1;}

		  i++;

  }



  printf("%s",a);    

}

void main(){

	char a[]="this is a";

     reverse_each_word(a);



}