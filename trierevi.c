//Program to match one string from another as a percentage(flipkart intreview
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int indext(c){ return  (int)c-(int)'a';}
char ot[10];
int count=0;
int k=0;

struct trie{
  char data;
  int is_end;
  struct trie* child[26];
};



struct trie *root=NULL;
struct trie *foot;
//struct trie *temp;

struct trie *inst(struct trie *root,char *word){
		 int i;
	if(!word)
	return NULL;
	  //printf("%d\n",index(*word));
	if(!root){
	struct trie  *temp=(struct trie*)malloc(sizeof(struct trie));
	  if(!temp){printf("Memory error");return;}
	  temp->data=*word;
	  for(i=0;i<26;i++)
		temp->child[i]=NULL;
	  if(!*(word+1)) temp->is_end=1;
	  else {
		temp->child[indext(*word)]=inst(temp->child[indext(*word)],word+1);
		return temp; }

		}
		else{
	  //	printf(" %d",k++);
	  root->child[indext(*word)]=inst(root->child[indext(*word)],word+1);
	  return root; }

	}

	 void display(struct trie *root){
		 int i,count=0;
		  if(!root)
		  return;

		  ot[count]=root->data;
		  count++;
		 printf("%c",root->data);
		  for(i=0;i<26;i++)
			  display(root->child[i]);

				if(root->is_end==1)
				 printf("%s\n",ot);


		  }











void main(){
	int i=0;

	  //	char* a[]={"ram","shyam","rat","sharika","shaam"};
//int arraylength= sizeof(a)/sizeof(a[0]);

	  char a[]="r";
	  char b[]="ra";
	 root=inst(root,a);
	 root=inst(root,b);
	 //display();

	  display(root);
	 /*while(i<arraylength){

	  root=inst(root,a[i]);
		//printf("%s",a[i]);
		i++;

	 }
	 display(root);   */
}









