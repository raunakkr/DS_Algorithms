#include<stdio.h>
int fmax=0;
int t[20];


int max(int a,int b){
return (a>b)?a:b;
}


int mp(int n){
int i,j;

 t[0]=0;
t[1]=0;



 for(i=2;i<=n;i++) {
	 for(j=1;j<i;j++)
  t[i]=max(max(j*(i-j),t[i]),j*t[i-j]);

 // printf("%d\n",t[i]);
  }

  return t[n];

}


void main(){

  printf("%d",mp(11));
// printf("%d\n",mp(3));
  //printf("%d\n",fmax);


}