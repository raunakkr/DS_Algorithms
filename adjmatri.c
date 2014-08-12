#include<stdio.h>
#include<stdlib.h>
int b[]={7,8,7};
struct graph{
int v;
int e;
int **adj;};


struct graph *createadjmatrix(){
  int i,u,v;

  struct graph *g=(struct graph*)(malloc(sizeof(struct graph)));
  if(!g)
  {printf("memory error");
  return;
  }
  g->v=2;
  g->e=2;
  printf("%d",sizeof(8));
  g->adj=malloc(1*sizeof(int));
	printf("%d",sizeof(b));
  for(i=0; i<2; i++)
{
	*(g->adj+i) = (int*)malloc(2*sizeof(int));
}
  for(u=0;u<g->v;u++)
	  for(v=0;v<g->v;v++)
		  g->adj[u][v]=0;

		  return g;



}


void main(){


	 createadjmatrix();



}