//Program to reach destination with minimum distance covered using direction notation "N" "E" "W" "S" (FLIPKART INTEVIEW)
#include<stdio.h>



 void min_distance(char *str){

	int x,y,p,q;
	if(!str)return;
	x=5;y=5;
	while(*str){

		if(*str=='E') y++;
		if(*str=='W') y--;
		if(*str=='N') x--;
		if(*str=='S') x++;

		str++;
	}
		//printf("%d-%d\n",x,y);
		p=5;q=5;


      	if(y>q){
		while(y>q){
		printf("E");
		q++;   }
		}

			if(x<p){
		while(x<p){
		printf("N");
		p--; }
}

	if(x>p){
		while(x>p){
		printf("S");
		p++;  }
}


					if(y<q){
		while(y<q){
		printf("W");
		q--;  }
}








 }








int main(){

  char str[]="NESNWES";

	min_distance(str);



}