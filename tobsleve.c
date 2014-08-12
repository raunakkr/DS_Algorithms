//Program to create a binary tree from inorder and level order traversal
#include<stdio.h>
#include<stdlib.h>

int in[]    = {4, 8, 10, 12, 14, 20, 22};
int level[] = {20, 8, 22, 4, 12, 10, 14};

int n;


//Declare a tree node
struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}
 // Function for inorder traversal
void inorder(struct tree* root)
{
	 if (root)
	 {

		  inorder(root->left);
		  printf( "%d \t ", root->data);
		  inorder(root->right);
	 }
}

//search in inorder array
  int search_lt(int num,int left,int right){

		 int i;

		 for(i=left;i<=right;i++){
			if(in[i]==num)
			return i;

		 }
			 return -1;




  }







 struct tree *create_tree(int left,int right,int local){

	 int mid=-1;
	 struct tree *temp;


	 if(left>right || left<0 || right>n-1)
	  return NULL;
	//Finds first node in levelorder next to index 'local'(including local)
	//which ets a match in inorder array from index 'left' to 'right'
	//
	 while(mid==-1 && local<=n-1){
	 mid=search_lt(level[local],left,right);
	 local++;
	 }
	temp=newnode(in[mid]);
	//pass 'local' as argument since we know 'temp' children will be next
	//to 'local' somewhere in 'level' array  
	temp->left=create_tree(left,mid-1,local);
	temp->right=create_tree(mid+1,right,local);

		 return temp;





 }










void main(){

  n=sizeof(in)/sizeof(in[0]);
root=create_tree(0,n-1,0);
  inorder(root);

}