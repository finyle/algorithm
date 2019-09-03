/*
并查集，在一些有N个元素的集合应用问题中，我们通常是在开始时让每个元素构成一个单元素的集合，然后按一定顺序将属于同一组的元素所在的集合合并，其间要反复查找一个元素在哪个集合中。这一类问题近几年来反复出现在信息学的国际国内赛题中，其特点是看似并不复杂，但数据量极大，若用正常的数据结构来描述的话，往往在空间上过大，计算机无法承受；即使在空间上勉强通过，运行的时间复杂度也极高，根本就不可能在比赛规定的运行时间（1～3秒）内计算出试题需要的结果，只能用并查集来描述。
并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。常常在使用中以森林来表示。
*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int fa[50002],a,b,m,n,p;
/*
x代表例题中的人，fa[x]中所存的数代表这一集合中所有人都与一个人有亲戚关系
相当于例题中第一个集合所有的元素都与第一个元素有亲戚关系
搜索时只要找元素所指向的fa[x]=x的元素(即父元素)
然后比较两个元素的父元素是否相同就可以判断其关系
*/
void build(int qwq) {for(int i=1;i<=qwq;i++) fa[i]=i;return ;}//初始化，一开始每个点单独成集合 
int find(const int &x) {return fa[x]==x?x:fa[x]=find(fa[x]);}//找到x的最远祖先，并且压缩路径
bool che(const int &x,const int &y){return find(x)==find(y);}//判断x,y是不是在同一个集合里，直接判断最远祖先是不是一样的 
void mer(const int &x,const int &y) {if(!che(x,y)) fa[fa[x]]=fa[y];return ;}
//合并x,y，我们在判断x和y是不是同一个集合里，路径压缩之后fa[x],fa[y]已经是最远祖先了，所以直接将fa[x]的父亲连接起来就好 
int main()
{
  int i;
  scanf("%d%d%d",&n,&m,&p);
  build(n);
  for(i=1;i<=m;i++)
  {
        scanf("%d%d",&a,&b),
        mer(a,b);
    }
  for(i=1;i<=p;i++)
    {
      scanf("%d%d",&a,&b);
      if(che(a,b))
        printf("Yes\n");
      else
        printf("No\n");
    }
  return 0;
}