//Program to print roman equivalent of any no.

#include<stdio.h>
int numdigit(int,int);
int t[5];
void calroman(int,char*);
void main(){
int num;
int count=0;
char a[]={'I','X','C','M','L','D','V'};

printf("Enter any no.");
scanf("%d",&num);

	count=numdigit(num,count);
  calroman(count,a);

	}


int numdigit(no,count){
int n=no,i=0;
 while(n>0){
  //printf("%d",n%10);
  t[i]=n%10;
  printf("%d",t[i]);
  count++;
  n=n/10;
  i++;

 }
  return count;
}


void calroman(int count,char *a){
  int j;
	 if(count==3){
	 count--;
	  for(j=1;j<=t[count];j++)
		printf("%c",a[count]);
		 count--;
	  //	printf("\n");
	  for(j=1;j<=t[count];j++)
	  printf("%c",a[count]);
	  count--;
	  //printf("\n");
	  for(j=1;j<=t[count];j++)
	  printf("%c",a[count]);



	 }



}





