//Manssa stones:: Possible ways to get last stone with different nos.
#include<stdio.h>

 int a[1000];int pos=0;
int search(int data,int pos){int i;for(i=0;i<=pos;i++) if(a[i]==data)return 1;  return 0;}
void push(int sum,int pos){a[pos]=sum; return;}


void stone(int n,int a,int b,int sum){

    int i;
	 if(n==0){if(!search(sum,pos)){pos++;push(sum,pos);printf("%d ",sum); return;} return;}


	  sum+=a;
	  stone(n-1,a,b,sum);
	  sum=sum-a;
	  sum+=b;
	  stone(n-1,a,b,sum);

}







int main(){
	int i,t;
	int n[10],a[10],b[10];
	scanf("%d",&t);
	for(i=0;i<t;i++){
	  scanf("%d",&n[i]);
	  scanf("%d",&a[i]);
	  scanf("%d",&b[i]);
	  }

	for(i=0;i<t;i++){
		stone(n[i]-1,a[i],b[i],0);
      printf("\n");

	}



return 0;
}