#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){return a>b?a:b;}

int max_cost_DP(int a[],int n){

  //This can be solved with no space by taking two variables and updating the same
  //finally returning maximum of two
  int i,p[100000][2];

  for(i=0;i<n;i++){


    p[i+1][0]=max(p[i][0],p[i][1]+abs(a[i]-1));
            p[i+1][1]=max(p[i][1]+abs(a[i]-a[i+1]),p[i][0]+abs(a[i+1]-1));


  }
return max(p[n-1][0],p[n-1][1]);

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
    printf("%d \n",max_cost_DP(a[i],n[i]));

return 0;
}
