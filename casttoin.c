#include<stdio.h>
#include<string.h>
#include<math.h>

int convert_to_integer(char *a,int j){

	 int i=0,temp;
    int res=0;
	 if(!a)return 0;

 while(*(a-i)&& j>0){ temp=(int)*(a-i)-(int)'0';
				 res=res+(temp*pow(10,i));i++;
             printf(">>>%d\n",res);
				 j--;}

		return res;

}

void main(){
  char a[10];
	 int len;
//char a[]="A 6";
 //int len=strlen(a);
	scanf("%[^\n]s",a);
	len=strlen(a);
  printf("%d",convert_to_integer(a+(len-1),len-2));
}
