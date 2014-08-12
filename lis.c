#include<stdio.h>
int a[6]={0,1,4,2,113},maxt,p;
 int max(int a,int b){return(a>b?a:b);}
int lis(int i,int j){
  if(j<i)
  return 0;
  if(i==j)
  return 1;
	if(a[i+1]>a[i])
return maxt=max(maxt,1+lis(i+1,4));
else{
lis(i+1,j);
return 1;
}

}

void main(){

       lis(0,4);
	 printf("%d",maxt);
}