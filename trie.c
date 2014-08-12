#include<stdio.h>
#include<stdlib.h>
int index(c){ return((int)c - (int)'a');}
struct trie *insertnode(struct trie *,char *);
void displaytrie(struct trie *);
struct trie{
 char data;
 int is_end;
 struct trie *child[26];
};
 void main(){

		char c[]="hot";
	  char d[]="utm";
	  struct trie *curr=insertnode(NULL,c);
	  struct trie *urr=insertnode(curr,d);
	  displaytrie(urr);


}
struct trie *insertnode(struct trie *root,char *word){
		int i;
		if(!word) return NULL;

	  if(!root){
			struct trie *t=(struct trie*)malloc(sizeof(struct trie));
			 if(!t){
					 printf("memory error");
					 return NULL;
					 }
			 t->data=*word;
			 for(i=0;i<26;i++)
				  t->child[i]=NULL;
			 if(!*(word+1)){
					 t->is_end=1;
					 return t;
							  }
			 else{
					t->is_end=0;
					t->child[index(*word)]=insertnode(t->child[index(*word)],word+1);
					  return t;
				  } }

			  root->child[index(*word)]=insertnode(root->child[index(*word)],word+1);
					 return root;


}



void displaytrie(struct trie *root){
    int i;
	if(!root)
	return;

 printf("%c",root->data);
 if(!root->is_end){
		displaytrie(root->child[index(root->data)]);
		}
			  
	return;
 }





