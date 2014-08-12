//This is a far more efficient approach for queue implementation( circular ARRAY based )

#include<stdio.h>
int createqueue();
void dequeue();
int enqueue(int);
int isfull();
int isempty();
int peek();

struct queue{
int front,rear;
int capacity;
int *array;


};

 struct queue *q=NULL;
void main(){



  createqueue();
  //enqueue(4);
  //dequeue();

}
 //Creates a queue after allocating resources
int createqueue(){
printf("jjjk");
 q=(struct queue*)malloc(sizeof(struct queue));
 if(!q)
 {
 printf("Memory error");
 return 0;

 }

printf("Enter capacity of queue\n");
scanf("%d",&(q->capacity));
q->front=-1;
q->rear=-1;
q->array=(int*)malloc(sizeof(int)*q->capacity);

if(!q->array)
{
  printf("Memory error");
  return 0;
  }


printf("Queue created\n");
printf("There is some error in reading input");
return 1;
}

//check whether queue is empty

 int isempty(){

	return(q->front==-1);

 }
//check whether queue is full
 int isfull(){

 return((q->rear+1)%q->capacity==q->front);
 return (((q->front)%(q->capacity))-1==q->rear);
 }
//Fill data in queue
 int enqueue(int data){

	 if(isfull()){
	 printf("Overflow\n");
		return 0;

		}

		q->rear=(q->rear+1)%q->capacity;
		q->array[q->rear]=data;
		return q->front;

 }
// Delete data from queue
 void dequeue(){
	 if(isempty())
	 { printf("Underflow\n");
		}

		 printf("Dequeued %d\n",q->array[q->front]);

		 if(q->front==q->rear)
			if(q->front==q->rear)
				  q->front=q->rear=-1;
				  else
					 q->front=(q->front+1)%q->capacity;


 }
 //Return front position
 int peek(){

  return (q->front);


 }