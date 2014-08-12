//Program to find nearest square root of given integer
#include<stdio.h>


float square_root(int z)
{
    float n=(float)z;
  float x = n;
  float y = 1;
  float e = 0.000001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}



void main(){

printf("%d",(int)(square_root(27)+0.5));


}