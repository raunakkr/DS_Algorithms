#include<stdio.h>
int a[6]={20,30,2,2,2,10};
int max(int a,int b){
return a>b?a:b;}


int win (int i,int j){

if(j-i==1)
return a[j];



return max(max(a[i]+win(i+2,j),a[i]+win(i+1,j-1)),max(a[j]+win(i+1,j-1),a[j]+win(i,j-2)));
}






void main(){
printf("%d",win(0,5));}