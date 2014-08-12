// Find diameter of a binary tree
#include<stdio.h>
#include<stdlib.h>
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
  int maxt;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}
  //Returns maximum of two nos;
	 int maxp(int a,int b){return a>b?a:b;}

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

 //Prints Diameter of a binary tree

 int diameter(struct tree *root){
	 int left,right;
	 if(!root)
		return 0;
	left= diameter(root->left);
	right=diameter(root->right);

	maxt=maxp(left+right+1,maxt);

	return maxp(left,right)+1;




 }



void main(){

root = newnode(5);
	 root->left = newnode(7);
	 root->right = newnode(8);

	 root->left->left  = newnode(9);
	 root->left->left->right  = newnode(2);
	 root->left->left->right->left  = newnode(52);
	 root->left->right = newnode(4);
	 root->left->right->left=newnode(14);
	 root->left->right->right=newnode(3);
	  root->left->right->right->right=newnode(33);
	root->right->left  = newnode(19);
	 root->right->right = newnode(32);









  diameter(root);

	printf("Diameter of a binary tree is %d",maxt);




}

