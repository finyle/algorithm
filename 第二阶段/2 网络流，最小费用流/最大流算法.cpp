#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x7fffffff
using namespace std;
int tt,kase;
int nn,m;
int H[45],X[1004],P[1004],flow[1004],tot,cap[1005];
int d[45];
int S,T;
void add(int x,int y,int z)
{
P[++tot]=y;
X[tot]=H[x];
H[x]=tot;
flow[tot]=z;
cap[tot]=flow[tot];
}
queue<int> q;
bool bfs()
{
memset(d,0,sizeof(d));
d[S]=1; 
int x;
q.push(S);
while(!q.empty()){
x=q.front();q.pop();
for(int i=H[x];i;i=X[i]){
if(flow[i]>0&&!d[P[i]]){
d[P[i]]=d[x]+1;
q.push(P[i]);
}
}
}
return d[T];
}
int dfs(int x,int a)
{
if(x==T||a==0)return a;
int f=a,tmp;
for(int i=H[x];i;i=X[i]){
if(flow[i]>0&&d[P[i]]==d[x]+1){
tmp=dfs(P[i],min(flow[i],a));
flow[i]-=tmp;
a-=tmp;
flow[i^1]+=tmp;
if(!a)break;
}
}
if(f==a)d[x]=-1;
return f-a;
}
int Dinic(){
int f=0;
while(bfs())f+=dfs(S,inf);
return f;
}
int main()
{
/**
输入过程省略
**/
int maxflow=Dinic();
printf("%d\n",maxflow);
return 0;
}
