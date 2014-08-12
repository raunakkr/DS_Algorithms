//Program for pattern searching in given string (Naive,KMP,BOYCE-MOORE,RABIN-KARP,Finite Automata)
#include<stdio.h>
#include<string.h>
char txt[]="sriramanram";
char pat[]="ram";

void naivesearch(int m,int n){
	int i,j,k;

	for(i=0;i<=n-m;i++)
	{

		for(j=0;j<m;j++){
		 if(txt[i+j]!=pat[j])
		 break; }

		 if(j==m)
       printf("Pattern found at %d\n",i+1);


	}

}

void main(){
int m,n;
m=strlen(pat);
n=strlen(txt);
naivesearch(m,n);}