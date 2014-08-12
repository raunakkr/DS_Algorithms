//Print all denominations to make a change for given number

#include<stdio.h>
//Array to store output
char ot[20];
//Available coins (infinite supply)
int a[]={1,2};
 int n=2,count;
 int sum=3;

void print_array(int pos){
 int i;

 for(i=0;i<pos;i++){
	if(ot[i]==0)
	continue;
	printf("%d",ot[i]); }

	printf("\n");


}

void make_change(int i,int j,int pos,int sum){

  if(sum==0){
	 count++;
	print_array(pos);
	return;
  }

  if(i>j || i>n-1)
  return;

  if(sum<0)
  return;





	ot[pos]=a[i];

make_change(i,j,pos+1,sum-a[i]);
make_change(i+1,j,pos,sum);

//make_change(i+1,j,pos+1,sum);





}







void main(){

make_change(0,n-1,0,sum);
 printf("m%d",count);
}