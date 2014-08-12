//Program to find the length of longest non-repeated substring in given string
#include<stdio.h>
#include<string.h>
  int track[20];
	int max(int a,int b){return a>b?a:b;}

int get_longest_non_repeated_substring(char *str){

	 int i,cur_max=0,start=0;
	 int maxt=1;

	 if(strlen(str)==0) return 0;
	 //Reset all elements
		 for(i=0;i<strlen(str);i++)
			  track[str[i]]=-1;

	  for(i=0;i<strlen(str);i++){

			 if(track[str[i]]==-1){
					track[str[i]]=i;
					cur_max++;  }

		  else if(track[str[i]]<start){track[str[i]]=i;cur_max++;}
		  else {
				maxt=max(maxt,cur_max);
				start=track[str[i]]+1;
				cur_max=i-track[str[i]];
				track[str[i]]=i;

				 }


	  }



		return maxt;


}



void main(){
  char str[]="geeeffgtt";
	printf("Longest Non-Repeated substring is %d",get_longest_non_repeated_substring(str));


}