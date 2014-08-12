// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    long int* array;
};

// function to create a queue of given capacity. It initializes size of
// queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (long int*) malloc(queue->capacity * sizeof(long int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

// Function to add an item to the queue.  It changes rear and size
void enqueue(struct Queue* queue, long int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.  It changes front and size
long int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
   long int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
long int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
long int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


void least_number(struct Queue *q,int n,int num){

  int temp;
  enqueue(q,num);
  while(1){

    temp=dequeue(q);
  if(temp%n==0){printf("%d\n",temp);return;}
   enqueue(q,temp*10);
   enqueue(q,temp*10+9);
}



}


int main(){
    struct Queue* q = createQueue(1000);
    int i,t,n[10000];
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%d",&n[i]);

    for(i=0;i<t;i++)
        least_number(q,n[i],0);


return 0;
}
