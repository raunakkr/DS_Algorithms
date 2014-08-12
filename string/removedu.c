//Removing duplicate characters in a string (No extra space allowed :: o(n^2)  XXXXXXXXXXXXX
#include<stdio.h>
#include<string.h>


void remove_duplicate(char *str){
	int i,j,len,tail;
	if(!str){printf("Empty string");return;}
		  len=strlen(str);
		  tail=len-1;
	for(i=0;*(str+i);i++){
   if(tail<0)break;
		 for(j=i+1;*(str+j);j++) {

		 if(str[i]==str[j]){
				 if(str[tail]!=str[j]){
					 str[j]=str[tail];
					 str[tail]='\0';
					 tail--;
					 printf("%s\n",str); }
	  else if(j==tail && str[tail]==str[j]){
					str[tail]='\0';tail--; printf("%s\n",str); }

			 else	 {while(str[tail]==str[j])
						tail--;
						if(tail<=j){ str[j]='\0'; printf("%s\n",str);return;}

                  str[j]=str[tail];
					 str[tail]='\0';
					 tail--;
					 printf("%s\n",str);

				 }

				  


				  }



}
  }

  }




int main(){
char str[]="abbbbbbbbbbcccaabbccaa";
printf("Original String  %s\n",str);
remove_duplicate(str);
printf("Pruned String  %s",str);

return 0;}