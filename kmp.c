#include<stdio.h>
int f[7];

void prefixtable(char p[],int m){
int i=1,j=0;
f[0]=0;
while(i<m){
 if(p[i]==p[j])
 {
	 f[i]=j+1;
	 i++;
	 j++;

 }
	else if (j>0)
		  j=f[j-1];
		  else {
			 f[i]=0;
			 i++;
				 }

}




}



int kmp(char t[],int n,char p[],int m){

	 int i=0,j=0;
	 prefixtable(p,m);
	 while(i<n){
		if(t[i]==p[j]){
			 if(j==m-1)
			  return i-j;
			  else{
			  i++;
			  j++;
			  }


	 }

	 else if (j>0)
			 j=f[j-1];
			 else i++;
}


  return -1;

  }







void main(){
char p[8]={'a','b','a','b','a','c','a'};
int m=7;
char t[]="bacbabababacaca";
int n=15;





 printf("%d",kmp(t,n,p,m));





}