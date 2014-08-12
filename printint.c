//Program to print all interleaving of two strings
#include<stdio.h>
#include<string.h>
char a[]="ab";
char b[]="cd";
 char outputx[10];
int na,nb;

void printallinterleaving(char *a,char *b,int pos){

  if(*a=='\0' && *b=='\0'){
	printf("%s\n",outputx);
	 return;
	 }


  if(*a!='\0'){
  outputx[pos]=*a;
  printallinterleaving(a+1,b,pos+1); }
  if(*b!='\0'){
  outputx[pos]=*b;
  printallinterleaving(a,b+1,pos+1);
  }

}


void main(){
na=strlen(a);
nb=strlen(b);
printallinterleaving(a,b,0);

}