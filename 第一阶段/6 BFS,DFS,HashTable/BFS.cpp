structNode
{
int x;
int y;
int step;
Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}
};
intBFS()
{
Nodenode(0,0,0);
queue<Node>q;
while(!q.empty())q.pop();
q.push(node);
while(!q.empty())
{
node=q.front();
q.pop();
if(node.x==n-1&&node.y==n-1)
{
returnnode.step;
}
visit[node.x][node.y]=1;
for(int i=0;i<4;i++)
{
intx=node.x+stepArr[i][0];
inty=node.y+stepArr[i][1];
if(x>=0&&y>=0&&x<n&&y<n&&visit[x][y]==0&&mazeArr[x][y]==0)
{
visit[x][y]=1;
Nodenext(x,y,node.step+1);
q.push(next);
}
}
}
return-1;
}