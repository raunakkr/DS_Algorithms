//Program to calculate sum of two linked lists and store in any one of them(No extra Space allowed)
#include<stdio.h>
#include<stdlib.h>
//Declare a linked list
struct node{
	 int data;
	 struct node *next;};

//Head node of both lists
struct node *bigger,*smaller;


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


//Adds two lists(same size) and stores in any one list  and then returns CARRY if any
int add_list(struct node *head,struct node *read){
		struct node *bigger=head;
		struct node *smaller=read;
	 int carry=0;int sum=0;

	  if(!bigger && !smaller) return 0;

	 carry=add_list(bigger->next,smaller->next);

	 sum=bigger->data+smaller->data+carry;
	  if(sum>=10){
			bigger->data=sum-10;
			carry=1; }
	  else if(sum<10){
			bigger->data=sum;
			carry=0; }

			 return carry;
	 }


 


 //Add list _main
 struct node * add_list_main(struct node *head,struct node *read){
	 struct node *dummy;
	 if(!head && !read) return NULL;

	 if(add_list(head,read)){
		  dummy=create_node(1);
		  dummy->next=head;}
	  else dummy=head;

	  return dummy;
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
  bigger->next=create_node(9);
  bigger->next->next=create_node(9);

  smaller=create_node(9);
  smaller->next=create_node(9);
  smaller->next->next=create_node(9);
  display_list(bigger);
  display_list(smaller);

 display_list(add_list_main(bigger,smaller));

}