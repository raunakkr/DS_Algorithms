//This is an inefficient approach for queue implementation( ARRAY based )

#include<stdio.h>
void createqueue();
int dequeue();
int enqueue(int);
int rear,front,a[5];
int isfull();
int isempty();
int peek();
void main(){



  createqueue();
  enqueue(5);
  dequeue();
    peek();
}

void createqueue(){

front=-1;
rear=-1;

printf("Queue created\n");
}

 int isempty(){


	//important condition
	return(front==-1 || front==rear+1) ;


 }

 int isfull(){

 return(rear==4);
 }

 int enqueue(int data){

	 if(isfull()){
	 printf("Overflow\n");
		return 0;

		}

	if(front==-1 && rear==-1)
		front=rear=0;
	  else
		 rear++;
	 a[rear]=data;
	 printf("Enqueued %d\n",data);
    return front;
 }

 int dequeue(){
	 if(isempty())
	 { printf("Underflow");
		return 0;}

		 printf("Dequeued %d\n",a[front]);

		 front++;
          return front;


 }

 int peek(){


  printf("Front at %d\n",front);
  return front;


 }
