//::::::::::::::::::Type Casting examples:::::::::::

#include<stdio.h>




int main(){
  int a=3;
  char c='d';
  char cnum='4';
	 // convert  "d" to "3"
		 printf("%d\n",(int)c-(int) 'a');

	 //convert "3" to "d"
		 printf("%c\n",(char)a+97);      //equivalent to   (char)((int)'a'+num)  because (int)'a'=97

	 //convert integer based character " '4' " to "4"(integer)
		 printf("%d\n",(int)(cnum-'0'));






return 0;
}
