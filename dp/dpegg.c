//Egg dropping puzzle :: Recursive and Dynamic programming implementation


#include<stdio.h>
#include<limits.h>

int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

//Minimum trials needed to find uppermost safe floor

int min_trial(int e,int f){
  int i,maxt=INT_MAX;
  if(e==0)
	 return 0;
	 if(f==1 && e>0)
		 return 1;
  if(e==1)
	  return f;


	  for(i=1;i<=f;i++){
		 maxt=min(maxt,max(min_trial(e-1,i-1),min_trial(e,f-i)));
}
  //This is because we haven't added 1 to min
  return maxt+1;



}


int min_trial2(int e,int f){
  int i,maxt=INT_MAX;
  if(e==0)
	 return 0;
	 if(f==1 && e>0)
		 return 1;
  if(e==1)
	  return f;


	  for(i=1;i<=f;i++){
		 maxt=min(maxt,max(1+min_trial2(e-1,i-1),1+min_trial2(e,f-i)));
}
  //This is because we haven't added 1 to min
  return maxt;



}







void main(){

printf("Minimum no. of trials needed %d\n",min_trial(2,4));
printf("Minimum no. of trials needed %d\n",min_trial(2,4));
}