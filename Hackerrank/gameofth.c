//Program to check whether anagram of given string is palindrome or not
#include<stdio.h>
#include<string.h>



int is_convertible_to_palindrome(char *str){

	char *s=str;
	 int c,h[26];
	  int i;
	  int len=strlen(str);
		if(len==0 || len==1)return 1;


	 for(i=0;i<26;i++) h[i]=0;
	 while(*str){
		 c=(int)(*str)-(int)'a';
		h[c]++;
      str++;

	 }
	  c=0;
	for(i=0;i<26;i++) {
			if(h[i]%2!=0)
				c++;  }

	  if(c>1)return 0;
	  else return 1;

}










int main(){

 char str[]="cdcdcdcdeeeef";
 printf("%d",is_convertible_to_palindrome(str));

return 0;
}
