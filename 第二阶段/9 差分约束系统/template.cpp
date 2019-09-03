#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x7fffffff
using namespace std;
const int MAXN = 1100;
const int MAXM = 30030;
 
struct EdgeNode
{
    int to;
    int w;
    int next;
}Edges[MAXM];
 
int Head[MAXN],Dist[MAXN],vis[MAXN],outque[MAXN],id;
 
void AddEdges(int u,int v,int w)
{
    Edges[id].to = v;
    Edges[id].w = w;
    Edges[id].next = Head[u];
    Head[u] = id++;
}
void SPFA(int s,int N)
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    memset(outque,0,sizeof(outque));
    for(int i = 1; i <= N; ++i)
        Dist[i] = INF;
    Dist[s] = 0;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while( !Q.empty() )
    {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        outque[u]++;
        if(outque[u] > N+1) //如果出队次数大于N，则说明出现负环
        {
            ans = -1;
            break;
        }
        for(int i = Head[u]; i != -1; i = Edges[i].next)
        {
            int temp = Dist[u] + Edges[i].w;
            if(temp < Dist[Edges[i].to])
            {
                Dist[Edges[i].to] = temp;
                if( !vis[Edges[i].to])
                {
                    vis[Edges[i].to] = 1;
                    Q.push(Edges[i].to);
                }
            }
        }
    }
 
    if(ans == -1)   //出现负权回路，不存在可行解
        printf("-1\n");
    else if(Dist[N] == INF) //可取任意值，都满足差分约束系统
        printf("-2\n");
    else
        printf("%d\n",Dist[N]);  //求使得源点 s 到 终点 t 的最大的值
}
 
int main()
{
    int N,ML,MD,u,v,w;
    while(~scanf("%d%d%d", &N, &ML, &MD))
    {
        memset(Head,-1,sizeof(Head));
        id = 0;
        for(int i = 0; i < ML; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            AddEdges(u,v,w);//建边 u - v <= w
        }
        for(int i = 0; i < MD; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            AddEdges(v,u,-w);//建边 v - u <= w
        }
//这里不加也可以
//        for(int i = 1; i < N; ++i)
//            AddEdges(i+1,i,0);
        SPFA(1,N);  //求使得源点 s 到 终点 t 的最大的值
    }
 
    return 0;
}