// Program for DFS along with Graph creation
#include<stdio.h>
#include<stdlib.h>


//Graph declaration
struct graph{

 int v,e;
 int *adj;
};

struct graph *g;
int *visited,*parent;
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
	parent=(int*)malloc(sizeof(int)*g->v);
	for(i=0;i<g->v;i++)
	  parent[i]=-1;

}

//Add edges to graph
void add_edge(int x,int y){

		*(g->adj+x*g->v+y)=1;
		*(g->adj+y*g->v+x)=1;

}

//DFS Traversal
void dfs(int u){
	int i;
	visited[u]=1;
	//printf("%d ", u);
	for(i=0;i<g->v;i++){

	  if(!visited[i] && *(g->adj+u*g->v+i)){
			parent[i]=u;
			dfs(i);  }
			else if(visited[i] && *(g->adj+u*g->v+i) && parent[u]!=i){printf("Graph has cycle\n");exit(0);}


	}
		}
void dfs_main(){

	int i;
	//this function is needed for more than one connected components
	for(i=0;i<g->v;i++){
	  if(!visited[i])
		dfs(i);
				  }

     printf("Graph has no cycle");
}







int main(){
		int i,j;
	 initialize_graph(3,2);
	add_edge(0,1);
	 add_edge(1,2);
	 //add_edge(2,0);
	 //add_edge(0,3);
	 //add_edge(3,4);

	  


   dfs_main();


	 return 0;
}