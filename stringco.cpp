//Print combination of characters ncr
#include<stdio.h>
#include<string.h>
void com(int,char*,int,char*);
void main(){
char p[9];
char *c=p;
char *o="abc";
com(1,c,0,o);

 }
 void com(int depth,char *combination,int start,char *original)
 {
 int length=strlen(original);

 for(int i=start;i<length;i++){
 combination[depth]=original[i];
 combination[depth+1]='\0';
 printf("%s\n",combination);
 if(i<length-1)
 printf(">>>>>>>>>>\n");
 com(depth+1,combination,start+1,original);
 }

 }

 


