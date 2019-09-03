//
//  main.cpp
//  POJ1422最小不想交路径覆盖
 
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 200 + 10;
vector<int> g[N];
int cy[N];
bool vis[N];
bool dfs(int u)
{
    for(int i=0; i<g[u].size(); ++i)
    {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(cy[v]==-1 || dfs(cy[v])){
            cy[v] = u;
            return true;
        }
    }
    return false;
}
int solve(int n)
{
    int ret = 0;
    memset(cy, -1, sizeof(cy));
    for(int i=1;i<=n;++i)
    {
        memset(vis, 0, sizeof(vis));
        ret += dfs(i);
    }
    return n - ret;
}
int main( )
{
    int t,n,m;
    int u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            g[i].clear();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        
        int ans = solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
