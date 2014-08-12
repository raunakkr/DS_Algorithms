//Converting character to integer and vice versa

#include<stdio.h>
void main(){



 char cd='2';
 int d=4;
  char word='f';
  int num=4;
 int con;
 char conm;

 con=(int)cd-(int)'0';

 //if given characetr is '4' i.e integer based use following:-
	 // con=(int)cd-(int)'

 conm=(char)d+'0' ;

 printf("m%d-%c",con,conm);


//>>>>>>>>>>>>>>Array index>>>>>>>>>>>


  printf("\n%d",(int)word-(int)'a');	//convert "character" to "integer" for array indexing

  printf("\n%c",(char)((int)'a'+num));







}