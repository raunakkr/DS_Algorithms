#include<stdio.h>
#include<stdlib.h>


void is_equal_sum(int a[],int n){
    int i,sum=0,lsum,rsum;
    if(n==1){printf("YES\n");return;}
    for(i=0;i<n;i++)
        sum+=a[i];


    lsum=0;rsum=sum;

    if(lsum==rsum){printf("YES\n");return;}

    for(i=1;i<n;i++){
        lsum+=a[i-1];
        rsum=sum-(lsum+a[i]);
        if(lsum==rsum){printf("YES\n");return;}
    }

 printf("NO\n");return;



}






int main(){
    int i,j,t,n[10];
int *a[10],*temp;
scanf("%d",&t);
for(i=0;i<t;i++){
    scanf("%d",&n[i]);
    temp=(int*)malloc(sizeof(int)*100000);
    for(j=0;j<n[i];j++)
        scanf("%d",temp+j);
        a[i]=temp;
}

   for(i=0;i<t;i++)
    is_equal_sum(a[i],n[i]);

return 0;
}
