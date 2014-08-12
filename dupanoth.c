//Program to remove all characters from one string those are in second string
#include<stdio.h>
void main(){
 int i,j=0;
 int c[20]={0};
 char a[]="tmesktkmmmsku";
 char b[]="mask";
 int d[4];
 //printf("%s",a);
 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	 d['m']=1;
	 d['a']=1;
	 d['s']=1;
	 d['k']=1;

 //>>>>>>>>>>>>>>>>>>>>>>>>>>

 for(i=0;a[i];i++) {

	if(d[a[i]]!=1){
   a[j]=a[i];
	j++; }

  }
  a[j]='\0';

  printf("%s",a);
  }