#include<stdio.h>
#include<stdlib.h>


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






void main(){
printf("%d",count_prime(30));

}