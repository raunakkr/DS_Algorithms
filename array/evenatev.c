#include<stdio.h>




void display(int a[],int n){

int i;
for(i=0;i<n;i++)
  printf("%d ",a[i]);
}

void swap(int a[],int i,int j){
  int temp=a[i];
  a[i]=a[j];
  a[j]=temp;
}

int get_next(int a[],int n,int p,int i){

  if(i==0){	while(p<n && a[p]%2!=0)p++;
		return p;  }
  else if(i==1){ while(p<n && a[p]%2==0)p++;
		return p; }

}

void rearrange_array(int a[],int n){

	  int i=0,flag;

	  swap(a,0,get_next(a,n,0,0));

		flag=1;
       i++;
	while(i<n){

		 swap(a,i,get_next(a,n,i,flag));
		 flag=flag?0:1;

}

  display(a,n);
}






int main(){

	int a[]={1,3,2,6};
	int n=sizeof(a)/sizeof(a[0]);

   rearrange_array(a,n);



return 0;
}