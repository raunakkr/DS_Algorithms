//Implementation of binary search
#include<stdio.h>
  int a[5]={2,5,7,9,76};
int bs(int left,int right,int item){
int mid;
if(right<left)
return -1;
mid=(left+right)/2;
if(a[mid]==item)
return mid;
else if(item<a[mid]){
  //printf("%d%d PP\n",left,mid-1);
  return bs(left,mid-1,item);

  }
  else{
  //printf("%d%d\n",mid+1,right);
 return  bs(mid+1,right,item);
  }

 return -1;
}
void main(){
  printf("%d",bs(0,4,9));

}