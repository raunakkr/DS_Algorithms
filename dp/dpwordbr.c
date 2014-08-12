//Word wrap problem (as used in ms word).....Recursive and dynamic programming aproach.
#include<stdio.h>

//An array representing word length
int a[]={1,3};
//Maximum characters a line may have
int max_width=4;
int n;


//Function to compute arrangement having minimum cost
int min_cost_word_wrap(int pos,int line){

		int w=max_width;
		 int cost=0;
	  if(pos>n-1)
		return;

	  //while we can accomodate as many words in a line
	  while(pos<=n-1 && a[pos]<=w){

	  //Free space in a line now reduced ( plus 1 for 'space')
	  if(pos!=n-1)	w=w-a[pos]-1;
			 else
          w=w-a[pos];
		//Recursive call here
			min_cost_word_wrap(pos+1,line+1);

		//move to next word
		pos++;

	  }
  //calculate cost here
	if(w>0){ cost=w-a[pos-1];

	printf("%d  ",cost);
}
  }




void main(){

  n=sizeof(a)/sizeof(a[0]);
  min_cost_word_wrap(0,1);

}