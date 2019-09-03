#include<iostream>
using namespace std;
int a[100]={1,2,3,5,12,12,12,15,29,55};//数组中的数（由小到大）
int k;//要找的数字
int found(int x,int y)
{
    int m=x+(y-x)/2;
    if(x>y)//查找完毕没有找到答案，返回-1
        return -1;
    else
    {
        if(a[m]==k)
            return m;//找到!返回位置.
        else if(a[m]>k)
            return found(x,m-1);//找左边
         else
            return found(m+1,y);//找右边
    }
}
int main()
    {
        cin>>k;//输入要找的数字c语言把cin换为scanf即可
        cout<<found(0,9);//从数组a[0]到a[9]c语言把cout换为printf即可
        return 0;
    }