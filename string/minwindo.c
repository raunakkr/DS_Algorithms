//Find the minimum window containing all characters of given dtring
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int *count_a;
 int *copy_count;
void build_count_array(char *txt){
	count_a=(int*)calloc(256,sizeof(int));
	while(*txt){
	  count_a[(int)(*txt)-(int)'a']++;
	  txt++;
	}
}
	int mint(int a,int b){return a<b?a:b;}
void build_copy_of_count(){
	int i=0;

	copy_count=(int*)calloc(256,sizeof(int));
	while(i<256){
		 copy_count[i]=count_a[i];
		 i++;

	}
}
int min_window(char *txt,char *p){
	int n,i,start,flag,count;

	int window=0;
	int min_window=99;
	int len=strlen(p);
	count=0;start=0;  flag=0;
	n=strlen(txt);

	if(!p || !txt)return 0;
	  build_count_array(p);
	  build_copy_of_count();
	  while(!copy_count[(int)(txt[start])-(int)'a']){start++;}//move to first matching character
		if(len==1 && txt[start]==*p)return 1;else if(len==1) return min_window;
	  while(start<n){
		 i=start;
		 count=0;  //reset count

					 while(i<n){

						 if(copy_count[(int)(txt[i])-(int)'a']){copy_count[(int)(txt[i])-(int)'a']--;count++; }
							 window++;i++;
						  if(count==len){min_window=mint(min_window,window);}
							  if(count_a[(int)(txt[i])-(int)'a'] && !flag){flag=i;}
                       if(count==len) break;
								 }

								 if(count!=len)break;
				build_copy_of_count(txt);
				start=flag;
				flag=0;
            window=0;


	  }

	  return min_window;

}

void main(){
  int i=0;char txt[]="prvpr";
  char p[]="vr";
  


printf("Minimum window is  %d",min_window(txt,p));




}