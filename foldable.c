//Program to check whether a binary tree is foldable or not
#include<stdio.h>
#include<stdlib.h>


 //Declare a tree
  struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};

struct tree *root;
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
		  printf( "%d ", root->data);
		  preorder(root->left);
		  preorder(root->right);
	 }
}

//Function to check whether a binary tree is identical or not
 int is_identical(struct tree *root,struct tree *foot){

	if(!root && !foot)
	return 1;







	 return (root && foot && is_identical(root->left,foot->left)&& is_identical(root->right,foot->right));

 }


 //Function to check a binary tree is foldable or not (return 1 or 0)
 int is_foldable(struct tree *root){

  if(!root)
  return 1;

  //	if(root->left &&


 }







void main(){
root = newnode(5);
	 root->left = newnode(7);
	 root->right = newnode(9);
  //	root->left->left  = newnode(8);
	root->left->right = newnode(6);
	//root->left->right->right = newnode(96);

	 //root->right->left  = newnode(4);
	 root->right->right = newnode(16);
	 //root->right->right->right = newnode(32);
	 //root->right->left->left  = newnode(19);
	 //root->right->left->right = newnode(3);
	 //root->right->left->left = newnode(44);
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	 preorder(root);

	 if(is_identical(root->left,root->right))
	 printf(" identical");
	 else
	 printf(" No ");

}