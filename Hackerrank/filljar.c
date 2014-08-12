#include<stdio.h>





int main(){
 long int m,n;
 long int i,p,q,r;
 long int count=0;
scanf("%ld",&n);
scanf("%ld",&m);

  for(i=0;i<m;i++) {
	  scanf("%ld",&p);
	  scanf("%ld",&q);
	  scanf("%ld",&r);
	  count+=(abs(q-p)+1)*r;
	  }

	  printf("%ld",count/n);

return 0;
}