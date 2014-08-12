
//Program to convert a binary tree to its sum tree
#include<stdio.h>
#include<stdlib.h>

//Declare a tree
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
//root node
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
void inorder(struct tree* root)
{
	 if (root)
	 {

		  inorder(root->left);
        printf( "%d \t ", root->data);
		  inorder(root->right);
	 }
}


//Function to convert a binary tree to sum tree
  int convert_to_sum_tree(struct tree *root){
	  int left,right,temp;
	 if(!root)
		  return 0;

	  left= convert_to_sum_tree(root->left);
	  right= convert_to_sum_tree(root->right);

		temp=root->data;
		root->data=left+right;
		return temp+root->data;
  }





void main(){

	 root = newnode(10);
	 root->left = newnode(-2);
	 root->right = newnode(6);
	 root->left->left  = newnode(8);
	 root->left->right = newnode(-4);
	 root->right->left=newnode(7);
	 root->right->right=newnode(5);

	 inorder(root);
	 printf("\n");
	 convert_to_sum_tree(root);
	  inorder(root);








}