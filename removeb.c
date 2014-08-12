//Remove 'b' 'ac'  from a string in one pass and in place.

#include<stdio.h>
#include<string.h>
  char a[]="asdbc";
void removeb(){
char *p=a,*q=a;
  if(strlen(a)<1){
	  printf("No string found");
	  return;}


	while(*q!='\0'){
		if(*q =='a' && *(q+1)=='c'){
			  q=q+2;
			}
	  else if(*q!='b'){
			*p=*q;
			 p++;
			 q++;
			}



		else{

			  q++;}

}

*p='\0';
}


void main(){
removeb();
printf("%s",a);

}