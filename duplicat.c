#include<stdio.h>
void main(){
 int i,j=0;
 int c[20]={0};
 char a[]="bbbbbytyty";

 for(i=0;a[i];i++) {

	if(c[a[i]]==0){
	c[a[i]]=1;
   a[j]=a[i];
	j++; }

  }
  a[j]='\0';

  printf("%s",a);
  }
