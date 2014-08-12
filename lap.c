//Recursive program to find longest arithmetic progression(LAP)
#include<stdio.h>
	int Lmax=0;

	int a[]={2,8,12,14,20,22,26};
	int n=7;

	int maxt(int a,int b){return a>b?a:b;}

 int isap(int i,int j,int k){ if(i>n-1||j>n-1||k>n-1 || i==j || j==k || i==k) return 0; /*printf("((%d-%d-%d))\n",i,j,k);*/return a[j]==(a[i]+a[k])/2 ? 1 :0;}
 int lap(int i,int j){
	int k;
printf("%d-%d\n",i,j);


		 if(j==n-1)
		 return 0;

	if(i>n-1 || j>n-1)
	return 0;



	  for(k=j+1;k<=n-1;k++){
		if(isap(i,j,k)){
		return 1+lap(j,k);
			}


								}
				  return 0;

}




void main(){

 int x,y,z;


for(x=0;x<=n-3;x++){
	  for(y=x+1;y<=n-2;y++) {

	for(z=y+1;z<=n-1;z++){
	 if(isap(x,y,z)){
		Lmax=maxt(1+lap(y,z),Lmax);




	}}}}



	printf("%d",2+Lmax);

}
