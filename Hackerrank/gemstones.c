#include<stdio.h>
#include<stdlib.h>


void gem_element(char *a[],int n){
  int t,j,i=0,flag=0;
  int count=0;
  int p[100][26];

  for(i=0;i<n;i++)
      for(j=0;j<26;j++)
      p[i][j]=0;

  for(i=0;i<n;i++){

    while(*a[i]){
       t=(int)(*a[i])-(int)'a';
        p[i][t]++;
        a[i]++;
        }
    }

    for(j=0;j<26;j++){
    for(i=0;i<n;i++){
        if(p[i][j]==0){flag=1;break;}}
     if(!flag)count++;
     flag=0;}

 printf("%d\n",count);

}










int main(){
int i,n;
char *a[100],*temp;

scanf("%d",&n);
for(i=0;i<n;i++){
    temp=(char*)malloc(sizeof(char)*100);
   scanf("%s",temp);
   a[i]=temp;
}
gem_element(a,n);

return 0;
}
