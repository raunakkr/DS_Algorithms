//Program to add two linked list (NO extra space allowed)

#include<stdio.h>
#include<stdlib.h>

   //Declare a linked list
 struct node {
	int data;
	struct node *next;

 };
  struct node *head=NULL;
  struct node *read=NULL;
  //Node where a list is split
  struct node *q;
  //Node to store carry if any
	  struct node carry;
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

//Count no. of node in a linked list
  int count(struct node *p){
	  int count=0;
	 while(p!=NULL){
      count++;
		p=p->next;
}

  return count;
  }



//Function to add two linked list (NO extra space allowed)

  int add_list_same(struct node *head,struct node *read){
	 int sum;
	 if(!head && !read)
		return 0;



	 sum=head->data+read->data+add_list_same(head->next,read->next);

	 if(sum>=10){

	 head->data=sum-10;
	 return 1;

	 }
	 else      {
	 head->data=sum;
	 return 0;
	 }


  }

 //Function to add list with a given one digit number (0 or 1)
	int add_list_one(struct node *p,int carry){
		int sum;

		if(!carry)
		return 0;

	 if(p->next) sum=p->data+add_list_one(p->next,carry);

	 else
    sum=p->data+carry;



if(sum>=10){

	 p->data=sum-10;
	 return 1;

	 }
	 else      {
	 p->data=sum;
	 return 0;
	 }


	}
   
	//Joins two lists

	void join_list(struct node *start){
	  while(start->next!=NULL){
		 start=start->next;



	  }
		start->next=q;
	}

 //Function to add list irrespective of their no. of nodes

	struct node *add_list(struct node *head,struct node *read){

	 //Pointer to store bigger node head
	  struct node *bigger,*smaller,*temp;
		//Assume same no. of nodes
		int diff=0,hc,rc;
		hc=count(head);
		rc=count(read);
		 if(!head || !read){

			return head?head:read;
		 }


	  if(hc>rc){
			 diff=hc-rc;
			 bigger=head;
			 smaller=read;}
	  if(rc>hc){
		  diff=rc-hc;
		  bigger=read;
		  smaller=head;}
	 //If both lists have same no. of nodes
	  if(diff==0){
	  carry.data=add_list_same(head,read);
	  carry.next=head;
	  return &carry;
	 }
	//If both lists have different no. of nodes
	if(diff>0){
		  temp=bigger;
		while(temp!=NULL && diff>1){

			 temp=temp->next;
			 diff--;
		}
      q=temp->next;
		temp->next=NULL;

		carry.data=add_list_one(bigger,add_list_same(q,smaller));
		carry.next=bigger;
      join_list(&carry);

 }
		return &carry;
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






void main(){
 struct node *p,*q;
head=create_node(9);

	  p=head;
	  p->next=create_node(4);
	  //p->next->next=create_node(2);
	  //p->next->next->next=create_node(8);

  read=create_node(9);
	q=read;
	  q->next=create_node(2);
	  q->next->next=create_node(9);

	 display(p);
	 display(q);

	 printf("List after addition ");
	 add_list(head,read);



	 if(carry.data)
	 display(&carry);
	 else
	 display(head);

}
