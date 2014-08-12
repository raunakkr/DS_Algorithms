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
  int mysum=17;
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
//function to alter node data with sum of all descendent data

  int alterwithsum(struct tree *root){
	int sum=0;
	if(!root)
	return 0;
	if(root->left)
	sum+=alterwithsum(root->left);
	if(root->right)
	sum+=alterwithsum(root->right);
	if(root->left || root->right)
	root->data=sum;
	return root->data;
	//return (root->left->data) + (root->right->data);



  }

  void deletelesssum(struct tree *root,int sum,int k){
	  if(!root)
	  return;
	  if(root->left==NULL && root->right==NULL && sum+root->data<=k){
		 //free this node
		 //printf("%d\n",root->data);
		 free(root);
       root=NULL;
       //root->data=888;

		 return;   }
		 //exit(0); }

	  deletelesssum(root->left,sum+root->data,k);
	  deletelesssum(root->right,sum+root->data,k);

  }

  //Replace each node with sum of all greater nodes
  void replaced(struct tree *root,struct tree *m){
	 if(!root)
	 return;
	 if(root->left)replaced(root->left,m);
	 if(root->right)replaced(root->right,m);
	 if(root->left){root->left->data=mysum-(root->left->data); mysum=root->left->data;
	// printf("%d",mysum);
	}
	if(root==m){root->data=mysum-root->data;mysum=root->data;}
    //if(!(root->left && root->right)){mysum=mysum-(root->data);root->data=mysum; }
	 if(root->right){root->right->data=mysum-(root->right->data); mysum=root->right->data;}
    return;
	 
  }

  void main(){
  //create binary tree >>>>>>>>>>>>>>>>>>>>>>>
	  root = newnode(10);
	 root->left = newnode(7);
	 //root->right = newnode(16);
	// root->left->left  = newnode(10);
	 //root->left->right = newnode(14);
	 //root->left->right->left=newnode(14);
	 //root->left->right->right=newnode(5);

	 //root->right->left  = newnode(19);
	 //root->right->right = newnode(32);
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	preorder(root);
	printf("\n");
	//alterwithsum(root);
	//deletelesssum(root,0,15);
	replaced(root,root);


	preorder(root);

  }
