//Print how many ways can a string be decoded
#include<stdio.h>

  int a[]={1,2,1};
  char d[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  //output array
  char ot[10];
	int n,count;


 void find_decode_ways(int i,int j,int pos){

		  int x;
	  if(i>n-1){
	  for(x=0;x<pos;x++)
	  printf("%c",ot[x]);
	  printf("\n");
	  count++;
	  return;

	  }



	  ot[pos]=d[a[i]-1];
	  find_decode_ways(i+1,j,pos+1);

	  if(i+1<=n-1 && a[i]==1){
	  ot[pos]=d[10*a[i]+a[i+1]-1];
	  find_decode_ways(i+2,j,pos+1);  }

	  if(i+1<=n-1 && a[i]==2 && a[i+1]<7){
	  ot[pos]=d[10*a[i]+a[i+1]-1];
		find_decode_ways(i+2,j,pos+1);
		}


 }









void main(){

n=sizeof(a)/sizeof(a[0]);
find_decode_ways(0,n-1,0);
printf("No of decoding ways-  %d",count);

}