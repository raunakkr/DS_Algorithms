//program to print all nodes K distance away from given node both in upward & downward direction

#include<stdio.h>
#include<stdlib.h>
 //Declare a tree
  struct tree
{
	 int data;
	 struct tree *left;
	 struct tree *right;
};
  struct tree *root;
	int k=1;
	int rdata=3;
// A utility function to create a new Binary Tree node
struct tree *newnode(int item)
{
	 struct tree *temp =  (struct tree *)malloc(sizeof(struct tree));
	 temp->data = item;
	 temp->left = temp->right = NULL;
	 return temp;
}

  //print nodes in forward direction
  void print_node_k_distance_forward(struct tree *root,int dis,int flag){
	 if(!root)
	  return;



		//Check if node found
	  if(root->data==rdata)
	  //Set flag that node is found
		flag=1;



	  if(flag){
		  if(dis==k)
		  printf("%d  ",root->data);
	  print_node_k_distance_forward(root->left,dis+1,flag);
					  print_node_k_distance_forward(root->right,dis+1,flag);}

			  else {
					  print_node_k_distance_forward(root->left,dis,flag);
					  print_node_k_distance_forward(root->right,dis,flag);
					  }

  }



  //Print nodes in downward direction
  int print_node_k_distance_upward(struct tree *root) {
			  int left,right;
			 if(!root)
			 return 0;



			 if(root->data==rdata)
				 return 1;

			 left=print_node_k_distance_upward(root->left);
			 right=print_node_k_distance_upward(root->right);

			  if(left>0 && left<k)
				print_node_k_distance_forward(root->right,left+1,1);

				 if(right>0 && right<k)
				print_node_k_distance_forward(root->left,right+1,1);

			 if(left==k||right==k)
				 printf("%d ",root->data);

			  if(left>0)
			  return 1+left;

			  if(right>0)
				 return 1+right;

             return 0;




  }
	//Wrapper function for print k nodes away from given node
	  void print_k_away(struct node *root,int dis,int flag){

				 if(!root){
				 printf("Empty Tree");
				 return;
				 }

					if(k==0){
			 printf("%d\n",rdata);
			 return;}

			  print_node_k_distance_forward(root,0,0);
			  print_node_k_distance_upward(root);


	  }

  // Function for preorder traversal
void preorder(struct tree* root)
{
	 if (root)
	 {
		  printf( "%d ", root->data);
		  preorder(root->left);
		  preorder(root->right);
	 }
}

void main() {


  root = newnode(5);
	 root->left = newnode(7);
	 root->right = newnode(9);
	root->left->left  = newnode(8);
	root->left->right = newnode(6);
	root->left->right->right = newnode(96);

	 root->right->left  = newnode(4);
	 root->right->right = newnode(16);
	// root->right->right->right = newnode(32);
	 //root->right->left->left  = newnode(19);
	 root->right->left->right = newnode(3);
	 root->right->left->left = newnode(44);
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	 preorder(root);
		printf("\n");
	print_k_away(root,0,0);


}