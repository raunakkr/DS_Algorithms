//Maximize xor result between two given nos. 'a' & 'b'
#include<stdio.h>

   int max(int a,int b){return a>b?a:b;}
int max_xor(int l,int r){

	 int i,j,maxt=0;
for(i=l;i<r;i++)
		 for(j=l+1;j<=r;j++)

			 maxt=max(maxt,i^j);

			 return maxt;

}



int main(){
printf("%d",max_xor(1,10));

return 0;
}
