//Program to calculate sum of two linked lists and store in any one of them(No extra Space allowed)
#include<stdio.h>
#include<stdlib.h>
//Declare a linked list
struct node{
	 int data;
	 struct node *next;};

//Head node of both lists
struct node *bigger;


//Create a linked list node
struct node * create_node(int data){
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 if(!temp){printf("Memory Error");return NULL;}
 temp->data=data;
 temp->next=NULL;
 return temp;

}

//Get count of nodes in linked list
int get_count(struct node *head){
  int count=0;
  struct node *p=head;
  if(!p)return 0;
  while(p!=NULL)
  {count++;p=p->next;}

  return count;
}

//Reverse K alternate nodes
  struct node *reverse_alternate_k_nodes(struct node *p,int k){
	  struct node *prev,*q,*temp;
	  int count;
     if(!p)return NULL;
	  while(p!=NULL){
		 count=0;
		 prev=NULL;q=p;

			 while(count<=k-1 && p){

				 temp=p->next;
				 p->next=prev;
				 prev=p;
				 p=temp;
				 count++;
			 }
	  count=0;
	  q->next=p;
	  while(count<k-1 && p!=NULL){p=p->next;count++;}

//	  printf("%d  \n",p->data);
      if(p) p->next=reverse_alternate_k_nodes(p->next,k);

     return prev;



	  }






  }









//Display list
void display_list(struct node *head){
	struct node *p=head;
	if(!p){printf("Memory Error");return;}

	while(p!=NULL){
	 printf("%d ",p->data);
	 p=p->next;

	}
	printf("\n");
  return;

}


void main(){

  bigger=create_node(9);
  bigger->next=create_node(8);
  bigger->next->next=create_node(7);
  bigger->next->next->next=create_node(27);
  bigger->next->next->next->next=create_node(77);
  bigger->next->next->next->next->next=create_node(55);
  bigger->next->next->next->next->next->next=create_node(85);
  bigger->next->next->next->next->next->next->next=create_node(33);
  display_list(bigger);

  display_list(reverse_alternate_k_nodes(bigger,3));


}
