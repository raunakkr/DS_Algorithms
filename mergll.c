//Merge two sorted linked lists using recursion(Using Dummy node)
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *head=NULL;
struct node *read=NULL;
struct node dummy,*tempdummy;

//Create nodes of a linked list
struct node *create_node(int data){

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(!temp){
	 printf("Memory error");
	 return;

	}
	temp->data=data;
	temp->next=NULL;
	return temp;
}

 //Displays a linked list
 void display(struct node *head){
	struct node *p=head;

	while(p!=NULL){

	  printf("%d  ",p->data);
		p=p->next;

	}
}




//Merge sorted linked list
void merge_sorted_list(struct node *p,struct node *q){
			if(!p && !q)
			 return;

			 if(!p || !q){

			  tempdummy->next=p?p:q;
			  tempdummy=tempdummy->next;

			  merge_sorted_list(tempdummy->next,NULL);
             return;

			 }


			 if(p->data>=q->data) {
			 tempdummy->next=q;
			 tempdummy=tempdummy->next;
			 merge_sorted_list(p,q->next); }

			 else {
			 tempdummy->next=p;
			 tempdummy=tempdummy->next;
			 merge_sorted_list(p->next,q); }


}




//Main starts here>>>>>>>>>.
void main(){
 struct node *p,*q;
  dummy.data=21;
dummy.next=NULL;
tempdummy=&dummy;

	  head=create_node(5);

	  p=head;
	  p->next=create_node(10);
	  //p->next->next=create_node(13);

	  read=create_node(2);
	  q=read;
	  //q->next=create_node(11);

	  display(head);
	  printf("\n");
	  display(read);
	  merge_sorted_list(head,read);
		printf("\n");
	  display(dummy.next);

     



}