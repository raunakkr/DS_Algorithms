//Program to print duplicates in Lexicographic order
#include<stdio.h>




int convert_to_int(char c){

return (int)c-(int)'a';
}

char convert_to_char(int c){
 // return (char)(c+97);
  return (char)((int)'a'+c);  //You may use any one of return statements
}


void find_duplicates_sorted(char *a){
  int h[26],i;
  int len=strlen(a);
	if(len==0)printf("empty string");

	for(i=0;i<26;i++)
		h[i]=0;

	//Now traverse string
	for(i=0;i<len;i++)
		h[convert_to_int(*(a+i))]++;

	//Get duplicates now
		for(i=0;i<26;i++)
		  if(h[i]>1)
        printf("%c\n",convert_to_char(i));

		}






void main(){

	 char a[]="bccedfeb";
	 find_duplicates_sorted(a);


}