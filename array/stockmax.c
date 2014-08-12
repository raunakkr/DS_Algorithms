//Stock buy-sell for maximum profit
#include<stdio.h>
		 int price[]={100, 180, 260, 310, 40, 535, 695};

void max_profit(int a[],int n){

	int i,prev,flag,profit=0;
		i=0;flag=0;
		prev=a[0];
	while(i<n){


		//sell
	  while(flag && a[i]>=prev){

			 prev=a[i];
			 i++;

	  }
		  if(flag && i<=n){	 flag=0; printf("Sell on day %d\n",i-1); prev=a[i];}
		 //Buy
		  while(!flag && a[i]<=prev){

			 prev=a[i];
			 i++;

	  }

	 if(!flag && i<=n){ flag=1;printf("Buy on day %d\n",i-1);prev=a[i];}
	}



}







int main(){

  int price[]={66 ,388 ,195 ,158 ,495 ,310 ,224 ,314 ,321 ,76 ,176 ,192 ,248 ,447 ,168 ,437 ,401 ,192 ,237 ,132};
	 int n = sizeof(price)/sizeof(price[0]);

    max_profit(price,n);


return 0;
}