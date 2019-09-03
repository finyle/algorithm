struct In 
{ 
int x; 
int y; 
}s[100]; 

//按照x从小到大排序，当x相等时按照y从大到小排序 

int cmp( const void *a , const void *b ) 
{ 
struct In *c = (In *)a; 
struct In *d = (In *)b; 
if(c->x != d->x) return c->x - d->x; 
else return d->y - c->y; 
} 

qsort(s,100,sizeof(s[0]),cmp); 