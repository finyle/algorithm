#include <stdio.h><br />
#include <stdlib.h><br />
#include <math.h><br />
#define INF 10000<br />
#define eps 1e-8<br />
#define zero(x) (((x)>0?(x):-(x))<eps)<br />
struct point<br />
{<br />
	double x,y;<br />
};<br />
struct LINE<br />
{<br />
	point a,b;<br />
};</p>
<p>double xmult(point p1,point p2,point p0)<br />
{<br />
        return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);<br />
}</p>
<p>int pinplg(int n,point q,point* p)<br />
{<br />
        point q2;<br />
        int i=0,count;<br />
        while (i<n)<br />
                for (count=i=0,q2.x=rand()+INF,q2.y=rand()+INF;i<n;i++)<br />
                        if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)<br />
                                return 1;<br />
                        else if (zero(xmult(q,q2,p[i])))<br />
                                break;<br />
                        else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)<br />
                                count++;<br />
        return count&1;<br />
}<br />
point p[110],q;<br />
int main()<br />
{<br />
        int cas;<br />
        scanf("%d",&cas);<br />
        int n;<br />
        while(cas--)<br />
        {<br />
                scanf("%d",&n);<br />
                int i;<br />
                scanf("%lf%lf",&q.x,&q.y);<br />
                for(i=0;i<n;++i)<br />
                        scanf("%lf%lf",&p[i].x,&p[i].y);<br />
                int t;<br />
                if(pinplg(n,q,p))<br />
                        printf("yes/n");<br />
                else<br />
                        printf("no/n");<br />
        }<br />
        return 0;<br />
}<br />
