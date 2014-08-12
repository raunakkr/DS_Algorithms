			 #include <stdio.h>
int main() {
	int a[25];
	 int i,n=3;
	 scanf("%d",&n);
	 for(i=0;i<n;i++){
		scanf("%d",&a[i]);   }
	  //	printf(">>>>>>>>>>>>>>>>%d",a[i]);}

	 //Iterate array for finding missing number

	 for(i=0;i<n-2;i++){

		  if(a[i]+a[i+2]!=2*a[i+1] && i>0){
			  //this is missing spot;
			 printf("%d",a[i+1]+a[i+1]-a[i]);
			 printf("mmm%d\n",i);
				break;}

			if(a[i]+a[i+2]!=2*a[i+1] && (i==0)){
				 printf("%d-%d-%d",a[i],a[i+1],a[i+2]);
					printf("mmm%d\n",i);
				 break;}

	 }






	 return 0;

}