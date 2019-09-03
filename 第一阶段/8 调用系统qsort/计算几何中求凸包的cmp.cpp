int cmp(const void *a,const void *b) //重点cmp函数，把除了1点外的所有点，旋转角度排序 
{ 
struct point *c=(point *)a; 
struct point *d=(point *)b; 
if( calc(*c,*d,p[1]) < 0) return 1; 
else if( !calc(*c,*d,p[1]) && dis(c->x,c->y,p[1].x,p[1].y) < dis(d->x,d->y,p[1].x,p[1].y)) //如果在一条直线上，则把远的放在前面 
return 1; 
else return -1; 
} 