// Find maximum sum in path b/w two leaves
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
  int maxt=INT_MIN;
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

 int max_sum(struct tree *root){
	 int left,right;
	 if(!root)
		return 0;
	left= max_sum(root->left);
	right=max_sum(root->right);

   if(root->left!=NULL && root->right!=NULL)
	maxt=maxp(left+right+root->data,maxt);

	return maxp(left,right)+root->data;




 }



void main(){

root = newnode(-15);
	 root->left = newnode(5);
	 root->right = newnode(6);
	 root->left->left = newnode(-8);
	 root->left->right = newnode(1);
	 root->left->left->left = newnode(2);
	 root->left->left->right = newnode(6);
	 root->right->left = newnode(3);
	 root->right->right = newnode(9);
	 root->right->right->right= newnode(0);
	 root->right->right->right->left= newnode(4);
	 root->right->right->right->right= newnode(-1);
	 root->right->right->right->right->left= newnode(10);
                                                          
	 max_sum(root);

	 printf("Maximum sum is  %d",maxt);














}
