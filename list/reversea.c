//Rreverse alternate K nodes of a linked list
#include<stdio.h>
#include<stdlib.h>
void display_list(struct node*);
 //Declare  a list
	 struct node{
		int data;
		struct node *next;

	 };

  struct node *head;
  struct node *newhead;

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


//Reverse a list-segement till second argument "k"
	struct node *reverse_list_till_k(struct node *head,int k){
			 struct node *p,*temp,*ret,*prev;
			 int count=0; prev=NULL; ret=NULL;
			 if(!head)
			 return NULL;
			 if(k<0 || k==1 || k==0)
			 return NULL;

			 p=head;
		//Reverse K nodes
		while(count<k && head!=NULL){
			temp=head->next;
			head->next=prev;
			prev=head;
			head=temp;
			count++;}


	 //Move K nodes ahead
	 p->next=head;
	 count=1;
	 while(count<k && head!=NULL){
	 head=head->next;
	 count++;
	 }
	 if(head!=NULL)head->next=reverse_list_till_k(head->next,k);
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

	struct node *t;
	int k=2;
  head=create_node(1);
  head->next=create_node(2);
  head->next->next=create_node(3);
  head->next->next->next=create_node(4);
  head->next->next->next->next=create_node(5);
  head->next->next->next->next->next=create_node(6);
	display_list(head);
	 t=reverse_list_till_k(head,k);
  //	printf("%d",t->data);
	display_list(t);
}
