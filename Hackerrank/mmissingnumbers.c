#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int min(int a,int b){return a<b?a:b;}

void print_diff(int b[],int n,int a[],int m){
  int i;
  int mint=INT_MAX;

for(i=0;i<n;i++){
    mint=min(mint,b[i]);}

 int *h=(int*)malloc(sizeof(int)*100);

 for(i=0;i<101;i++)h[i]=0;
 for(i=0;i<n;i++)
    if(b[i]-mint>=0)    h[b[i]-mint]++;
   // printf("%d ",h[b[i]-mint]);}

    for(i=0;i<n;i++){
    if(h[b[i]-mint]==0)
    h[b[i]-mint]=-1;}

 for(i=0;i<m;i++)
    if(a[i]-mint>=0)h[a[i]-mint]--;

    for(i=0;i<101;i++)
      if(h[i]>0)
        printf("%d ",i+mint);


}



int main(){
    int i,n,m;
    int a[1000],b[1000];
  scanf("%d",&m);
for(i=0;i<m;i++)
    scanf("%d",&a[i]);
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&b[i]);

    print_diff(b,n,a,m);

return 0;
}
