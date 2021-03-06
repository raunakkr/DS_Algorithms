//Program to replace all occurings of pattern with 'X', Note that successive occurings should be replaced with only one 'X'
#include<stdio.h>
#include<string.h>


int search_pattern(int p,int q,char *pat,char *txt){
	int i,j;
	int m=strlen(pat);
	int n=q-p+1;
	if(m==0)return -1;
              
	for(i=p;i<=p+n-m;i++){

		 for(j=0;j<m;j++){
			if(txt[i+j]==pat[j])
			 {  if(j==m-1)return i;

			 }
          else break;
						}
	}



	return -1;
}


//Replace occurence of pattern with 'X'
char  *replace_pattern_with_X(char *txt,char *pat){
		  int m=strlen(pat);
		  int n=strlen(txt);
		  int i=0;
		  int temp,j=0;

		if(!txt || !pat)return NULL;


		 while( i<=n-1){
			 j=search_pattern(i,n-1,pat,txt);
			 if(j!=-1){
				temp=j;
				//check for successive pattern here
				  while(search_pattern(j+m,n-1,pat,txt)==j+m)
							{j=j+m;}

							j=j+m;

				txt[temp++]='X';
				//shift characters
				while(j<=n-1){txt[temp++]=txt[j++];}
				txt[temp]='\0';

			 }
         else break;
		  }


	return txt;
}










void main(){

char txt[]="aabaaabaa";
char pat[]="aa";

printf("Original string-  %s\n",txt);
printf("Pattern-  %s\n",pat);


printf("Final Replaced String  %s",replace_pattern_with_X(txt,pat));



}