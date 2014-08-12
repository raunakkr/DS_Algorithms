// Program for DFS along with Graph creation
#include<stdio.h>
#include<stdlib.h>


//Graph declaration
struct graph{

 int v,e;
 int *adj;
};

struct graph *g;
int *visited;
int *ot,flag;
//initialize graph
void initialize_graph(int v,int e){

	 int i,j;
	  g=(struct graph*)malloc(sizeof(struct graph));
	  g->adj=(int*)malloc(sizeof(int)*v*v);
	  g->v=v;
	  g->e=e;

	  for(i=0;i<g->v;i++)                //Initialize adjacency matrix as zero
		for(j=0;j<g->v;j++)
		 *(g->adj+i*g->v+j)=0;


	visited=(int*)calloc(g->v,sizeof(int));
	ot=(int*)malloc(sizeof(int)*g->v);

}

//Add edges to graph
void add_edge(int x,int y){

		*(g->adj+x*g->v+y)=1;
		*(g->adj+y*g->v+x)=1;

}

//Check whether there is a hamiltonial cycle. If yes print that complete path
void display(){int i;for(i=0;i<g->v;i++)printf("%d ",ot[i]);printf("%d\n",ot[0]);}
void reset_visited(){int i;for(i=0;i<g->v;i++)visited[i]=0;}
int is_hamiltonian_cycle_util(int u,int pos){

	 int i;
	  if(pos==g->v-1){ot[pos]=u;if(*(g->adj+u*g->v+ot[0])){display();flag=1;return 1;}}
	  if(!visited[u]){visited[u]=1;ot[pos]=u;}
     else return 0;


	 for(i=0;i<g->v;i++){
		if(!visited[i] && *(g->adj+u*g->v+i))
		is_hamiltonian_cycle_util(i,pos+1); }

		return 0;
}

void is_hamiltonian_cycle_main(){
	int i;
	flag=0;
	for(i=0;i<g->v;i++){
	reset_visited();
	  is_hamiltonian_cycle_util(i,0);
		  }

	 if(!flag)printf("No hamiltonian cycle found in given graph");

}




int main(){
		int i,j;
	 initialize_graph(5,7);
	add_edge(0,1);
	 add_edge(1,2);
	 add_edge(2,4);
	 add_edge(0,3);
	 add_edge(1,4);
    add_edge(1,3);
	 add_edge(4,3);

   is_hamiltonian_cycle_main();




	 return 0;
}