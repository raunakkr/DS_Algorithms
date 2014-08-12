//Implement a circular queue
#include<stdio.h>
#include<stdlib.h>
struct queue{
  int *a;
  int capacity;
  int front;
  int rear;
  int size;
};
  struct queue *q;
void create_queue(int cap){
	q=(struct queue *)malloc(sizeof(struct queue));
	q->capacity=cap;
	q->a=(int *)malloc(sizeof(int)*q->capacity);
	q->front=q->rear=-1;
	q->size=0;
}

void enqueue(int data){
  if(isfull()){printf("Queue is full");return;}
  if(isempty()){q->front=0;q->rear=q->front;
  q->a[q->rear]=data;q->size++;return;}

	q->rear=(q->rear+1)%q->capacity;

	q->a[q->rear%q->capacity]=data;
	q->size++;
}

int dequeue(){
  int temp;
  if(isempty()){printf("No element in queue");return -1;}
  if(current_size()==1){temp=q->a[q->front];q->front=q->rear=-1;q->size--;return temp; }

  temp=q->a[q->front];
  q->front=(q->front+1)%q->capacity;
		q->size--;
  return temp;


}

int isempty(){

  if(current_size()==0)return 1;
  else return 0;

}

int isfull(){

	if(current_size()==q->capacity) return 1;
	else return 0;


}

int current_size(){

return q->size;

}




int main(){

  create_queue(4);
  enqueue(2);
  enqueue(12);
  enqueue(22);
  enqueue(52);
  printf("%d\n",dequeue());
  printf("%d\n",dequeue());
  printf("%d=%d\n",q->front,q->rear);
  enqueue(58);
  printf("%d=%d\n",q->front,q->rear);
  printf("%d\n",dequeue());
  printf("%d\n",dequeue());
  printf("%d\n",dequeue());
  printf("%d\n",dequeue());
  enqueue(22);
  enqueue(52);
  printf("%d\n",dequeue());


}