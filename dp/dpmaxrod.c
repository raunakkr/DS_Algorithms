//Maximum product rod cuttiong :: Recursive and dynamic programming
#include<stdio.h>

int n=5;
 //Returns maximum of two nos.
int max(int a,int b){

  return a>b?a:b;

}


//Recursive implementation
int max_rod_cut(int n){
 int maxt=0,i;


  if(n==2 || n==1)
	 return 1;


  for(i=1;i<=n-1;i++)


  maxt= max(maxt,max(i*(n-i),i*max_rod_cut(n-i)));



  return maxt;



}


//Dynamic programming implementation

	int max_rod_cut_DP(int n){
	 int p[10],i,j;
	  int maxt=0;
	 p[0]=0;p[1]=1;p[2]=1;

	 for(i=3;i<=n;i++){
          maxt=0;
		 for(j=1;j<i;j++)
		 maxt=max(maxt,max(j*(i-j),j*p[i-j]));
		 p[i]=maxt;
		 }


		 return p[n];




	}




void main(){

printf("Maximum product cut (Recursive solution) %d\n",max_rod_cut(n));
printf("Maximum product cut (Dynamic programming) %d",max_rod_cut_DP(n));


}