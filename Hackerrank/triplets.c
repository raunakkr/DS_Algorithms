#include<stdio.h>
#include<stdlib.h>
//#include<map>
int ar[100010];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

long long count_distinct_increasing_triplets(int a[],int n){

qsort(a,n,sizeof(a[0]),compare);
    int i,count=0,flag=0;
    long long sum=0;

    for(i=0;i<n;i++)
      {
          while(a[i+1]==a[i]){
                flag=1;
            count++;i++;}
     if(flag){i--;flag=0;}

      }
n=n-count;n-=2;
for(i=n;i>=1;i--)
  sum+=((i*(i+1))/2);

  return sum;
}




int main()
{
long long count=0;
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&ar[i]);

// Write the code to compute the count of triplets, based on the array 'ar'
// Store it in the variable 'count'
    count=count_distinct_increasing_triplets(ar,n);
printf("%lld\n",count);
return 0;
}
