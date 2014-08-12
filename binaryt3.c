// C program binary tree part 2
#include<stdio.h>
#include<stdlib.h>
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
  struct tree *head=NULL;
  int c=0;
  int mysum=17;
  int maxdiameter=0;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}

//calculates maximum of two nos.


	int maxnum(int a,int b)
	{return a>b?a:b;}
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


//Function to convert a BST to double linked list(DLL)
  struct tree *todl(struct tree *root,int dir){
	 if(!root)
	 return NULL;
  if(root->left)	 if(root->left->left || root->left->right){root->left=todl(root->left,0);root->left->right=root;}
	if(root->right) if(root->right->left || root->right->right){root->right=todl(root->right,1);root->right->left=root;}

	 if(root->left){ if(c==0){head=root->left;c++;} root->left->right=root; }
	 if(root->right){if(c==0){head=root->right;c++;} root->right->left=root; }
	 if(c==0){head=root;c++;}

	 if(dir==0 && root->right) return root->right;
	 else if(dir==1 && root->left) return root->left;
	 else return root;
}
//Double linked list traversal

void DLtraversal(struct tree *root){
	 struct tree *p=root;
		if(!p){
		printf("Empty list");
		return;}
	 while(p!=NULL){
	 printf("%d  ",p->data);
	 p=p->right;
	 }


}
//Calculates the diameter of tree
int diameter(struct tree *root){
	  int left,right;
	  if(!root)
	  return 0;
	 left=diameter(root->left);
	 right=diameter(root->right);

	 if(left+right>maxdiameter)
			maxdiameter=left+right;

		return maxnum(left,right)+1;


}

//calculate height of tree in TOP DOWN manner
  int height(struct tree *root,int level){
	 int i;
	 if(!root)
	 return 0;
	 i=maxnum(height(root->left,level+1),height(root->right,level+1));
	 return maxnum(i,level);}

void main(){

//create binary tree >>>>>>>>>>>>>>>>>>>>>>>
	  root = newnode(10);
	 //root->left = newnode(7);
	 root->right = newnode(16);
	//root->left->left  = newnode(26);
	//root->left->right = newnode(14);
	 //root->left->right->left=newnode(14);
	 //root->left->right->right=newnode(5);

	 root->right->left  = newnode(19);
	// root->right->right = newnode(32);
	// root->right->right->right = newnode(32);
	 //root->right->left->left  = newnode(19);
	 //root->right->left->right = newnode(32);
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	preorder(root);
	printf("\nHeight of tree is  %d",height(root,1));
	}