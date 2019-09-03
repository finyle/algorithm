double in[100]; 

int cmp( const void *a , const void *b ) 
{ 
return *(double *)a > *(double *)b ? 1 : -1; 
} 

qsort(in,100,sizeof(in[0]),cmp)；