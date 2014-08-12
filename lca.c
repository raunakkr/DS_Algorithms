// C program binary tree part 3
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
  struct tree *foot;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}
//Preorder traversal of a binary tree
void preorder(struct tree* root)
{
	 if (root)
	 {
		  printf( "%d \t ", root->data);
		  preorder(root->left);
		  preorder(root->right);
	 }
}
//find least common ancestor of two nodes
struct tree *lca(struct tree *root,struct tree *n1,struct tree *n2){
	struct tree *left,*right;
	if(!root || !n1 || !n2)
	return NULL;
	left=lca(root->left,n1,n2);
	right=lca(root->right,n1,n2);
	if(root==n1 || root==n2)
	  return root;
	  if(left && right){
	  return root;

	  }
	  else
	  return left?left:right;
	  

}


//To check wheteher a given binary tree is BST or not
int isbst(struct tree *root,int high){
int low,l=0,r=0;
  if(!root)
  return 0;
  low=root->data;
  if(low==high)
  high=9999;
  if(root->left){
if(root->left->data<low && (low<root->right->data<high))
	 l=isbst(root->left,low) && isbst(root->right,low);
	 }

	 if(root->right){
	 if(root->right->data>low && (low<root->left->data<high))
	 r= isbst(root->left,low) && isbst(root->right,low);
}

return l&&r ;



	 }

 //Convert a binary tree to a binary tree having children sum property
 void converttochildsum(struct tree *root){
 int sum=0;
 struct tree *mynode;
	if(!root)
	return;
   //
   if(!root->left && !root->right)
			return;
	//
	if(!root->left || !root->right){
		mynode=root->left?root->left:root->right;
		sum=mynode->data;
		if(sum-root->data>0)
		root->data=sum;
		else
		mynode->data=root->data;
   converttochildsum(mynode);
		return;}

	converttochildsum(root->left);
	converttochildsum(root->right);

	sum=root->left->data + root->right->data;
	if(sum-root->data>0)
	root->data=sum;
	else{
	root->left->data+=root->data-sum;
	converttochildsum(root->left);
	}
}

//Check whether two trees are identical in structure
int isidentical(struct tree *r1,struct tree *r2){
  if(!r1&&!r2)
	return 1;
	if(!r1 || !r2)
	  return 0;
	  if(r1 && r2)
	  return isidentical(r1->left,r2->left) && isidentical(r1->right,r2->right);
}

//Print all ancestors of a given node of  a binary tree

int printallancestors(struct tree *root,struct tree *n){
  if(!root || !n )
  return 0;
  if(printallancestors(root->left,n) || printallancestors(root->right,n)){
  printf("%d",root->data);
  return 1;
  }
  if(root==n)
  return 1;
  else
  return 0;

}

//Remove all nodes of a BST outside the given range
  struct tree *removenode(struct tree *root,int llimit,int rlimit){
	  if(!root)
	  return NULL;
	  root->left=removenode(root->left,llimit,rlimit);
	  root->right=removenode(root->right,llimit,rlimit);
	  if(root->data <llimit || root->data> rlimit){
		 if(root->left)root=root->left;
		 else if(root->right) root=root->right;
		 else root=NULL;
	  }
		  return root;


  }

//>>>>>>>>>>>>>>
void main(){

 root = newnode(14);
  root->left        = newnode(9);
  root->right       = newnode(18);
  root->left->left  = newnode(7);
  root->left->right = newnode(13);
  root->right->left  = newnode(16);
  root->right->right = newnode(32);
//>>>>>>>>>>Another binary tree for checking whether both are identical or not
  //foot = newnode(50);
  //foot->left        = newnode(7);
  //foot->right       = newnode(2);
 // foot->left->left  = newnode(3);
  root->left->right->left = newnode(11);
  //foot->right->left  = newnode(1);
  //foot->right->right = newnode(30);
	preorder(root);
	//converttochildsum(root);
	printf("\n");
	//preorder(root);

  // isidentical(root,foot)?printf("Yes"):printf("No");

 // printallancestors(root,root->left->right);
 preorder(removenode(root,1,32));

}