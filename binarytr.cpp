#include<stdio.h>
#include<stdlib.h>
 int makx=0,maxlevel=0,eq=0;
void preorder(struct tree *);
void printlevelwise(struct tree *,int);
void printleftchildonly(struct tree *,int);
int isallleafatsamelevel(struct tree *,int);
int isallleafatsamelevel2(struct tree *,int);
void leftboundary(struct tree *);
void rightboundary(struct tree *);
int printleaves(struct tree *);
struct tree *insert(struct tree*,int);
void boundarytraversal(struct tree *);
int findmax(struct tree *);
 void deepestleftleaf(struct tree *,int,int);
void fa(struct tree *);
void createmirror(struct tree *);
void deletenode(struct tree*,int);
void printgivenlevel(struct tree *,int);
int diffbwsumsoflevels(struct tree *,int);
int anc=0,oddsum=0,evensum=0;
void iterativetraversal(struct tree *);
int findsum(struct tree *);
struct tree *temp=NULL;
struct tree{

int data;
struct tree *left;
struct tree *right;


};

void main(){
//staticint max=0;
struct tree *rootR=(struct tree*)malloc(sizeof(struct tree));
struct tree *roota=(struct tree*)malloc(sizeof(struct tree));
struct tree *rootb=(struct tree*)malloc(sizeof(struct tree));

struct tree *rootc=(struct tree*)malloc(sizeof(struct tree));
struct tree *rootd=(struct tree*)malloc(sizeof(struct tree));
struct tree *roote=(struct tree*)malloc(sizeof(struct tree));
struct tree *rootf=(struct tree*)malloc(sizeof(struct tree));
struct tree *rootg=(struct tree*)malloc(sizeof(struct tree));

rootR->left=rootR->right=roota->left=roota->right=rootb->left=rootb->right=
rootc->left=rootc->right=rootd->left=rootd->right=roote->left=roote->right=rootf->left=rootf->right=rootg->left=rootg->right=NULL;
rootR->data=75;
roota->data=7;
rootb->data=3;
rootc->data=62;
rootd->data=1;
roote->data=15;
rootf->data=55;
rootg->data=9;

 rootR->left=roota;
 rootR->right=rootb;
 roota->left=rootc;
 roota->right=rootd;
 rootb->left=roote;
 rootb->right=rootf;
 //rootg->left=rootf;
 rootf->left=rootg;

 //preorder(rootR);
 //printf("\n");
 //printf("largest : %d",findmax(rootR));
 //fa(rootR);
 //createmirror(rootR);
 //printf("Sum of all nodes of a tree -  %d:\n ",findsum(rootR));
 //preorder(rootR);
 printgivenlevel(rootR,2);
 printlevelwise(rootR,0);
 //printleftchildonly(rootR,0);
  //deepestleftleaf(rootR,0,0);
  //if(temp)printf("%d",temp->data);
  //else
  //printf("No left child found");

  //if(isallleafatsamelevel2(rootR,0))
  //printf("All at same level");
  //else
  //printf("Not at same level");
	/*if(isallleafatsamelevel(rootR,0))
	printf("At same level");
	else
	printf("Not at same level"); */

	//printleaves(rootR);

	//printf("Difference b/w sums of odd and even level-  %d",diffbwsumsoflevels(rootR,0));
  //	boundarytraversal(rootR);
  //insert(rootR,333);
  //preorder(rootR);
  //deletenode(rootR,7);
  //printf("\n");
 // preorder(rootR);
}
//Traverses binary tree using PREORDER
void preorder(struct tree *root){
 if(root==NULL) return;
 printf("%d -",root->data);
 preorder(root->left);
 preorder(root->right);

}


//Finds Maximum of all nodes in a binary tree
int findmax(struct tree *root){
//static int max=0;
if(!root) return makx;
else{
if(root->data>makx)
  makx=root->data;

 if(root->left) findmax(root->left);
 if(root->right) findmax(root->right);}

 return makx;

}
//find ancestor of nodes in a binary tree
void fa(struct tree *root){
if(root==NULL)
return;
if(root->left){
 printf("Ancestor of %d - %d\n",root->left->data,root->data);
 fa(root->left);}
 if(root->right) {
printf("Ancestor of %d - %d\n",root->right->data,root->data);
fa(root->right); }


}
//Create a mirror of a binary tree
void createmirror(struct tree *root){
struct tree *temp;
if(root==NULL)
return;
createmirror(root->left);
createmirror(root->right);
temp=root->left;
root->left=root->right;
root->right=temp;


}

//finds SUM of all nodes in a binary tree
int findsum (struct tree *root){
if(!root)
return 0;

return (root->data + findsum(root->left) + findsum(root->right));



}

//Function to print all nodes of a tree levelwise as in level order fashion

	void printlevelwise(struct tree *root,int level){

	  if(!root)
	  return ;
	  if(level==0)
	//printf("At level %d:  %d\n",level,root->data);
	printf("%d\t",root->data);
	printlevelwise(root->left,level+1);
	printlevelwise(root->right,level+1);



	}

//Prints only left child of a node
	void printleftchildonly(struct tree *root,int done){
	if(!root)
	return;
	if(!done){
	printf("%d ",root->data);
	done=1;
	}
	printleftchildonly(root->left,!done);
	printleftchildonly(root->right,done);



	}

 //print deepest left leaf node in a tree
	  void deepestleftleaf(struct tree *root,int level,int done){
     if(!root)
	return;
	if(!done){
	//printf("%d ",root->data);
	if(level>maxlevel){
	maxlevel=level;
	temp=root;}
	done=1;

	}
	deepestleftleaf(root->left,level+1,!done);
	deepestleftleaf(root->right,level+1,done);



	  }

//check to see if all leaves of a binary tree at same level

	int isallleafatsamelevel2(struct tree *root,int level){
   if(!root)
{
  return 0;
}
if(root->left==NULL && root->right==NULL){
 if(!eq)
 eq=level;
 if(eq!=level){
 printf("no");exit(0);
	 }						  }
 isallleafatsamelevel2(root->left,level+1);
 isallleafatsamelevel2(root->right,level+1);

 return 1;
}


//print all leaves of a binary tree

int printleaves(struct tree *root){
if(!root)
{
  return 0;
}
if(root->left==NULL && root->right==NULL)
 printf("%d\n",root->data);

 printleaves(root->left);
 printleaves(root->right);
return 1;}

//Calculate diff. b/w sums of odd and even levels
int diffbwsumsoflevels(struct tree *root,int level){
if(!root)
return 0;
if(level%2==0)
 oddsum+=root->data;

if(level%2!=0)
evensum+=root->data;
  diffbwsumsoflevels(root->left,level+1);
  diffbwsumsoflevels(root->right,level+1);

	return (oddsum-evensum);

}
//BOUNDARYTRAVERSAL helper function to print left boundary nodes
void leftboundary(struct tree *root){
if(!root)
return;
if(!root->left && !root->right)
return;
printf("%d\t",root->data);
 leftboundary(root->left);


}
//BOUNDARYTRAVERSAL helper function to print right boundary nodes
void rightboundary(struct tree *root){
if(!root)
return;
if(!root->left && !root->right)
return;
rightboundary(root->right);
printf("%d\t",root->data);

}
//Prints only boundary nodes circularly starting from node
void boundarytraversal(struct tree *root){
		leftboundary(root);
		printleaves(root);
		rightboundary(root);


}

//Inserts a new element in a binary tree
struct tree *insert(struct tree *root,int data){
if(!root){
struct tree *temp=(struct tree*)(malloc(sizeof(struct tree)));
if(!temp){
printf("Memory error");
return NULL;}
temp->left=temp->right=NULL;
temp->data=data;
 return temp;
}
if(!root->left)
root->left=insert(root->left,data);
else
 insert(root->left,data);

}

//Deletes node of a binary tree
void deletenode(struct tree *root,int item){
 if(!root)
 return;
 if(root->data==item && root->left){
		root=root->left;
	 return;
	 }
  deletenode(root->left,item);
  deletenode(root->right,item);


}

//print nodes at given level )

	 void printgivenlevel(struct tree* root, int level)
{
  if(root == NULL)
	 return;
  if(level == 0)
	 printf("%d ", root->data);
  else if (level > 0)
  {
	 printgivenlevel(root->left, level-1);
	 printgivenlevel(root->right, level-1);
  }
}


//print nodes at given level (iterative version)

	 void iterativeprintlevelnodes(struct tree *root,int level){
	  //traverse while root is not null
	  while(!root){
        




	  }



	 }
