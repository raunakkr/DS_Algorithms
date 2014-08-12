#include<stdio.h>
void tt(int);
void main(){

tt(1);




}


void tt(int i){

while(i<6)  {
//printf("%d\n",i);
tt(i+1);
printf("%d\n",i);
return;

}

 //return;


}