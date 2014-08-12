//Program to check endianess of current system
#include<stdio.h>
void main(){

	int i=1;
	char *p;
	p= (char*)&i;
	if(*p) printf("Little Endian");
	else printf("Big Endian");


}