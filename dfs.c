#include<stdio.h>
int a[6][6] = {
 {0,1,0,0,0,0} ,
 {0,0,1,1,0,0} ,  
 {0,0,0,0,0,1} ,
 {0,0,0,0,0,1} ,
 {0,0,0,0,0,0} ,
 {0,0,0,0,0,0}
};
int n=6,countpath=0;
int visited[6]={0,0,0,0,0,0};
//Marking all vertices unvisited initially
 void unvisitallnodes(){
 int i;
for(i=0;i<n;i++)
	 visited[i]=0;
	 }

 void dfs(int current){
 int i;
	printf("%d ",current);
	visited[current]=1;
  for(i=0;i<n;i++)
  {
	  if(a[current][i] && !visited[i])
		 dfs(i);
		 }
		 }
 //start traversal
	 void dfstraversal(){
	 int i,count=0;
	 //We need this loop for more than one connected component
		for(i=0;i<n;i++){
		 if(!visited[i])
		 dfs(i);
 //This count keeps track of no. of connected components
		 count++;}

	 }

//>>>>>>>>>>Check whether there is a simple path between source and destination

	 int hassimplepath(int source,int destination){
 int i;
 if(source==destination)
  return 1;

  visited[source]=1;
  for(i=0;i<n;i++)
  {
	  if(a[source][i] && !visited[i])
//you can't write "return hassimplepath" because as soon it gets no path.it returns leaving remaining posible paths
	  if(hassimplepath(i,destination))
	  return 1;
		 }
		return 0;
	 }
 //>>>>>>>>count no. of simple path from source to destination
 void noofsimplepath(int source,int destination){
 int i;
 if(source==destination){
 countpath++;
unvisitallnodes();
 }
  for(i=0;i<n;i++)
  {
	  if(a[source][i] && !visited[i]) {
			noofsimplepath(i,destination);  }
		 }

 }
void main(){
//unvisitallnodes();
//dfstraversal();
//unvisitallnodes();
  //hassimplepath(1,5);
//hassimplepath(0,3)?printf("\nSimple path found"):printf("\nno simple path found");
//unvisitallnodes();
noofsimplepath(0,3);
printf("No. of simple path -%d",countpath);
}