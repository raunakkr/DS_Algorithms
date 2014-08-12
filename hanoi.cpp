//Program for recursive hanoi tower

#include<stdio.h>


//'s' for source 'd' for destination 'n' for number of disks and 'h' for helper


void hanoi(char s,char d,char h,int n){

 if(n==1) {
 printf("Move from %c to %c\n",s,d);
 return; }

 hanoi(s,h,d,n-1);

 printf("Move from %c to %c\n",s,d);

 hanoi(h,d,s,n-1);


}






void main(){


 int n=10;
 hanoi('A','C','B',n);




}