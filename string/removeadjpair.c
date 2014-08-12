#include<stdio.h>



void remove_adj_pair(char *str){

    if(!str)return;

    char *prev=str;
    char *p=str;
    int flag=0;
    while(*str && *prev){
        if(*str==*(str+1)){
            str+=2;
            flag=1;}

      else {  *prev=*str;

            prev++;str++;

      }
    }

     *prev='\0';
     if(flag)remove_adj_pair(p);
     else return;


}





int main(){
char a[]="abbcddcq";
remove_adj_pair(a);
printf("%s",a);
return 0;
}
