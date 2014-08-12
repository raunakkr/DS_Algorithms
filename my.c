#include<stdio.h>

int a[8]={8,3,14,1,6,19,5,22};

void my(){
int i=0,smallest=0,temp=0,largest=0;
for(i=0;i<8;i++)
  {
	 if(i==0)
	 smallest=largest=i;
	 else if(i==1){
		 if(a[i]>a[smallest])
		 largest=i;
		 else smallest=i;}

	  if(!i<2)
		{
		  if(a[i]>a[largest])
		  largest=i;
		  if(a[i]<a[smallest])
		  smallest=i;

		 if(a[i]>a[smallest] && a[i]<a[largest]){
		 //code for swap starts here
			temp=a[i];
			a[i]=a[i-1];
			a[i-1]=temp;
		}           }
  }
  for(i=0;i<8;i++)
 printf("%d\t",a[i]);
}



 void printarray(){
 int i=0;
 for(i=0;i<8;i++)
 printf("%d\t",a[i]);}

void main(){

	 my();

}