//:: Anagram
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 int compare (const void * a, const void * b)
{
 return( strcmp((char *)a,(char *)b) );
}

int count_replacement(char *str){

     int *l,*r,i,c=0;
	 int len=strlen(str);
	 if(len%2!=0)return -1;

	 qsort(str,len/2,sizeof(char),compare);
	 qsort(str+len/2,len/2,sizeof(char),compare);

	  i=0;
	  l=(int*)calloc(26,sizeof(int));
	  r=(int*)calloc(26,sizeof(int));

	  for(i=0;i<len/2;i++)
		l[(int)(*(str+i))-(int)'a']++;

		for(i=len/2;i<len;i++){
		r[(int)(*(str+i))-(int)'a']++;
        //printf(">>%c ",*(str+i));
        }

		for(i=0;i<26;i++)
			if(l[i]!=r[i]){
           // printf("%c-%d-%d\n",(char)i+97,l[(char)i+97],r[(char)i+97]);
			 c+=abs(l[i]-r[i]);}


		  return c/2;

}





int main(){
 int t,i;
  char *temp,*s[100];

  scanf("%d",&t);


 for(i=0;i<t;i++) {
		temp=(char*)malloc(sizeof(char)*1000);
	  scanf("%s",temp);
	  s[i]=temp;}

	 for(i=0;i<t;i++) 
  printf("%d\n",count_replacement(s[i]));



return 0;
}
