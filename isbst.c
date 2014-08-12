#include<stdio.h>
#include<stdlib.h>
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
  int count=0;
  int prev=0;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}


	 int isbst( struct tree *root) {

	 if(!root){
	 printf("Empty Tree");
	 return; }

	 if(root->left)
	 {isbst(root->left);} else if(count==0) {prev=root->data;}

	 if(root->data<prev){
		printf("This is not a BST");exit(0);}

		if(root->right)
		isbst(root->right);
	 }

	 int isbstv2(struct tree *root){

		  if(!root)
		  return 1;
		  if(!isbstv2(root->left))
			return 0;

			if(root->data>prev)
				prev=root->data;
				else
				return 0;

				if(!isbstv2(root->right))
				return 0;

				return 1;



	 }



void main(){

  root = newnode(3);
	 root->left = newnode(6);
	 root->right = newnode(18);
	root->left->left  = newnode(1);
	 root->left->right = newnode(7);
	 root->right->right=newnode(52);
	 root->right->left=newnode(14);
	isbst(root);
			  //isbstv2(root)?printf("Yes"):printf("No");

}