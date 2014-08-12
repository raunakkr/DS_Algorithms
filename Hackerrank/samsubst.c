#include<stdio.h>




void find_sum(char *a){
	int x,sum,finalsum;
   char *temp;
	sum=0;finalsum=0;
	while(*a){

	  temp=a;
			x=0;sum=0;
	  while(*temp){
		 x=x+(int)*temp -'0';
		 sum+=(x%1000000007);

		 x*=10; temp++;

	  }

	  finalsum+=(sum%1000000007);
		  a++;

	}

	 printf("%d",finalsum);



}







int main(){

  char a[20];	scanf("%s",a);


	 find_sum(a);


return 0;
}
