#include<stdio.h>
#include<stdlib.h>
#define max maxt
#define min mint



 long int max(long int a,long int b){return a>b?a:b;}
 long int min(long int a, long int b){return a<b?a:b;}
/* int max_game_score( int a[],int i){

	 int p,q,r;
		if(i==n-3)
		return a[i]+a[i+1]+a[i+2];
		if(i==n-2)
		return a[i]+a[i+1];
		if(i==n-1)
		return a[i];
		if(i>n-1)
	  return 0;


  p=	a[i]+  min(min(max_game_score(a,i+2),max_game_score(a,i+3)),max_game_score(a,i+4));

  q=	a[i]+a[i+1]+ min( min(max_game_score(a,i+3),max_game_score(a,i+4)),max_game_score(a,i+5));
  r=	a[i]+a[i+1]+a[i+2]+min(min(max_game_score(a,i+4),max_game_score(a,i+5)),max_game_score(a,i+6));


  return max(max(p,q),r);

  }    */

// ::Dynamic Programming implementation

 long int max_game_score_DP(long int a[],long int n){

	long int i,r,s,t, p[100];

	 for(i=0;i<100;i++)
		 p[i]=0;

	 p[n-1]=a[n-1];
	 p[n-2]=p[n-1]+a[n-2];
	 p[n-3]=p[n-2]+a[n-3];

	 for(i=n-4;i>=0;i--) {
		 r= a[i]+min(min(p[i+2],p[i+3]),p[i+4]);
		 s= a[i]+a[i+1]+min(min(p[i+3],p[i+4]),p[i+5]);
		 t= a[i]+a[i+1]+a[i+2]+min(min(p[i+4],p[i+5]),p[i+6]);
		 p[i]=max(max(r,s),t);

	 }

	  return p[0];

  }




int main(){
	// int a[]={0,1,1,1,999,7,8,12,566};
  long	int t;
  long	 int i,j,n[5];
  long	int *a[5];

	scanf("%ld",&t);


	for(i=0;i<t;i++) {
	  scanf("%ld",&n[i]);
	  a[i]=(long int *)malloc(sizeof(long int)*n[i]);
	  for(j=0;j<n[i];j++){
		 scanf("%ld",a[i]+j);
		 //printf("%d-",*temp+j);

		 }
		 }

	 for(i=0;i<t;i++)
		 printf("%ld\n",max_game_score_DP(a[i],n[i]));
	  //	n=sizeof(a)/sizeof(a[0]);
		// printf("%d\n",max_game_score_DP(a,9));
		// printf("%d\n",max_game_score(a,0));

return 0;
}