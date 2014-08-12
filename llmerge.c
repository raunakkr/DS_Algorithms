//Program to sort a linked list using merge sort
#include<stdio.h>
#include<stdlib.h>

 //Declare a linked list
 struct node {
	int data;
	struct node *next;

 };
  struct node *head=NULL;
  struct node dummy,*tempdummy;

 //Create a linked list
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
	if(!p)  {
	printf("Empty list");
	return;}

	while(p!=NULL){

	  printf("%d  ",p->data);
		p=p->next;

	}
   printf("\n");
}







//Get the mid of a linked list using slow-fast pointers
  struct node *get_mid(struct node *a){
		 struct node *slow,*fast;
		 if(!a)
		 return NULL;



		 slow=a;
		 fast=a;

		while(fast->next && fast->next->next){

		  slow=slow->next;
		  fast=fast->next->next;

		}

		return slow;


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

 //merge sorted listUTIL
struct node *merge_sorted_listUtil(struct node *p,struct node *q){
			struct node *r;
			merge_sorted_list(p,q);
			r=dummy.next;
			dummy.next=NULL;
         tempdummy=&dummy;
         return r;

}

//Merge sort (linked list)

struct node *merge_sort(struct node *a){
  struct node *pivot;
	struct node *mid;
	struct node *left,*right;
		if(!a)
		return NULL;
	if(a->next){
	mid=get_mid(a);
		pivot=mid->next;
		mid->next=NULL;

	  left=	merge_sort(a);
		right=merge_sort(pivot);

		return merge_sorted_listUtil(left,right);


		}
		else
		return a;

}

 void main(){
	struct node *p;
	 dummy.data=21;
dummy.next=NULL;
tempdummy=&dummy;


	head=create_node(5);

	  p=head;
	  p->next=create_node(3);
	  p->next->next=create_node(13);
		p->next->next->next=create_node(6);
			p->next->next->next->next=create_node(15);
			 	p->next->next->next->next->next=create_node(7);

	  display(p);

	  //printf("%d",get_mid(p)->data);

	display(merge_sort(p));
//    display(dummy.next->next);


}
