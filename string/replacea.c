//Replace adjacent characters of given string with third one repeatedly till we find smallest string
#include<stdio.h>




void replace_str(char *str){

int i=0;int k,j=1;int flag=0;
	if(!str) return 0;
		  k=0;
	while(*(str+k)){
  printf("mm%d\n",k);
			i=k;
		flag=0;
		if(*(str+i)=='a' && *(str+i+1)=='b'){
		*(str+i)='c';
		i++;j=i+1;
		while(*(str+j)){
		*(str+i)=*(str+j);
	  //	printf("%c\n",*(str+i));
		i++;j++;}
		*(str+i)='\0'; flag=1;
		}

		else if(*(str+i)=='b' && *(str+i+1)=='c'){
		*(str+i)='a';
		i++;j=i+1;
		while(*(str+j)){
		*(str+i)=*(str+j);
	  //	printf("%c\n",*(str+i));
		i++;j++;}
		*(str+i)='\0'; flag=1;}

		else if(*(str+i)=='a' && *(str+i+1)=='c'){
		*(str+i)='b';
		i++;j=i+1;
		while(*(str+j)){
		*(str+i)=*(str+j);
	  //	printf("%c\n",*(str+i));
		i++;j++;}
		*(str+i)='\0'; flag=1;}



	  if(!flag)	k++; else k=0;
	}

  printf("%s",str);
}









int main(){

	char str[]="abccbcabc";

	 replace_str(str);
	return 0;

}