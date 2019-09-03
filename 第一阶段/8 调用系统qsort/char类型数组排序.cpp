char word[100]; 

Sample: 

int cmp( const void *a , const void *b ) 
{ 
return *(char *)a - *(int *)b; 
} 

qsort(word,100,sizeof(word[0]),cmp); 
