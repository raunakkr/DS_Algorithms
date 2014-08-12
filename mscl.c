#include<stdio.h>
#include<stdlib.h>
struct cl{
int data;
struct cl *next;};
struct cl *start=NULL;
int count=1;
struct cl *insertnode(struct cl *node,int data){
   struct cl *temp;
		 if(!node){

		 temp=(struct cl*)malloc(sizeof(struct cl));
		 if(!temp){
		 printf("Memory error");
		 return NULL;}
		 temp->data=data;
		 if(count==1)
		 start=temp;
		 count++;
		 temp->next=start;
		 return start;
		 }
	 else
	 {  //insert data in a regular fashion
		  struct cl*p=start;
		  do{
				p=p->next;
		  }
			while(p->next!=start);
			temp=(struct cl*)malloc(sizeof(struct cl));
		 if(!temp){
		 printf("Memory error");
		 return NULL;}
		 temp->data=data;
		 p->next=temp;
		 temp->next=start;
		 return start;
	 }


		 }


  void displaylist(){
	 struct cl *p=start;
	 do{
        printf("%d",p->data);
		  p=p->next;  }

		  while(p!=start);

  }

void main(){

 struct cl *c=insertnode(NULL,2);
 insertnode(c,5);
 insertnode(c,8);
 insertnode(c,9);

 displaylist();

}