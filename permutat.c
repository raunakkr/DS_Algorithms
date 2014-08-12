#include<stdio.h>
#include<string.h>
void permutations(int,char *,int *,char *);
void main(){
  int depth=2;
  char permutation[4];
  char original[4]="abc";
  int used[50];
  //printf("%c",permutation);
  permutations(depth,permutation,used,original);
  getchar();
 }

void permutations(int depth,char *permutation,int *used,char *original){
 int length=strlen(original);
int i;
//printf("%d",length);
 if(depth==length)
printf("%c",permutation);
 else
 {
		for(i=0;i<length;i++){
		if(!used[i]){
			used[i]=1;
			permutation[depth]=original[i];
			permutations(depth+1,permutation,used,original);
			used[i]=0;

						}
			}}

 }

