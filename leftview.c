#include<stdio.h>
#include<stdlib.h>
struct tree
{
	 int data;
	 struct tree *left, *right;
};
 
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
int maxlevel=0;
void leftview(struct tree *root,int level){
 if(!root)
 return;
 if(level==maxlevel){
 printf("%d",root->data);
 maxlevel++;}
 leftview(root->left,level+1);
 leftview(root->right,level+1);

}

void main(){

 struct tree *root = newnode(12);
	 root->left = newnode(10);
	 root->right = newnode(30);
	 root->right->left = newnode(25);
	 root->right->right = newnode(40);
	  leftview(root,0);
	 // root->right->right->right = newnode(10);

}