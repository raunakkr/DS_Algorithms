//Program to match string based on regular expression containing '?' & '*'
#include<stdio.h>
#include<string.h>


int match_string(char *pat,char *str){

	if(pat && !str) return 0;

	while(*pat && *str){
		while(*pat!='?' && *pat!='*'){
			 if(*pat !=*str){

				 printf("q");return 0;}
			  else{
				  pat++;str++; }
				  if(!*pat && !*str)
				  return 1;
				  }
		while(*pat=='?' && *str)
					pat++;str++;
				  //	printf("o");

	 while(*pat=='*'){

			if(*(pat-1)=='?' & *str){str++;pat++;while(*str!=*pat)str++;}

			else if(*(pat-1)!='?'){while(*str==*(pat-1)) str++; pat++;}
			else {printf("hhh");return 0;}

	 }


	}

 if(*pat=='\0'&&*str=='\0') return 1;else {printf("%c-%c End\n",*pat,*str);return 0;}
}












int main(){
 char str[]="aaaam";
 char pat[]="a*am";

 match_string(pat,str)?printf("Matched"):printf("No match");

return 0;
}