#include<stdio.h>
#include<stdlib.h>

int *h;
//compare function
  int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int bs(int a[],int left,int right,int data){


   if(left>right)return 0;
    int mid=left +((right-left)/2);

    if(a[mid]>=data && !h[mid]){h[mid]=1;return 1;}
    else if(a[mid]>=data)
    return bs(a,left,mid-1,data) || bs(a,mid+1,right,data);
    else if(a[mid]<data)return bs(a,mid+1,right,data);

    else return bs(a,left,mid-1,data) || bs(a,mid+1,right,data);
}

int is_combination_possible(int a[],int b[],int n,int k){
    h=(int*)calloc(1000,sizeof(int));

    qsort(a,n,sizeof(a[0]),compare);

    int i;
    for(i=0;i<n;i++){
      if(!bs(a,0,n-1,k-b[i]))
      return 0;
    }


      return 1;



}







int main(){
int i,j,t,n[10],k[10];
int *a[1000],*b[1000],*temp,*lemp;
scanf("%d",&t);
for(i=0;i<t;i++){
    scanf("%d%d",&n[i],&k[i]);
    temp=(int*)malloc(sizeof(int)*1000);
    lemp=(int*)malloc(sizeof(int)*1000);
    for(j=0;j<n[i];j++)
        scanf("%d",temp+j);
    for(j=0;j<n[i];j++)
    scanf("%d",lemp+j);
        a[i]=temp;b[i]=lemp;
}
  for(i=0;i<t;i++){
     if(is_combination_possible(a[i],b[i],n[i],k[i]) || is_combination_possible(b[i],a[i],n[i],k[i]))printf("YES\n");
     else printf("NO\n");}



return 0;
}
