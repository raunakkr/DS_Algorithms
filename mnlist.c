//Program to alter a linked list with given two integers M & N .keep M  nodes and delete N nodes repetitively.

#include<stdio.h>
#include<stdlib.h>

//Declare a linked list
  struct node{
	 int data;
	 struct node *next;
  };
  struct node *head;
  int flag=1;
//Create a node of a linked list
	struct tree *create_node(int data){

		struct node *temp=(struct node*)malloc(sizeof(struct node));
		if(!temp)
		{ printf("Memory error");
		return;
		}

	temp->data=data;
	temp->next=NULL;
	 return temp;

	}
  //Delete n nodes from given node(including node)
	struct node *delete_node_from(struct node *left,int n){
		  //counter for counting nodes to be deleted
		  int counter=0;
		  struct node *temp;
		  struct node *nxt;
		  temp=left;
			if(!n || !left)
		  return left;
	  while(temp!=NULL && counter!=n){
			  nxt=temp->next;
			  printf("Node- %d being deleted\n",temp->data);
			  free(temp);
			  temp=NULL;

			  counter++;
			 //if counter equals 'n' return else proceed
			 temp=nxt;
			  if(counter==n)
			  return temp;

	  }
	  //set flag here
		  flag=0;
		  return temp;

}

  //Keep 'M' node of  a linked list
	 struct node *keep_node(struct node *left,int m){
	  //Counter
		int counter=0;
		struct node *temp=left;
		if(!m || !left)
		  return left;

		while(temp!=NULL && counter!=m){
		  counter++;
		  if(counter==m)
		  return temp;
		  else
		  temp=temp->next;
		  }

		  //set flag here
		  flag=0;
		  return temp;

 }

  void alter_list(int m,int n){
	 struct node *temp=head;
	 if(m==0){
	 printf("M can't be zero\n");
	 return;
	 }

	while(flag==1 && temp!=NULL){


	if(flag==1)

temp=keep_node(temp,m);

	  if(flag==1) {
	  temp->next=delete_node_from(temp->next,n);
	  temp=temp->next; }
	}



  }


  //Display  a linked list
  void display_list(){
	 struct node *temp=head;
	 while(temp!=NULL){

	  printf("%d  ",temp->data);
	  temp=temp->next;

	 }

    printf("\n");

  }




void main(){
  int m=2,n=3;
	struct node *t1=create_node(2);
	head=t1;
	t1->next=create_node(5);
	t1->next->next=create_node(7);
	t1->next->next->next=create_node(9);
  t1->next->next->next->next=create_node(11);
	t1->next->next->next->next->next=create_node(13);
	t1->next->next->next->next->next->next=create_node(15);

	display_list();

	alter_list(m,n);

	display_list();
  }
