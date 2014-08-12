//Maximum length chain of pairs :;Recursive & Dynamic Programming
#include<stdio.h>

struct chain{
  int a,b;
};

 int max(int a,int b){return a>b?a:b;}
struct chain c[]={ {5, 24}, {10, 25},{12, 40}, {14, 60} };
 int n;

int longest_chain(int p){

int i,j,maxt=0;
if(p==0)
return 0;

if(p<0)
	return 0;

for(i=p-1;i>=0;i--){
	if(c[i].b<c[p].a)
  maxt= max(maxt,1+longest_chain(i)); }



  return maxt;

}


int longest_chain_main(){
	 int i,maxt=0;
	 if(n==0)
	 return 0;
  for(i=n-1;i>=0;i--){
 maxt=max(maxt,1+longest_chain(i));}

	return maxt;

 }




void main(){

n=sizeof(c)/sizeof(c[0]);
printf("Longest chain of pair is %d",longest_chain_main());

}