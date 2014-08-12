#include<stdio.h>
#include<stdlib.h>



void min_candies(int a[],int n){
  int i,j=0,prev,sum=0;
prev=1;

int *can=(int*)malloc(sizeof(int)*n);

can[j++]=1;
  for(i=1;i<n;i++){
      if(a[i]>a[i-1]){
        prev++;
        can[j++]=prev;
      }

     else if(a[i]<a[i-1]){
        if(prev-1==0){
        can[j-1]=2;
        can[j++]=1;
        prev=1;}
        else {prev=1;can[j++]=prev;}
      }

     else if(a[i]==a[i-1]){
            can[j++]=1;
            prev=1;}



    }

//This is backward traversal to ascertain fulfilled requirements

for(i=0;i<n;i++){
   // printf(">>%d",can[i]);
    sum+=can[i];}
   // printf("\n");
    sum=0;

for(i=n-1;i>=1;i--)
    if(a[i-1]>a[i] && !(can[i-1]>can[i]))
       can[i-1]++;
    // if(a[i-1]<a[i] && !(can[i-1]<can[i])
      // can[i-1]++;

for(i=0;i<n;i++)
    sum+=can[i];
printf("%d ",sum);

  }

int main(){
  int i,t,n[100000];
  scanf("%d ",&t);
  for(i=0;i<t;i++)
    scanf("%d",&n[i]);

    min_candies(n,t);

return 0;
}
