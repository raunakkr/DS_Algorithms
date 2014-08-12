#include<stdio.h>

int main() {

    long long int n,i,sum=0,pro,maxt;
    scanf("%lld",&n);
    long long int *a=(long long *)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
        scanf("%lld",a[i]);

    for(i=0 ; i<n ; i++)
    {
        sum+= a[i];
        pro += (i+1)*a[i];
    }
maxt=pro;
    for(i=0 ; i<n; i++)
    {
        pro += sum;
        pro-=a[n -1-i]*n;
        if (pro>maxt)
            maxt=pro;
    }
    printf("%lld",maxt);
    return 0;
}
