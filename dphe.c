#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


double minp(double a,double b){return a<b?a:b;}




double min_cost(int a[],int n,int p,int q){
	 int i;
	 double mint;



	 if(p>n-1 || q>n-1)return 9999.0000;
	 if(p>q)return 9999.0000;
    if(q-p==1)return sqrt(a[q]-a[p]+1);
	 if(p==q)return sqrt(1.0000);

	 mint=9999.0000;



	 for(i=p;i<n-1;i++)
			mint=minp(mint,minp(sqrt((double)a[q]-a[p]+1),min_cost(a,n,p,i)+min_cost(a,n,i+1,q)));
			return mint;



}

double min_cost_util(char *a,int n){
	int i,j;
    int *b=(int*)malloc(sizeof(int)*n);
    j=0;

	for(i=0;i<n;i++) {
		if(*(a+i)=='0'){

	  //	printf("%d",i);
		*(b+j)=i+1;
		  j++;}

		}


		// return 2.0000;
	return min_cost(b,j,0,j-1);

}



int main(){

  int n;
 // char a[]="0101110";

 int a[]={1,3,7};
  n=strlen(a);
  printf("%.04f",min_cost(a,3,0,2));


return 0;
}