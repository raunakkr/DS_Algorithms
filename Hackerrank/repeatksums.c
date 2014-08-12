#include<stdio.h>
#include<stdlib.h>

 int compare (const void * a, const void * b)
{
  return ( *(long long *)a - *(long long*)b );
}



long long num_combination(long int n,long int k) {
    long long i,p;
    if(k > n - k) {
        k = n - k;
    }
     p = 1;
    for (i = 1; i <= k; ++i) {
        p *= n + 1 - i;
        p /= i;
    }
    return p;
}

void generate_array(long long a[],long int N,long int n,long int k){
    int i,j,*p;
    qsort(a,N,sizeof(a[0]),compare);
    p=(long int *)malloc(sizeof(long int)*n);

    p[0]=a[0]/k;

j=0;
    for(i=1;i<n;i++){
            j=j+(i+k-1);
            printf(">>%d\n",j);
    p[i]=a[j-1]-(p[0]*(k-1));

    }

    for(i=0;i<n;i++)
        printf("%ld ",p[i]);

        printf("\n");



    }









int main(){

  long int t,n[100000],k[100000];
  long long *s[100000];
  long long *temp;
  long int i,j;
  long long m[100000];

  scanf("%ld",&t);

  for(i=0;i<t;i++){
   scanf("%ld %ld",&n[i],&k[i]);
   m[i]=num_combination(n[i] + k[i] - 1, k[i]);
  temp=(long long*)malloc(sizeof(long long)*100000);
  for(j=0;j<m[i];j++)
  scanf("%lld",temp+j);

  s[i]=temp;}

  for(i=0;i<t;i++)
    generate_array(s[i],m[i],n[i],k[i]);



return 0;
}
