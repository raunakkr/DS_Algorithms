
#include<stdio.h>
#include<math.h>

void genbinary(int n){

  int i,k,mask;
for(i=15;i>=0;i--)
	{
		mask=1<<i;
		k=n&mask;

		k==0?printf("0"):printf("1");
}

}

 void genbinar(int n){

  int i,j,k;
for(i=15,j=0;i>=0;i--,j++)
	{
		k=n&((int)pow(2,j));

		k==0?printf("0"):printf("1");
}

}

void main(){
  //int	k=5 & 8;
	//printf("%d",k);
  genbinar(15);
}