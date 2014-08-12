#include<stdio.h>
#include<stdlib.h>


long int binary_search(long int a[],long int left,long int right,long int data){

 long  int mid;
  if(left>right)
	  return -1;
  mid=left+(right-left)/2;
  if(a[mid]==data)return mid;
  if(data<a[mid]) return binary_search(a,left,mid-1,data);
  else return binary_search(a,mid+1,right,data);

}


  void print_num(long int x,long int y){
	  long int i;

	  printf("%ld=%ld",x,y);return;
  for(i=0;i<x;i++)
			 printf("5");

		 for(i=0;i<y;i++)
			  printf("3");

			  printf("\n");
  }


void decent_number(long int n){

  long	int i,j,x,y;

  long	int *t,*f;
	t=(long int*)malloc(sizeof(long int)*(n/5));
	f=(long int*)malloc(sizeof(long int)*(n/3));
	  j=0;x=0;y=0;

	 if(n<3){ printf("-1\n");return;  }

	for(i=3;i<=n;i+=3) {
		 // printf(">>>%ld",j);
		  f[j]=i; j++;}
		  j=0;
		  for(i=5;i<=n;i+=5)
		t[j++]=i;



	if(binary_search(f,0,n/3-1,n)!=-1){x=n;y=0; print_num(x,y);return;}


	 for(i=n/3-1;i>=0;i--){

		  if(binary_search(t,0,n/5-1,n-f[i])!=-1) {
			 x=f[i]; y=n-f[i];  print_num(x,y);return;   }  }

	  if(binary_search(t,0,n/5-1,n)!=-1){x=0;y=n;print_num(x,y);return;}


        printf("-1\n");return; 

}






int main(){
 long int i,t;
 long int a[20];
  scanf("%ld",&t);
  for(i=0;i<t;i++)
	 scanf("%ld",&a[i]);

	 for(i=0;i<t;i++)
		decent_number(a[i]);

return 0;
}