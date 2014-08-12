//Trim all spaces except one space between words(IN-PLACE)
#include<stdio.h>


	void swap_char(char *a,int i,int j){
        char temp;
	  if(!a || !*(a+i) || !*(a+j)){

			return;
}

	 temp=*(a+i);
	 *(a+i)=*(a+j);
	 *(a+j)=*(a+i);


	}



void trim_space(char *a){

	int s=0,n=0,flag=0;
	 if(!a)return;
	 //while there is valid charcter,move ahead stop "raju is00"  at 0, here second 0 denotes aspace

 while(1){ if(*(a+s)==' ' && s==0)break;

           if(*(a+s)==' ' && *(a+s-1)==' ')break;

			s++;n++;}

// printf("%c",*(a+s-2));return;
 while(*(a+n)){


	while(*(a+n)!=' '){swap_char(a,s,n);*(a+n)=' ';s++; if(*(a+(n+1))==' ')flag=1;}
		if(flag){s++;flag=0;}
	n++;

}

printf("%s\n",a);
printf("sorry for the disturbance");
}









void main(){

 char a[]="    this  is     i  disturbance";
trim_space(a);



}