//Program to convert a sorted double linked list to balanced binary search tree
#include<stdio.h>
#include<stdlib.h>

struct dl{
  int data;
  struct dl *next;                     //Declare a double linked list
  struct dl *prev;
};

struct dl *head=NULL;

 //Create a double linked list node
  struct dl *create_node(int data,struct dl *p){

	  struct dl *temp;
	  temp=(struct dl*)malloc(sizeof(struct dl));
	  if(!temp){printf("Memory Error");return NULL;}
	  temp->data=data;
	  temp->next=NULL;
	  temp->prev=p;

		return temp;
	  }




 //Inorder traversal
	void inorder(struct dl *head){
		if(!head)
		return;
		inorder(head->prev);
		printf("%d ",head->data);
		inorder(head->next);
}
//Returns mid of a list
  struct dl *get_mid(struct dl *head){
	struct dl *p;
	if(!head)return NULL;
	p=head->next;
   if(!p || !p->next)return head;

	while(p!=NULL){
		head=head->next;
		p=p->next;
}
	 return head;

  }


//Converts a sorted double linked list to a balanced BST
struct dl *convert_to_BST(struct dl *head){
	  struct dl *mid;
	  if(!head)return NULL;
	  mid=get_mid(head);
    // printf(">>>>>>>>%d\n",mid->data);
	 if(mid==head && !mid->next){
		mid->prev=NULL;
		mid->next=NULL;
		return mid;}

	if(mid->prev)mid->prev->next=NULL;
  if(mid->next)mid->next->prev=NULL;

  if(mid->prev)	mid->prev=convert_to_BST(head);
  if(mid->next)	mid->next=convert_to_BST(mid->next);
	return mid;

}

  //Display a Double linked list
  void display(struct dl *head){
	 struct dl *p;
	 if(!head)
	 {printf("List is empty");return;}
	 p=head;
	 while(p!=NULL){
	  printf("%d ",p->data);
	  p=p->next;

	 }
	 printf("\n");
	 return;
  }





void main(){

  head=create_node(2,NULL);
  head->next=create_node(5,head);
  head->next->next=create_node(7,head->next);
  //head->next->next->next=create_node(9,head->next->next);
  //head->next->next->next->next=create_node(17,head->next->next->next);



	display(head);

  inorder(convert_to_BST(head));





}