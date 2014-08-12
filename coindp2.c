#include<stdio.h>
int a[4]={1,2,5,10};
int t[5]={0,0,0,0,99};
int v=0,sum=15;
int n=4;
int mint(int a,int b){return a<b?a:b;}
int fcoinDP(int i){
	if(i>n-1 && sum>v)
	return 99;
	if(i>n-1 || i<0)
	return 0;
	if(a[i]>sum){
		t[i]=1;
		return;}
	v+=a[i];
  if(v<sum)
	  t[i]=t[i+1]+1;
	  else
     t[i]=n-i;

}


void main(){
int i,myv=0,min=999;
  for(i=0;i<n;i++)
	myv+=a[i];
	if(myv<sum)
	min=-1;
for(i=n-1;i>=0;i--)
	  fcoinDP(i);

	  for(i=0;i<n;i++){min=mint(t[i],min);}

     for(i=0;i<n;i++){printf("%d\n",t[i]);}

	printf("\n%d",min);

}
