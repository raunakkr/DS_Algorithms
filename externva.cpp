#include<stdio.h>
void fun();
int i=4;
void main(){

fun();



}

void fun (){
if(i==10)return;
printf("%d",i);
  i++;
fun();

}