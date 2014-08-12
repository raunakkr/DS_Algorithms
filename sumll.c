//Program to calculate sum of two linked list
#include<stdio.h>
 //2nd list pointer
  struct node *sec=NULL;




int addlist(struct node *p){
 if(!p && !sec)
	 return 0;
  //Check if we have come to equivalent position
  if(diff>0){
	 diff--;
	carry=addlist(p->next);

  }
  else{
	sec=read;
	carry=addlist(p->next); }
	//check if 2nd node has data
	bottom=sec?sec->data:0;

	 carry=p->data+bottom+carry;
	 //Set the sum at this node and pass the carry
	 p->data=carry

	 if(carry>9)
		  return 1;
		  else return 0;

}













void main(){}
