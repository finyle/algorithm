int num[100]; 

Sample: 

int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 

qsort(num,100,sizeof(num[0]),cmp); 