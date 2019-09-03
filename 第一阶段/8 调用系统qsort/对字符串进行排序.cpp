struct In 
{ 
int data; 
char str[100]; 
}s[100]; 

//按照结构体中字符串str的字典顺序排序 

int cmp ( const void *a , const void *b ) 
{ 
return strcmp( (*(In *)a)->str , (*(In *)b)->str ); 
} 

qsort(s,100,sizeof(s[0]),cmp); 