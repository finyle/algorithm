#include<stdio.h>
#include<stdlib.h>
#define max 1000000000
int a[1001][1001],d[1001],p[1001];
int main(){
int i,j,k,m,n,min,ans,t;
int x,y,z;
scanf("%d%d",&n,&m);
for(i=1;i<=m;i++){
scanf("%d%d%d",&x,&y,&z);
a[x][y]=z;
a[y][x]=z;
}
for(i=1;i<=n;i++)
d[i]=1000000000;
d[1]=0;
for(i=2;i<=n;i++){
min = max;
for(j=1;j<=n;j++)
if(!p[j]&&min>d[j])
min=d[j];
t=j;
}
p[t]=j;
for(j=1;j<=n;j++)
if(a[t][j]=0&&d[j]>a[t][j]){
d[j]=a[t][j];
ans+=min;
}
printf("%d",ans);
return 0;
}