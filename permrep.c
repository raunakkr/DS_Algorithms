//Program to print all permutaion of given string with repeation taken into account
#include<stdio.h>
#include<string.h>
char a[]="abc";
char res[3];
int r=3;
void Permutenr()
 {       int i;
		if(strlen(res) == r) {
			 printf("%s",res);
      } else {
			  for(i=0; i<strlen(a); ++i){

					  res[i]=a[i];
					 Permutenr();
           }
		}
 }


void mian(){

Permutenr();


}