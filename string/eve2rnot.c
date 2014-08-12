//Program to implement a circular buffer of size N
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Declare  a circular queue
struct queue{
  int capacity;
  int front,rear;
  char *a[10000];

};
 struct queue *q;
 int f_rear;

//Build  a queue
void build_buffer(int n){

		q=(struct queue*)(malloc(sizeof(struct queue)));
	  //Handle memory error if any
	  if(!q){printf("Memory error");return NULL;}
	  q->capacity=n;
	  q->front=-1;q->rear=-1;


}
//check if buffer is full
int is_full(){
  return ((q->rear+1)% q->capacity==q->front);
}
//Check if buffer is empty
int is_empty(){return (q->front==-1);}
//Returns current size of queue
int current_size(){return(q->capacity-q->front+q->rear+1)%q->capacity;}
//Append string to buffer
void append(char *str){



  if(is_full()){ printf("%d-%d-%d\n",q->front,q->rear,f_rear);
  q->a[f_rear]=str;f_rear=(abs((f_rear-1)))%q->capacity;return;}


  q->rear=((q->rear+1)% q->capacity);
  q->a[q->rear]=str;

  //printf("\n------%s",q->a[q->rear]);
  if(q->front==-1)q->front=q->rear;

  	 f_rear=q->rear;
  printf(">>>>>%d\n",f_rear);
  //printf("front element  %s\n",q->a[0]);
}

//Remove string from buffer
char *remove_element(){

	char *data=NULL;
	if(is_empty())return NULL;
	data=q->a[q->front];
	if(q->front==q->rear)q->front=q->rear=-1;
	else q->front=(q->front+1)%q->capacity;
	return data;

}
//Show buffer contents
void list_buffer(){

  int i,size,r=q->rear;
  //printf("Address %s",q->a[0]);
  if(is_empty()){printf("Buffer is empty");return;}

  r=q->rear;
 //printf(">>>>>>>>>>Buffer Contents>>>>>>>>>\n");
 //printf("\n%d-%d",q->front,q->rear);
 if(r<q->front)r=r+q->capacity;
 for(i=q->front;i<=r;i++)
printf("%s\n",q->a[i%q->capacity]);
//printf("mmm%s\n",q->a[0]);

}
  //convert command to required format
  int convert_to_integer(char *a,int j){

	 int i=0,temp;
	 int res=0;
	 if(!a)return 0;

 while(*(a-i)&& j>0){ temp=(int)*(a-i)-(int)'0';
				 res=res+(temp*pow(10,i));i++;
				// printf(">>>%d\n",res);
				 j--;}

		return res;

}




//Functions implementing commands
  void command_exec(char *command){
  int i,len,n;
		char *temp;
	if(!command)return;
  len=strlen(command);
  //printf(">>%d",len);
  if(len==1 && *command=='L'){
		list_buffer();
		  return;          }


	else if(len==1 && *command=='Q')
			 exit(0);
	 else if(len>1 && *command=='A'){

			//while there is "quantifiers" get all of them and convert to integer
		  n=convert_to_integer(command+(len-1),len-2);
		  //printf(">>");
		  for(i=0;i<n;i++){
temp=(char*)malloc(sizeof(char)*1000);
scanf("%s",temp);

append(temp);

					  }
	 return;
	 }
	 else if(len>1 && *command=='R'){

			//while there is "quantifiers" get all of them and convert to integer
			n=convert_to_integer(command+(len-1),len-2);
		  for(i=0;i<n;i++){remove_element();}
			  return;
	 }



		return;

  }








int main(){
int n,i=0;
char *com;
scanf("%d",&n);
if(n==0)return 0;
build_buffer(n);
while(1){
 com=(char*)malloc(sizeof(char)*10);

 gets(com);
command_exec(com);



}
 return 0;


}