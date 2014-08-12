#include<stdio.h>
#include<string.h>
#include<math.h>
int l,b;

void generate_dimension(char *str){
  int len=strlen(str);
  l=floor(sqrt(len));
  b=ceil(sqrt(len));
  //printf("%d-%d",l,b);


}

void print_encrypted_string(char *a){
  int i,j,n;
  n=strlen(a);
  generate_dimension(a);
  i=0;

  while(i<n && i<b){
      j=i;
    while(j<n){
            printf("%c",a[j]);
            j+=b;}

    printf(" ");
    i++;
  }

}




int main(){
 char a[81]="";
 scanf("%s",a);
 print_encrypted_string(a);
return 0;
}
