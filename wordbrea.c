//Word break problem recursive implementation
#include<stdio.h>
#include<string.h>

char *str[]={"s","sa","sam","sung","like","mob","sams","mobile"};

char a[]="mobsamsmobiles";

 int n,m;

//Searches word from index 'j' to 'k' index forward
int search_word(int j,int k){
	int i,c;

	 if(a[j]=='\0' || *(a+j+k)=='\0')
	 return 0;



	for(i=0;i<n;i++){

	  if(*str[i]==a[j]){
		c=0;
	  while(c<=k && *str[i]+c!='\0' && *(a+j+c)!='\0'){
		if(*(str[i]+c)==*(a+j+c)){
		  c++;

		 continue;
			}
		 else {

			 break;

			 }
			 //while ends here
			 }
		//if all characters of string has got exhausted
		 if(c==k+1 && *(str[i]+c)=='\0' ) return 1;
	}


}
  //If we are here return false simply
  return 0;


	  }


//Function to check if word break is possible
  int is_word_breakable(int i,int j){

		int x;
		 if(i>m-1)
		 return 1;



 for(x=0;x<=m-1-i;x++)
		 {
		 if(search_word(i,x) && is_word_breakable(i+x+1,m-1))
			  return 1;

		 }

	  //If we get here
		 return 0;

		}



void main(){

	n= sizeof(str)/sizeof(str[0]);
	m=strlen(a);
	if(is_word_breakable(0,m-1))
		 printf("Yes");
		 else
		 printf("NO");

}