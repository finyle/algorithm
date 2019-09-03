/*
题目大意 ： 
就是给你一堆线段 问你是否存在这样一条直线 使得所有线段在直线上的投影均有公共部分 有输出Yes 没有输出No

解题方法 ： 
投影直线上有公共点的话就是说这条直线存在一个垂线经过所有线段 就是与所有线段均相交

只要枚举这些线段端点所确定的直线 是否存在一条与所有线段均相交即可

判断线段相交用的是叉乘 首先用两点p1,p2确定了一条直线 在用p1,p2分别与计算线段两个端点计算叉乘即可 
叉乘之积>0就说明线段两端点在直线的同侧 也就是直线不经过此线段

注意 ： 
本题是double类型 
判断是否有重点 重点定义为坐标非常接近的两点 <1e-8即可 
判断叉乘之积时 只要<1e-8 即可

*/
#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
#define MAXM 110
#define EPS 1e-8

typedef struct{
    double x1,y1,x2,y2;
}Segment;

Segment segment[MAXM];
int n;

double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double corss(double x1,double y1,double x2,double y2,double x,double y){
    return (x2-x1)*(y-y1)-(x-x1)*(y2-y1);
}

bool judge(double x1,double y1,double x2,double y2){
    int i;
    if(distance(x1,y1,x2,y2)<EPS) return 0;
    for(i=0;i<n;i++){
        if(corss(x1,y1,x2,y2,segment[i].x1,segment[i].y1)*
            corss(x1,y1,x2,y2,segment[i].x2,segment[i].y2)>EPS) return 0;
    }
    return 1;
}

int main(){
    int t,i,j,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&segment[i].x1,&segment[i].y1,&segment[i].x2,&segment[i].y2);
        if(n==1) {printf("Yes!\n");continue;}

        ans=0;
        for(i=0;i<n && !ans;i++)
            for(j=i+1;j<n && !ans;j++){
                if(judge(segment[i].x1,segment[i].y1,segment[j].x1,segment[j].y1) ||
                    judge(segment[i].x1,segment[i].y1,segment[j].x2,segment[j].y2) ||
                    judge(segment[i].x2,segment[i].y2,segment[j].x1,segment[j].y1) ||
                    judge(segment[i].x2,segment[i].y2,segment[j].x2,segment[j].y2))
                    ans=1;
            }
        if(ans) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}

