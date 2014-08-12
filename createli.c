#include<stdio.h>
#include<stdlib.h>
struct node{

int info;
struct node *link;


};

void display(struct node *start);
struct node *addatbeginning(struct node *start);
struct node *addatend(struct node *start);
struct node *insertatNth(struct node *start,int);
int count(struct node *start);
void main(){
int i,n,mid,k=0;
struct node *temp;
struct node *start=NULL;
printf("Please enter no. of nodes in linked list ");
scanf("%d",&n);
temp=(struct node*)malloc(n*sizeof(struct node));

//Assign base address of block to start

start=temp;

//Loop n times to get the user data and store them at dynamically allocated block

for(i=0;i<n;i++)
{   
for( ;k<n;k++) {

printf("%u\t",(temp+k));

}
printf("Enter next data for linked list\n");
scanf("%d",&mid);
(temp+i)->info=mid;

if(i!=n-1){

		(temp+i)->link=temp+(i+1);
printf("start  block is pointing at  %u \n",(start));
printf("next  block should point at %u \n",(temp+i)->link);


}
else
(temp+i)->link=NULL;
}
 
 
//display(start);
//start=addatbeginning(start);
//start=addatend(start);
start=insertatNth(start,5);
//display(start);
printf("count is %d",count(start));

 }

//function to display contents of linked list by sending start pointer

void display(struct node *start){
 struct node *t;
 t=start;
 while(t!=NULL) {
 //printf("link of t %u\n",t->link);
 printf("data in linked list are %d\n",t->info);
 t=t->link;
 }}


 //function to create a node at the beginning of list
 struct node *addatbeginning(struct node *start){

	struct node *to;
    int md;
	to=(struct node*)malloc(sizeof(struct node));
	printf("new block allocated  %u\n",to);
	printf("please enter data at this node");
	scanf("%d",&md);
	to->info=md;
	 printf("start link obtained %u",start);
	to->link=start;
	printf("t got the link %u",to->link);

	start=to;
	printf("start new link%u",start);
	return start;


 }

 struct node *addatend(struct node *start){
  struct node *t,*p;
  int md;
  t=start;
  p=(struct node*)malloc(sizeof(struct node));
  while(t->link!=NULL){
	t=t->link;
}
t->link=p;
	printf("%d%u",t->info,t->link);

	printf("Enter data");
	scanf("%d",&md);
	p->info=md;
	p->link=NULL;
	return start;

}

//function to insert node at nth place where n is supplied by argument
struct node *insertatNth(struct node *start,int n){
if(n<=count(start)){
  struct node *t,*p;
  int md,count=1;
	t=start;
	p=(struct node*)malloc(sizeof(struct node));
	while(t->link!=NULL){
	//From first cycle 't' is already pointing at first location
	//Hence for n=2, we have to stop here 
	if(n==2)
	break;
	t=t->link;
	count++;
	if(count==n-1)
	break;  }

	printf("Enter data at %dth node",n);
	scanf("%d",&md);
	p->info=md;
	p->link=t->link;
	t->link=p;
	return start;
	}
	else
	printf("Sorry!! You are placing outside limit");
   return start;
}
//function to count no. of nodes in linked list having start as argument

int count(struct node *start){
struct node *t;
int count=1;
t=start;
while(t->link!=NULL)
{
 t=t->link;
 count++;
}
  return count;


}


//function to reverse nodes in a linked list





