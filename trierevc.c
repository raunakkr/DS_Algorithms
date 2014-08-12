//Program to implement a fully functional trie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trie_n *createnode();
  char ot[20];
  int out_index=0;
  int num=0;

//Declaration of trie node
	struct trie_n{

		int value;
	  struct	trie_n *child[26];

	};
  //Declaration of trie  (A dummy node to start from)
  struct trie {
	 int count;
	 struct trie_n *root;
};

 struct trie *dummy;
//Converts character based array index to integer based
  int convert_to_index(char c){
	 return (int)c-(int)'a';
  }

//Convert integer based array index to character based
	char convert_to_char(int i){
  i=i+97;
return (char)i;

}

//Creates a new trie node
struct trie_n* create_node(){
  int i;
 struct trie_n *temp =(struct trie_n*)malloc(sizeof(struct trie_n));

  if(!temp){printf("Memory error");return;}

  temp->value=0;
  for(i=0;i<26;i++)
	temp->child[i]=NULL;

	return temp;
}

//Inserts words in trie
void insert_node(char *word){
 int length=strlen(word);
 int i=0;

 struct trie_n *temp=dummy->root;

	 dummy->count++;


 for(i=0;i<length;i++){
	  int current_index=convert_to_index(*(word+i));
	 if(!temp->child[current_index]){
		  temp->child[current_index]=create_node();
			}

		  temp=temp->child[current_index];
}

	  temp->value=dummy->count;

}

 //Displays all values inserted in a trie

 void display_trie(struct trie_n *temp,int pos){
	  int i,j;
	  if(!temp)
	  return;

		if(temp->value){
		  for(j=0;j<pos;j++)
			 printf("%c",ot[j]);
          printf("\n");


		  }


	for(i=0;i<26;i++){
		if(temp->child[i]){
		  ot[pos]=convert_to_char(i);

			 display_trie(temp->child[i],pos+1);
			  }
	  }

 }

 //Searches for given string returns 1 when found else 0
 int search_word(char *word){
	  int length=strlen(word);
	 int i=0;
	 struct trie_n *temp=dummy->root;
	 if(!temp)return 0;

		if(!word)
		return 0;

	  for(i=0;i<length;i++) {
		 int current_index=convert_to_index(*(word+i));
			  if(!temp->child[current_index])
			  return 0;
			  else
				temp=temp->child[current_index];
				  }
			 if(temp&&temp->value)
			  return 1;
			  else return 0;

 }

void main(){
	char *str[]={"ramtp","ram","rat","kar","carttt"};
	int length=sizeof(str)/sizeof(str[0]);
	int i;
	// initialize a trie(DUMMY node) here
	  dummy=(struct trie*)malloc(sizeof(struct trie));
dummy->count=0;
	dummy->root=create_node();
  //Inserts all words
  for(i=0;i<length;i++)
	  insert_node(str[i]);
display_trie(dummy->root,0);

search_word("ra")?printf("\nYes"):printf("\nNot found");

}
