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

//>>>>>>>>>>>>>>>>>Dynamic Programming implementation>>>>>
	 int is_word_breakable_DP(){

			int i,j;
			 int p[20];   //consider P[i] denotes whether str[0...i] can be breaked or not
			for(i-0;i<m;i++)p[i]=0;

			if(search_word(0,0))p[0]=1;
		 for(i=1;i<m;i++){ if(!p[i] && search_word(0,i))p[i]=1;


					  if(p[i]){
                      if(i==m-1)return 1;
							for(j=i+1;j<m;j++){

						 if(!p[j] && search_word(i+1,j))p[j]=1;

							if(j==m&&p[j])return 1;
							}


					  }  }

             return 0;
	 }

void main(){

	n= sizeof(str)/sizeof(str[0]);
	m=strlen(a);
	if(is_word_breakable(0,m-1))
		 printf("Using Recursive :: Yes\n");
		 else
		 printf("Using Recursive :: NO\n");


		 if(is_word_breakable_DP())
		 printf("Using Dynamic Programming :: Yes\n");
		 else
		 printf("Using Dynamic Programming :: NO\n");

}