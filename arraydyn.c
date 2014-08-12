//Program for a resizable array

#include<stdio.h>
#include<stdlib.h>
int *resize();
void fill();
void show();
int *ptr;
int newv=2;
void main(){
ptr=(int*)malloc(sizeof(int)*2);
	int num;

	for(int j=0;j<2;j++)
	scanf("%d",ptr+j);

	show();

while(1){

printf("Kindly choose if you wish to fill data in an array\n");
scanf("%d",&num);

switch(num){
  case 'y':
  if(resize()) fill();
  break;

  case 'n':
  exit(1);
  break;

  default:
  printf("It seems there is an error");


}}
}

int *resize(){

	ptr=(int*)realloc(ptr,4*sizeof(int));
	if(!ptr) {
	printf("Memory error");
	return 0; }
	else
		newv+=4;
	return ptr;




}

void fill(){
printf("Enter %d values to fill array",newv);
for(int i=newv-4;i<newv;i++)

scanf("%d",ptr+i);
  show();
}

void show(){
  for(int i=0;i<newv;i++)
  printff("%d",ptr+i);



}
