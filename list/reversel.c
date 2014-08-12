//Program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

  //Declare  a list
	 struct node{
		int data;
		struct node *next;

	 };

  struct node *head;

 //Create a node
 struct node *create_node(int data){

	 struct node *temp=(struct node*)malloc(sizeof(struct node));
	 if(!temp){
		printf("Memory Error");
		return NULL; }

	 temp->data=data;
	 temp->next=NULL;
	  return temp;
 }
//Reverses a list
struct node *reverse_list(struct node *head){

  struct node *prev=NULL;
  struct node *curr,*temp;
		if(!head)
		return NULL;
	 curr=head;
  while(curr!=NULL){
	 temp=curr->next;
	 curr->next=prev;
	 prev=curr;
	 curr=temp;
}

  return prev;

}

 //Display a linked list

 void display_list(struct node *head){
	struct node *p=head;
	if(!p) {
	printf("Empty List");
	return; }

	 while(p!=NULL){

	 printf("%d ",p->data);
	 p=p->next;
}
	 printf("\n");
 }






void main(){


  head=create_node(1);
  head->next=create_node(2);
  //head->next->next=create_node(3);

	display_list(head);
	 head=reverse_list(head);
    display_list(head);

}
