#include<stdio.h>
#include<stdlib.h>





int set_luck(int a[],int b[],int n,int c){

	  int *h,i;

	  h=(int*)malloc(sizeof(int)*n);
	  for(i=0;i<n;i++)
		 h[i]=9999;
		 h[0]=0;

	  for(i=0;i<n;i++) {
		if(h[a[i]]<h[b[i]])
			h[b[i]]=h[a[i]]+1;
			else if(h[a[i]]>h[b[i]])
			h[a[i]]=h[b[i]]+1; }


		for(i=1;i<c;i++)
			if(h[i]==9999)
			printf("-1\n");
			else
			printf("%d\n",h[i]);

}


int main(){

  int i,n,c;

  int a[1000],b[1000];
  scanf("%d",&n);
  scanf("%d",&c);

  for(i=0;i<c;i++)
  scanf("%d",&a[i],&b[i]);

	 set_luck(a,b,c,n);









}