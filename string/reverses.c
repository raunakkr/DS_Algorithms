//Program to reverse a string in place (Original string should be modified
#include<stdio.h>
#include<string.h>


	void reverse_string(char *str){

		int i,j;
	  char temp;
		if(!str) return ;

		i=0;j=strlen(str)-1;

	 while(i<j){
	  temp=str[i];
	  str[i]=str[j];
	  str[j]=temp;
     i++;j--;
}


	}

int main(){

  char str[]="ra";
  printf("Original String ::  %s\n",str);
  reverse_string(str);
  printf("Rversed String string ::  %s\n",str);
return 0;

}
