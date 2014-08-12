//Program to modify half of linked list subtracting from last element
#include<stdio.h>
#include<stdlib.h>
void display_list(struct node*);
 //Declare  a list
	 struct node{
		int data;
		struct node *next;

	 };

  struct node *head;
  struct node *q;
	int count=0;
	int n=1;
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

//Modify half of list
struct node *modify_list(struct node *p){
			  if(!p){q=head;return NULL;}

	  count++;
	  modify_list(p->next);
	if(n<(count/2)+1){q->data=p->data-q->data;
			q=q->next;
			n++;}





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
  head->next->next=create_node(3);
  head->next->next->next=create_node(4);
  head->next->next->next->next=create_node(5);
  head->next->next->next->next->next=create_node(6);
  head->next->next->next->next->next->next=create_node(7);
 // head->next->next->next->next->next->next->next=create_node(8);
  display_list(head);
	modify_list(head);
   if(count%2!=0)q->data=0;
   display_list(head);

}
