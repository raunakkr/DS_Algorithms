#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int findsum(int a[],int n){
  int i,sum=0;
  for(i=1;i<n;i++)
    sum+=abs(a[i]-a[i-1]);
    //printf(">>%d",sum);

  return sum;
}

int max(int a,int b){return a>b?a:b;}
int can[1000];
int max_cost(int a[],int n,int i,int pos){
   int x,y;
    if(pos>n-1)return findsum(can,pos);
    if( i>n-1)return INT_MIN;
 can[pos]=1;
 x=max_cost(a,n,i+1,pos+1);
 can[pos]=a[i];
 y=max_cost(a,n,i+1,pos+1);

return max(x,y);
}









int main(){
int i,t,*a[20],n[20],*temp,j;
scanf("%d",&t);
for(i=0;i<t;i++){
    scanf("%d",&n[i]);
    temp=(int*)malloc(sizeof(int)*100000);
for(j=0;j<n[i];j++)
    scanf("%d",temp+j);
    a[i]=temp;
}
for(i=0;i<t;i++)
    printf("%d \n",max_cost(a[i],n[i],0,0));


return 0;
}
