#include<stdio.h>
void markMultiples(int arr[], int a, int n)
{
	 int i = 2, num;
	 while ( (num = i*a) <= n )
	 {
		  arr[ num-1 ] = 1;
		  ++i;
	 }
}

// A function to print all prime numbers smaller than n
int SieveOfEratosthenes(int n)
{
	  int i,c=0;
	 if (n >= 2)
	 {

		  int arr[40];
		  for(i=0;i<40;i++)arr[i]=0;

		  for (i=1; i<n; ++i)
		  {
				if ( arr[i] == 0 )
				{

					c++;
					 markMultiples(arr, i+1, n);
				}
		  }
	 }
	 return c;
}





void main(){

  printf("%d",SieveOfEratosthenes(5));
}