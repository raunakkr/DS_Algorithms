// Convert a binary tree to Double linked list
#include<stdio.h>
#include<stdlib.h>
//Declare a tree
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root,*newhead=NULL;

// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}


 // Function for preorder traversal
void preorder(struct tree* root)
{
	 if (root)
	 {
		  printf( "%d \t ", root->data);
		  preorder(root->left);
		  preorder(root->right);
	 }
}

 struct tree *get(struct tree *root,int flag){
	if(!root)return NULL;
	if(!flag){
	while(root->right!=NULL)
		root=root->right;

		return root;}

	else if(flag) {
	while(root->left!=NULL)
		root=root->left;

		return root;}




 }






//Converts a binary tree to Double Linked List
 void convert_to_DLL(struct tree *root){
	  struct tree *p=NULL,*q=NULL;
	  if(!root)return;
		convert_to_DLL(root->left);
		p=get(root->left,0);
		root->left=p;if(p)p->right=root;
		convert_to_DLL(root->right);
		q=get(root->right,1);
		root->right=q;if(q)q->left=root;
      return;
	}

  //Diaplay a double linked list

	void display_DLL(struct tree *head){

	 struct tree *p;
	 p=head;
		if(!p){printf("Empty list");return;}
	while(p!=NULL){
	  printf("%d ",p->data);
	  p=p->right;

	}
	 printf("\n");
	}

 //>>>>>>>>>.Main Starts here>>>>>>>>
 void main(){
 struct tree *t;
 root = newnode(5);
	root->left = newnode(7);
	 root->right = newnode(8);
	 root->right->left = newnode(66);
	 root->left->right  = newnode(9);
	root->left->right->right  = newnode(2);
	 root->left->right->left  = newnode(52);
	// root->left->right = newnode(4);
	 //root->left->right=newnode(14);
	 //root->left->right->right=newnode(3);

  preorder(root);
  printf("\n");

  t=get(root->left,1);
  convert_to_DLL(root);

  display_DLL(t);
 // printf("%d>> ",t->data);
	 //display_DLL(newhead);



	}