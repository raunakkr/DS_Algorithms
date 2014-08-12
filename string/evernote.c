/*program to output an integer-valued list of equal length such that the output element at index 'i' is the product of all
input elements except for the input element at 'i'.  */

#include<stdio.h>
#include<stdlib.h>


void generate_array(int a[],int n){
	 int i,temp,j;
	 int product=1;
	  if(n<2) return;


	 for(i=0;i<n;i++)
	 product=product*a[i];

	//Now fill the output array
	for(i=0;i<n;i++){
		//handle "divide by zero" error
		if(a[i]==0)break;
		temp=a[i];
		a[i]=product/a[i];
		
			 }

	  //if loop breaks at any point print till that index(i) only
			for(j=0;j<i;j++)
            printf("%d\n",a[j]);


}



int main(){
  int *a;
  int i,n;
  scanf("%d",&n);
  a=(int*)(malloc(n*sizeof(int)));
 for(i=0;i<n;i++)
	 scanf("%d",a+i);
  	generate_array(a,n);


return '0';

}
