//Max heap Resizable :: All operations
#include<stdio.h>
#include<stdlib.h>

//Declare a heap data structure
  struct heap{
	 int count,capacity;
	 int *a;
	 
  };

//A global max-heap declaration
	struct heap *h;
//Create a binary max-heap
 struct heap *create_heap(){

	h=(struct heap*)malloc(sizeof(struct heap));
	if(!h){printf("Memory error");return NULL;}
	h->count=0;
	h->capacity=2;
	h->a=malloc(sizeof(int)*h->capacity);


	return h;

 }
//Returns left child of element
 int left_child(int i){
	 if(i<0)
		 return -1;
		 i=2*i+1;
	 if(i<0 || i>(h->count-1))
		return -1;

		return i;}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.keep
//Rteurns right child of an element
 int right_child(int i){
	  if(i<0)
		 return -1;

	 i=2*i+2;
	 if(i<0 || i>(h->count-1))
		return -1;

		return i;
 }

//Rturns parent of an element
 int parent(int i){
  if(i<0)
		 return -1;
		 i=(i-1)/2;
  if(i<0 || i>(h->count-1))
		return -1;

	  return i;

 }

//Percolate_down (Needed for deletion and building heap)

 void percolate_down(int i){
		int left,right,max=0,temp;
		if(i<0)
		 return -1;

	 left=left_child(i);
	 right=right_child(i);
	if(left!=-1 && h->a[left]>h->a[i])
			 max=left;
			 else
			 max=i;

		if(right!=-1 && h->a[right]>h->a[max])
			 max=right;

		if(max!=i){
		  //swap elements at  max & i
			 temp=h->a[max];
			 h->a[max]=h->a[i];
			 h->a[i]=temp;

			percolate_down(max);
		}

 }


//Percolate Up
void percolate_up(int i){
	  int parent,temp;
	  if(i<0 && (i>(h->count-1)))
		  return;
	  //find parent
	  parent=(i-1)/2;
	  if(parent==-1)
			return;

  while(h->a[i]>h->a[parent] && i>=0){
			//swap elements at  max & i
			 temp=h->a[parent];
			 h->a[parent]=h->a[i];
			 h->a[i]=temp;
			 i=parent;
			 parent=(i-1)/2;
			 }
}

//Resize heap (if more elements need to be inserted than capacity)
  struct heap *resize_heap(){
	  //if there is space
	  if(h->capacity>h->count)
			  return h;

		h->capacity=2*(h->capacity);
		h->a=realloc(h->a,h->capacity);
		if(!h->a){printf("Memory Error");return NULL;}
		return h;
  }

  //Insert element into heap
	void insert(int data){
		if(h->count==h->capacity)
			h=resize_heap();
		 //Increase heap size
			h->count++;
			//Place data at last
			h->a[h->count-1]=data;
		  	percolate_up(h->count-1);

  }

  //Fill a max-heap with given array

  void fill_heap(int p[],int n){
	 int i;
	 //Create space for allocation all array elements
	 while(n>h->capacity)
		h=resize_heap();
	 for(i=0;i<n;i++)
		 h->a[i]=p[i];
		 h->count=n;
       //Head to first non-leaf node
		 for(i=(n-2)/2;i>=0;i--)
			 percolate_down(i);
}

//find maximum element in heap(root)
  int top(){
	//if heap is empty return -1
	if(h->count==0)
		return -1;
	  return h->a[0];

  }


//Pop root element from heap
	int pop(){
	  int temp;
	  if(h->count==0)
		return -1;
temp=h->a[0];
  //copy last element at top
  h->a[0]=h->a[h->count-1];
	h->count--;
	//Heapify
	percolate_down(0);
	return temp;



	}


  //Print all heap elements
  void display_heap(){
		 int i;
	for(i=0;i<h->count;i++)
		printf(">>>>%d ",h->a[i]);
     printf("\n");
  }






void main(){
  int i;
int a[]={2,8};
int n=sizeof(a)/sizeof(a[0]);
h=create_heap();
  fill_heap(a,n);

  display_heap();

  printf("Top element is %d\n",top());

	 insert(77);
	 display_heap();
	printf("Top element is %d",top());

	  pop();
      display_heap();
		printf("Top element is %d",top());



}