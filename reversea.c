//Program to reverse alternate K nodes in a linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct node *head=NULL;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct node *insertatend(int data){
	 struct node *p,*first;
	 p=NULL;
	 p=head;
	 if(!p)  {
    first=(struct node*)malloc(sizeof(struct node));
first->data=data;
first->next=NULL;
head=first;
return head;}
	 while(p->next!=NULL){ p=p->next; }
	 first=(struct node*)malloc(sizeof(struct node));
	 if(!first){printf("Memory error");return NULL;}
	 else{
	 p->next=first;
    first->data=data;
	 first->next=NULL;
	 printf("Node created");
	 return head;
	 }
}

//Traverse and prints list
	 void printlist(){
	 struct node *p=head;
	 if(!p){printf("Empty list");return;}
		while(p!=NULL){ printf("\n%d  ",p->data);p=p->next; }
	 }




//Main starts here
void main(){
int n,i,num;


  printf("Enter No. of nodes");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  { printf("Enter %dst node data ",i);
	 scanf("%d",&num);
	 if(!insertatend(num)){
		 printf("Memory error"); break;}

	 }

	 //prints list
    printlist();
}