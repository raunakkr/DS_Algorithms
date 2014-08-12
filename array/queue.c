#include<stdio.h>

struct queue{
  int capacity;
  int size;
  int front,rear;
int *a;
};
struct queue *q;
void create_queue(int capacity){
   q=(struct queue*)malloc(sizeof(struct queue));
   q->capacity=capacity;
   q->front=q->rear=-1;
   q->a=(int*)malloc(sizeof(int)*capacity);
   q->size=0;

}
int is_full(){return q->size==q->capacity;}
int is_empty(){return q->size==0;}
void enqueue(int data){
  if(is_full()){printf("Queue full\n");return;}

    q->rear=(q->rear+1)%q->capacity;
  q->a[q->rear]=data;

  if(q->front==-1)q->front=q->rear;
  printf("Pushed %d\n",data);
  q->size++;
}
void dequeue(){
if(is_empty()){printf("Queue empty\n");return; }
int temp=q->a[q->front];
q->front=(q->front+1)%q->capacity;
printf("Popped %d\n",temp);
q->size--;
}



int main(){
  create_queue(6);
  enqueue(10);
  dequeue();
dequeue();
enqueue(30);
enqueue(20);
dequeue();dequeue();
dequeue();
return 0;
}
