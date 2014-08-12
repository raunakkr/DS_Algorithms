// :: Remove edges from tree to get minimum difference
#include<stdio.h>
#include<limits.h>


 int min(int a,int b){return a<b?a:b;}

 int visited[1001]={0};

 int adj[1001][1001]={{0}};

int max,mint;

void create_graph(int p[],int q[],int n){
        int i;

		for(i=0;i<n-1;i++){
		  adj[p[i]-1][q[i]-1]=1;
         // printf("oooo%d-%d\n",p[i],q[i]);
		  adj[q[i]-1][p[i]-1]=1;
         
		}
          

	  }

  int dfs(int a[],int p,int n,int ind){
      int j,sum=0;
        if(visited[p])return 0;
     	visited[p]=1;
	    // printf(">>>>>>>>>%d \n",p);
		
			 for(j=0;j<ind;j++){
				  if(adj[p][j] && !visited[j])
				 sum+=dfs(a,j,n,ind);
			 }
                   sum+=a[p];
                      mint=min(mint,abs((max-sum)-sum));
                      //printf(">>%d--%d\n",p,mint);
                        return sum;
				  
								 


  }


int main(){

  int i,n,ind,a[100000],p[1001],r[1001];
  mint=INT_MAX;
  scanf("%d", &n);

  for(i=0;i<n;i++){
	  scanf("%d",&a[i]);
		max+=a[i];}
	  for(i=0;i<n-1;i++){
		 scanf("%d",&p[i]);
		 scanf("%d",&r[i]); }


		 create_graph(p,r,n);
         if(n-1>1001) ind=1001; else ind=n;
         for(i=0;i<ind;i++)
		dfs(a,i,n,ind);
        
      
		printf("%d",mint);


return 0;
}
