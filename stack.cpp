#include<stdio.h>
#include<stdlib.h>
struct dynstack{
  int capacity;
  int top;
  int *array;


};

struct dynstack *st=NULL;
 int createstack();
 int pop();
 int top();
 int push(int);
 int isempty();
 int isfull();
void main(){


	 createstack();
		printf("top:%d\n",top());

	 push(5);
	 push(7);
	 push(9);
	 push(88);
	 //push(9);

		//pop();
		//pop();

		 pop();
       top();
		 pop();
        pop();pop();pop();pop();pop();
	  printf("%d\ntop: ",top());


}




int createstack(){
st=(struct dynstack*)malloc(sizeof(struct dynstack));
st->top=-1;
printf("Enter capacity");
scanf("%d",&(st->capacity));
//printf("%d",st->capacity);
//creating dynamic array of size "capacity"
st->array=(int*)malloc(sizeof(int)*(st->capacity));
if(!st->array)
{
  printf("Memory error");
  return 0;
  }

printf("Stack created.\n");
return st->top;
}


int push(int data){
 if(isfull()){
 printf("Stack Overflow");
 return st->top;}
 (st->top)++;
  st->array[st->top]=data;
  return st->top;


}



 int pop(){
 if(isempty()){
 printf("Stack underflow");
	 return st->top;

	 }
 printf("popped: %d",st->array[st->top]);
 st->top--;

 return st->top;


 }


 int top(){

 return st->top;


 }

 int isempty(){

  if(st->top==-1)
  return 1;
  else
  return 0;

 }

 int isfull(){
  if(st->top==(st->capacity)-1)
			 return 1;
			 else
			 return 0;

 }
