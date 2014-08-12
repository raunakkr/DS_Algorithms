//Replace one character from string in place in just one pass
#include<stdio.h>
void main(){
 char a[]="abmxtbybt";
 int i,flag=0;
 for(i=0;a[i]!='\0';i++)
  {
	if(flag==i+1) {
	a[flag]=a[flag+1];
	flag++;}


	if(a[i]=='b')
	 {

	  a[i]=a[i+1];
	  a[i+1]=a[i+2];
	  flag=i+2;
	  i--;
	 }


  }

 printf("%s",a);

 }