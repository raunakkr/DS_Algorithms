//Program to check whether there exists a subarray whose sum is equal to a given K
#include<stdio.h>
int a[5]={4,13,0,6,9};
int n=5,i,temp,rqd=26;
int t[5][27]={0};



int checksum(int i,int sum){
int k;
  if(t[i][sum])
  return 1;

  for(k=i+1;k<=n-1;k++){
  t[i][sum]=t[i][sum] || t[k][sum-a[i]];
  if(t[i][sum])
  printf("%d %d - %d\n",i,k,sum);
  }
  return t[i][sum];




}



void main(){

int i,flag=0;
for(i=0;i<n;i++){
  temp=a[i];
  t[i][temp]=1; }
for(i=n-1;i>=0;i--){
  flag=flag||checksum(i,rqd);
  }
flag?printf("Yes"):printf("No");
}