#include<stdio.h>
#include<stdlib.h>

struct graph{
int v,e;
int *adj;};

struct graph *g;
//Creates a graph having vertices and edges
void creategraph(){
  g=(struct graph*)(malloc(sizeof(struct graph)*1));
 if(!g){
  printf("Memory errorp");
  return;}
printf("Enter no. of vertices");
  scanf("%d",&g->v);
 printf("Enter no. of edges");
  scanf("%d",&(g->e));
  g->adj=(int*)calloc(g->v*g->v,sizeof(int));
  if(!g->adj){
  printf("Memory error");
  return;}

}



//Adds pair of edges to graph
struct graph *addedge(int a,int b){

	 if(a>g->v-1 || b>g->v-1 ||a<0 || b<0){
		printf("Entered edge pair is out of vertice range");
		return NULL;}
	  *((g->adj)+a*(g->v)+b)=1;
	 //For undirected graph
	  *((g->adj)+b*(g->v)+a)=1;
	  return g;

}


//Check if graph has cycle
  int checkcycle(){
	 if(!g){
	 printf("No graph found");
	 return 0; }



  }

void main(){
  int i,j,a,b;
  creategraph();
  for(i=0;i<g->e;i++){
	 printf("Enter pair of edges");
	 scanf("%d%d", &a,&b);
  addedge(a,b);
  //	printf("Error");
	//break;}


  }

for(i=0;i<g->v;i++) {
  for(j=0;j<g->v;j++)
	 printf("%d ",*((g->adj)+i*(g->v)+j));
	 printf("\n");
    }

  }
