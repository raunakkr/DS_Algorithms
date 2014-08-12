#include<stdio.h>
int fmax=0;
int max(int a,int b){
return (a>b)?a:b;
}


int mp(int n){
int i,cmax=0;
 if(n==0||n==1)
 return 0;


 for(i=1;i<n;i++) {

  //cmax=max(max(i*(n-i),cmax),i*mp(n-i));
  cmax=max(max(i*(n-i),cmax),i*mp(n-i));
  }
     if(fmax<cmax)
  fmax=cmax;
	return cmax;
}


void main(){


 printf("%d\n",mp(5));
  printf("%d\n",fmax);


}