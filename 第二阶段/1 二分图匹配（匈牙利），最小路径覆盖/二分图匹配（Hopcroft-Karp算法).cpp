//https://www.cnblogs.com/yzhang-rp-inf/p/10079578.html

/*
这个算法的效率比匈牙利算法的效率高，复杂度为O(n−−√e)，但很容易写挂，不适合考场上写（蒟蒻的想法）
该算法的主要思想是在每次增广的时候不是找一条增广路而是同时找几条不相交的最短增广路，形成极大增广路集，随后可以沿着这几条增广路同时进行增广。
可以证明在寻找增广路集的每一个阶段所寻找到的最短增广路都具有相等的长度，并且随着算法的进行最短增广路的长度是越来越长的，更进一步的分析可以证明最多只需要增广ceil(sqrt(n))次就可以得到最大匹配（证明在这里略去）。
因此现在的主要难度就是在O(e)的时间复杂度内找到极大最短增广路集，思路并不复杂，首先从所有X的未盖点进行BFS，BFS之后对每个X节点和Y节点维护距离标号，如果Y节点是未盖点那么就找到了一条最短增广路，BFS完之后就找到了最短增广路集，随后可以直接用DFS对所有允许弧(dist[y]=dist[x]+1)进行类似于匈牙利中寻找增广路的操作，这样就可以做到O(e)的复杂度。
*/

/*
dx[i]表示左集合i顶点的距离编号
dy[i]表示右集合i顶点的距离编号
mx[i]表示左集合顶点所匹配的右集合顶点序号
my[i]表示右集合i顶点匹配到的左集合顶点序号
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
int dx[N],dy[N],mx[N],my[N],vis[N],dis;
inline bool bfs()
{
    queue<int> q;
    dis=1926081700;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(register int i=1;i<=n;++i)
        if(mx[i]==-1)
        {
            q.push(i);
            dx[i]=0;
        }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(dx[u]>dis)
            break;
        for(register int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(my[v]==-1)
                    dis=dy[v];
                else
                {
                    dx[my[v]]=dy[v]+1;
                    q.push(my[v]);
                        }       
            }   
        }
    }
    return dis!=1926081700;
}
inline bool dfs(register int u)
{
    for(register int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v]||(dy[v]!=dx[u]+1))
            continue;
        vis[v]=1;
        if(my[v]!=-1&&dy[v]==dis)
            continue;
        if(my[v]==-1||dfs(my[v]))
        {
            my[v]=u;
            mx[u]=v;
            return true;
        }
    }
    return false;
}
inline void match()
{
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    while(bfs())
    {
        memset(vis,0,sizeof(vis));
        for(register int i=1;i<=n;++i)
            if(mx[i]==-1&&dfs(i))
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
        add(u,v);   
    }   
    match();
    write(ans);
    return 0;
} 