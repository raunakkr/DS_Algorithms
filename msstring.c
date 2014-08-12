#include<stdio.h>
#include<string.h>
#include<conio.h>
void main(){
	  int c=1,i,j;
 char str[]="hii1 \n hii2 \n hii3 \n hii4 \n hii5";

 printf("%s",str);

 for(i=strlen(str)-1;i>=0;i--) {
// printf("%c",str[i]);
	if(str[i]=='\n' && c<=2){
		c++;

	  for(j=i+1;;j++) {
		 if(str[j]=='\n' || j==strlen(str)){
		 printf("\n");
		 break; }
		 printf("%c",str[j]);
		 }
	  }
	}

	getch();
}