#include<stdio.h>

 struct r{int start,end;};

  int max(int a,int b){return a>b?a:b;}




int merge_sorted_intervals(struct r range[],int n){

	  int i,maxt=0,next,prev;
	  prev=range[0].start;next=range[0].end;


	  for(i=1;i<n;i++) {
  if(range[i].start>next){
			printf("%d-%d\n",prev,next);
			prev=range[i].start;next=range[i].end;

			continue;
			}
			else{
         next=max(range[i-1].end,range[i].start); 
		  printf("%d-%d\n",prev,next);
			prev=range[i-1].start;  }


		  }




}





int main(){

 struct r range[]={{1,6},{2,4},{5,7},{8,9},{10,14}};

 int n=sizeof(range)/sizeof(range[0]);

  merge_sorted_intervals(range,n);


return 0;
}