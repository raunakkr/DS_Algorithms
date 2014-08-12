//Implement BST operations :: Insert & Delete
#include<stdio.h>
#include<stdlib.h>

//Declare a tree data structure
struct tree {
  int data;
  struct tree *left,*right;
};
//Global root node
struct tree *root;

//Create a tree node
  struct tree *create_node(int data){

	 struct tree *temp;
	 temp=(struct tree*)malloc(sizeof(struct tree));
	 if(!temp){printf("Memory Error"); return;}

	 temp->data=data;
	 temp->left=NULL;
	 temp->right=NULL;

	 return temp;
}
 //Get maximum in a BST
 struct tree *get_max(struct tree *root){

		if(!root)
		return NULL;

		if(!root->right)
			 return root;
			 else
			return get_max(root->right);

 }



//Insert a node in a BST
	struct tree *insert_node(struct tree *root,int data){

		if(!root){
		root=create_node(data);
		return root;}

		if(data>root->data)
		 root->right=insert_node(root->right,data);

		if(data<root->data)
		 root->left=insert_node(root->left,data);


		 return root;

}

//Delete a node in BST

  struct tree *delete_node(struct tree *root,int data){
		 struct tree *temp=NULL;
	  if(!root)
		 return NULL;


	  //check if this is the node we want to delete
	 if(root->data==data){

			//if this is leaf node or has just one child
			  if(!root->left || !root->right){
					temp=root->left?root->left:root->right;
					root=temp;
					}

			//if this node has both child or one child

			  else if(root->left && root->right){
						temp=get_max(root->left);
						root->data=temp->data;
					  root->left= delete_node(root->left,root->data);

			  }}

	 else if(data>root->data)
				root->right=delete_node(root->right,data);

	 else if(data<root->data)
				root->left=delete_node(root->left,data);

		  return root;
  }



//Inorder :: Tree Traversal
	void inorder(struct tree *root){
	  if(!root)
		 return;

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);

	}











void main(){
	int i;
	int a[]={2,5,8,1,7,6};
	int n=sizeof(a)/sizeof(a[0]);

  for(i=0;i<n;i++)
	  root=insert_node(root,a[i]);

	 inorder(root);

	root= delete_node(root,6);
    printf("\n");
   inorder(root);





}