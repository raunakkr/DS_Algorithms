//Convert a sorted array to BST
#include<stdio.h>
#include<stdlib.h>
 int a[]={2,8,9,14,35,67};
struct tree
{
    int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root=NULL;
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


 //Converts a sorted array to BST
struct tree *convert_to_bst(int left,int right){
	 struct tree *temp=NULL;
	 int mid;
	 if(left>right)
		 return NULL;


	 mid=left+(right-left)/2;

	 temp=newnode(a[mid]);
	 temp->left=convert_to_bst(left,mid-1);
	 temp->right=convert_to_bst(mid+1,right);

	  return temp;


}




void main(){

  root=convert_to_bst(0,5);

  preorder(root);





}
