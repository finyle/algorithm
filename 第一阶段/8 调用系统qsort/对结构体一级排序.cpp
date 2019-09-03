struct In 
{ 
double data; 
int other; 
}s[100] 

//按照data的值从小到大将结构体排序,关于结构体内的排序关键数据data的类型可以很多种，参考上面的例子写 

int cmp( const void *a ,const void *b) 
{ 
return (*(In *)a).data > (*(In *)b).data ? 1 : -1; 
} 

qsort(s,100,sizeof(s[0]),cmp); 
