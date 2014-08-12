							//Program to find the height of Utopian tree after N cycles
#include<stdio.h>

//Rteurns height of tree
int find_height(int n){

int i;
    //Stores current height of tree
int cur_height=1;
//Denotes season:: '1' for monsoon & '2' for summer
    int flag=1;    
      	if(n==0 ||n<0)
    return 1;
    
 for(i=1;i<=n;i++){
     //toggle flag (we can use XOR for this
    if(flag==1) 
     cur_height=2*cur_height;
     
     else if(flag==2)
     cur_height++;
     
     //Toggle flag here
     flag=(flag==1)?2:1;
     
 }   
    
 return cur_height;   
}




int main(){
  int i,t,n[10];
  scanf("%d\n",&t);
  //handle if t>10 & <1
	 for(i=0;i<t;i++)
		 scanf("%d",&n[i]);

		for(i=0;i<t;i++)
		 printf("%d\n",find_height(n[i])); 
    
    return 0;
    
    
}