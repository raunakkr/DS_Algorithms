#include<string.h>
#include<string.h>
#include<stdlib.h>


int toINT(char a){return (int)a-'0';}


void print_decoded_string(char *p,int x){

	 int i,j,*s,prev,len=strlen(p);
    prev=0;

	s=(int*)malloc(sizeof(int)*len);


	 s[0]=x;s[1]=toINT(p[1])-s[0]; if(s[1]!=0 && s[1]!=1){printf("%d-NONE",s[1]);return;}
	 prev=s[0]+s[1];
		 i=2;
	 while(i<=len-1){
	  prev=s[i-1]+s[i-2];
	 s[i]=toINT(p[i])-prev;
	 if(s[i]!=0 && s[i]!=1){printf("NONE");return;}

	// printf(">>%d\n",prev);
	 i++;

	 }


	for(i=0;i<len;i++)
	  printf("%d",s[i]);

         printf("\n");
}











int main(){
	char str[]="012222";
	print_decoded_string(str,0);
   print_decoded_string(str,1);

return 0;
}