//Total cholcolates little bob can eat
#include<stdio.h>



int no_chocolates(int n,int c,int m){
	int q,total,w;

	total=n/c;
	w=total;


	while(w>=m){
	 q=w/m;
	 total+=q;


	 w=(w%m)+q;


	}

	 return total;


}





int main(){

  printf("%d",no_chocolates(12,4,4));
return 0;
}