//MaxClique_BB.cpp : 定义控制台应用程序的入口点。
/*
 
分支限界法求解最大团问题
*/
#include <fstream>
#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;
typedef struct{
    int v; //
无向图G的顶点
    int e; //无向图G的边
    int a[50][50]; //定义图G的
邻接矩阵
    int bestx[50]; //最优解
}MCP;
void Creat(MCP &G){
    int i,j;
    ifstream fin("data.txt");
    if(!fin)
    {
        cout<<"不能打开文件:"<<"data.txt"<<endl;
        exit(1);
    }
    fin>>G.v;
    for(int i=1;i<=G.v;i++)
        for(int j=1;j<=G.v;j++)
            fin>>G.a[i][j];
    for(i=1;i<=G.v;i++) //初始化
    {
        G.bestx[i]=0;
    }
    cout<<"————————————————————————"<<
endl;
    cout<<"———
优先队列式
分支限界法求解最大团问题———"<<endl;
    cout<<"————————————————————————"<<endl;
    cout<<"输入初始化
无向图矩阵为:"<<endl; //初始化
    for(i=1;i<=G.v;i++)
    {
        for(j=1;j<=G.v;j++)
        cout<<G.a[i][j]<<" ";
        cout<<endl;
    }
}
struct BBNode
{
    BBNode *parent; //指向父结点的指针
    bool LChild; //左儿子结点标志
};
struct CliqueNode //定义
优先队列类型为CliqueNode
{
    int cnum; //当前团的顶点数
    int un; //当前团最大顶点数的上界
    int level; //结点在子集空间树种所处的层次
    BBNode *p; //指向活结点在子集树中相应结点的指针
    bool operator<(const CliqueNode &b) const //<号
重载建立大根堆
    {
        if (b.un>un) return true;
    if (b.un==un&& b.cnum>cnum) return true;
    else return false;
   }
};
void BBMaxClique(MCP&G)
{
    BBNode *E=new(BBNode); //定义B代表记录的队列情况
    //初始化
    int j,i=1;
    int cnum=0,bestn=0;
    int OK=1;
    priority_queue<CliqueNode> Q; //定义
优先队列Q
    E->LChild=false; //初始化
    E->parent=NULL;
     
while(i!=G.v+1)//非叶结点
    {
        //检查顶点i与当前团中其它顶点之间是否有边相连
        OK=1;
        BBNode *B=E; //把当前点的数据给B，B为中间变量
        for(j=i-1;j>0;B=B->parent,j--)
        if(B->LChild&& G.a[i][j]==0) //如果不满足就停止
        {
            OK=0;
            break;
        }
        if(OK) //满足条件，即左儿子结点为可行结点
        {
            CliqueNode *D=new(CliqueNode); //定义一个节点D
            D->p=new(BBNode);
            if(cnum+1>bestn)bestn=cnum+1;
            D->cnum=cnum+1;
            D->level=i+1;
            D->p->LChild=true;
            D->p->parent=E;
            D->un=cnum+1+G.v-i;
            Q.push(*D); //进队列
        }
        if(cnum+G.v-i>bestn) //不满足条件但是还是可能有最优解
        {
            CliqueNode *D=new(CliqueNode); //定义一个节点D
            D->p=new(BBNode);
            D->cnum=cnum;
            D->level=i+1;
            D->p->LChild=false;
            D->p->parent=E;
            D->un=cnum+G.v-i;
            Q.push(*D); //进队列
        }
        CliqueNode N;
        N=Q.top(); //取队顶元素，
最大堆
        Q.pop(); //删除队顶元素
        E=N.p; //记录当前团的信息
        cnum=N.cnum; //记录当前团的顶点数
        i=N.level; //所在的层次
    }
    for(j=G.v;j>0;j--) //保存最优解
    {
        G.bestx[j]=E->LChild;
        E=E->parent;
        bestn=cnum;
    }
}
int main(){
    MCP G;
    Creat(G);
    BBMaxClique(G);
    cout<<"最大团方案为:(";
    for(int i=G.v;i>0;i--)
        if (G.bestx[i]==1){
            cout<<i<<" ";
        }
    cout<<")"<<
endl;
     
getch();
}
