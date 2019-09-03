/*
1.匈牙利算法
dalao：随便一个ISAP加前弧优化跑的飞快！
juruo：我们不用网络流，学不起
这是我的真实写照qaq
匈牙利算法就是一个协商与匹配的过程。
算法的主要步骤为：
1.首先从任意的一个未配对的点u开始，从点u的边中任意选一条边（假设这条边是从u->v）开始配对。如果点v未配对，则配对成功，这是便找到了一条增广路。如果点v已经被配对，就去尝试“连锁反应”，如果这时尝试成功，就更新原来的配对关系。所以这里要用一个matched[v] = u。配对成功就将配对数加1,。
2.如果刚才所选的边配对失败，那就要从点u的边中重新选一条边重新去试。直到点u 配对成功，或尝试过点u的所有边为止。
3.接下来就继续对剩下的未配对过的点一一进行配对，直到所有的点都已经尝试完毕，找不到新的增广路为止。

*/
#include <bits/stdc++.h>
#define N 1005
#define M 1000005
using namespace std;
inline int read()
{
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(register int x)
{
    if(!x)putchar('0');if(x<0)x=-x,putchar('-');
    static int sta[25];int tot=0;
    while(x)sta[tot++]=x%10,x/=10;
    while(tot)putchar(sta[--tot]+48);
}
struct node{
    int to,next;
}e[M];
int head[N],tot=0;
inline void add(register int u,register int v)
{
    e[++tot]=(node){v,head[u]};
    head[u]=tot;
}
int n,m,es,ans;
int ask[N<<1],matched[N<<1];
inline bool found(register int x)
{
    for(register int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(ask[v])
            continue;
        ask[v]=1;
        if(!matched[v]||found(matched[v]))
        {
            matched[v]=x;
            return true;
        }
    }
    return false;
}
inline void match()
{
    for(register int i=1;i<=n;++i)
    {
        memset(ask,0,sizeof(ask));
        if(found(i))
            ++ans;
    }
}
int main()
{
    n=read(),m=read(),es=read();
    while(es--)
    {
        int u=read(),v=read();
        if(v>m)
            continue;
        add(u,v+n); 
    }   
    match();
    write(ans);
    return 0;
} 