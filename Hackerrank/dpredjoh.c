#include<stdio.h>
#include<stdlib.h>




int no_of_tiles(int n){

	int i,p[40];
	if(n==1)return 1;
	if(n==4)return 2;
	if(n<0)return 0;



	 p[1]=1;p[2]=1;p[3]=1;p[4]=2;

	 for(i=5;i<=n;i++)
		p[i]=p[i-1]+p[i-4];

		return p[n];

	//return no_of_tiles(n-1)+no_of_tiles(n-4);


}

//Count prime(Sieve of erath...)
int count_prime(int n){
  int rep=2,i,*p;
  if(n==2)
	 return 1;

	 if(n<2)
	  return 0;
  p=calloc(n+1,sizeof(int));
	  while(rep<=n){

	  for(i=2*rep;i<=n;i+=rep)
	  //mark element as 1
		  *(p+i)=1;


			i=rep+1;
	 while(*(p+i)==1){i++;}
				 rep=i;


	}

	rep=0;
 //Now count elements whose value is still 0 (starting from 2)
				for(i=2;i<=n;i++){
					  if(*(p+i)==0)
					  rep++;}

				return rep;
}



int main(){
  int i,t,a[20];

  scanf("%d",&t);

  for(i=0;i<t;i++)
	  scanf("%d",&a[i]);

	  for(i=0;i<t;i++)
		 printf("%d\n",count_prime(no_of_tiles(a[i])));

return 0;
}



