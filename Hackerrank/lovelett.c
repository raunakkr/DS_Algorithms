#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int min_cost_to_convert_to_palindrome(char *str){

		int len=strlen(str);
		int cost=0;
		int i=0;int j=len-1;

		while(i<=j){

		  if(*(str+i)!=*(str+j))
			  cost+=abs((int)*(str+j)-(int)*(str+i));

           i++;j--;

}
	return cost;

}








int main(){
  int i,t;
  char *a[10];
	char *temp;
  scanf("%d",&t);

 for(i=0;i<t;i++){
	temp=(char*)malloc(sizeof(char)*10000);
	 scanf("%s",temp);
	 a[i]=temp;}

	 for(i=0;i<t;i++)
  printf("%d\n",min_cost_to_convert_to_palindrome(a[i]));

return 0;
}