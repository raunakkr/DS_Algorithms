// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>
  int max_level=0;
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
	 if (max_level < level)
    {
        printf("%d\t", root->data);
		  max_level = level;
    }
 
    // Recur for left and right subtrees
	 leftViewUtil(root->left, level+1);
	 leftViewUtil(root->right, level+1);
}
 
// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
	 leftViewUtil(root, 1);
}
 
// Driver Program to test above functions
int main()
{
	 struct node *root = newNode(12);
	 root->right = newNode(30);
    root->right->right = newNode(40);
 
    leftView(root);
 
    return 0;
}
