 
#include <stdio.h>
#include <math.h>
const int N = 100010;
int mark[N];
struct Point
{
    double x,y;
};
struct stline
{
    Point a,b;
} line1,line2, p[N];
 
int dblcmp(double a,double b)
{
    if (fabs(a-b)<=1E-6) return 0;
    if (a>b) return 1;
    else return -1;
}
//***************点积判点是否在线段上***************
double dot(double x1,double y1,double x2,double y2) //点积
{
    return x1*x2+y1*y2;
}
 
int point_on_line(Point a,Point b,Point c) //求a点是不是在线段bc上，>0不在，=0与端点重合，<0在。
{
    return dblcmp(dot(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y),0);
}
//**************************************************
double cross(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
double ab_cross_ac(Point a,Point b,Point c) //ab与ac的叉积
{
    return cross(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int ab_cross_cd (Point a,Point b,Point c,Point d) //求ab是否与cd相交，交点为p。1规范相交，0交点是一线段的端点，-1不相交。
{
    double s1,s2,s3,s4;
    int d1,d2,d3,d4;
    Point p;
    d1=dblcmp(s1=ab_cross_ac(a,b,c),0);
    d2=dblcmp(s2=ab_cross_ac(a,b,d),0);
    d3=dblcmp(s3=ab_cross_ac(c,d,a),0);
    d4=dblcmp(s4=ab_cross_ac(c,d,b),0);
 
//如果规范相交则求交点
    if ((d1^d2)==-2 && (d3^d4)==-2)
    {
        p.x=(c.x*s2-d.x*s1)/(s2-s1);
        p.y=(c.y*s2-d.y*s1)/(s2-s1);
        return 1;
    }
 
//如果不规范相交
    if (d1==0 && point_on_line(c,a,b)<=0)
    {
        p=c;
        return 0;
    }
    if (d2==0 && point_on_line(d,a,b)<=0)
    {
        p=d;
        return 0;
    }
    if (d3==0 && point_on_line(a,c,d)<=0)
    {
        p=a;
        return 0;
    }
    if (d4==0 && point_on_line(b,c,d)<=0)
    {
        p=b;
        return 0;
    }
//如果不相交
    return -1;
}