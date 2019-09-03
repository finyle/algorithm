#include<stdio.h>

int maxn[1005],maxlen;

int finddate(int l,int r,int t)
{
    if (l==r)
    {
        return r;
    }
    int m=(l+r)/2;
    if (maxn[m]>t)
    {
        return finddate(l, m, t);
    }
    else
    {
        return finddate(m+1, r, t);
    }
}

int main()
{
    int n,a[1005],i;
    maxlen=1;
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    maxn[0]=a[0];
    for (i=1; i<n; i++)
    {
        if (maxn[maxlen-1]<a[i])
        {
            maxn[maxlen]=a[i];
            maxlen++;
        }
        else
        {
            maxn[finddate(0,maxlen-1,a[i])]=a[i];
        }
    }
    printf("%d\n",maxlen);
    return 0;
}
