//https://baike.baidu.com/item/%E7%BD%91%E7%BB%9C%E6%B5%81/2987528?fr=aladdin


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int H[105],X[40005],P[40005],from[40005],flow[40005],cost[40005],tot;
inline void add(int x,int y,int z,int k){
P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;from[tot]=x;cost[tot]=k;
}
int f,c;
int n,m;
int S,T;
int d[105],a[105],p[105];
struct N{
int x,w;
friend bool operator < (N a,N b){
return a.w>b.w;
}
N(int a=0,int b=0){
x=a,w=b;
}
};
priority_queue<N>q;
bool spfa(){
memset(d,0x3f,sizeof(d));
d[S]=0;a[S]=inf;p[S]=0;int x;
q.push(N(S,0));
while(!q.empty()){
x=q.top().x;q.pop();
if(x==T)continue;
for(int i=H[x];i;i=X[i]){
if(flow[i]>0&&d[P[i]]>d[x]+cost[i]){
d[P[i]]=d[x]+cost[i];
a[P[i]]=min(a[x],flow[i]);
p[P[i]]=i;
q.push(N(P[i],d[P[i]]));
}
}
while(!q.empty()&&d[q.top().x]!=q.top().w)q.pop();
}
if(d[T]==inf)return 0;
f+=a[T];
c+=a[T]*d[T];
x=T;
while(x!=S){
flow[p[x]]-=a[T];
flow[p[x]^1]+=a[T];
x=from[p[x]];
}
return 1;
}
int main(){
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
Input();
while(spfa());
maxflow=f,mincost=c;
return 0;
}
