#include<stdio.h>
#include<string.h>
void findposition();
  char a[]="rramttggt";
  int flag=0;
  int n;
  char *start=a,*end;
  //char *start=&a[0],*end=&a[2];

  void removefirstadjduplicate(){
		 while(1 && flag)
		 {
		 *start=*end;
		 if(*end=='\0'){
		 break;
		 }
		 end++;
		 start++;
	  }
		 start=a;
		 flag=0;
	 findposition();
    }



void findposition(){
int i;
if(!start)
return;

n=strlen(a);
end=start+1;
 for(i=0;i<=n-1;i++){

  if(*start!=*end && flag){
  break;
  }
  else if(*start!=*end){
  start++;
  end++;
  }
  else if(*start==*end){
  end++;
  flag=1;
  }
}
if(flag)
 removefirstadjduplicate();
 else {
 printf("%s",a);
 return;        }
}



void main(){

findposition();


}


