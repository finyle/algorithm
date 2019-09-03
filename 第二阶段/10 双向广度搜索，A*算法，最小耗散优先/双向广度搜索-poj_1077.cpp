
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
 
typedef int State[9];
const int M = 1000000;
State st[M], goal;
//int dist[M];
int pre[M];
char move[M];
 
const int HASH_SIZE = M+3;
int head[HASH_SIZE], next[HASH_SIZE];
 
void init_lookup_table()
{
    memset(head, 0, sizeof(head));
    memset(next, 0, sizeof(next));
}
 
bool legal(int x, int y)
{
    return 0 <= x && x < 3 && 0 <= y && y < 3;
}
 
int hash(State& s)
{
    int t = 0;
    for (int i = 0; i < 9; i++) t = t * 10 + s[i];
    return t % HASH_SIZE;
}
 
bool try_to_insert(int k)
{
    int h = hash(st[k]);
    int u = head[h];
    while (u) {
        if (memcmp(st[u], st[k], sizeof(st[k])) == 0) return false;
        u = next[u];
    }
    next[k] = head[h];
    head[h] = k;
    return true;
}
 
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const char move_type[] = "drul";
int BFS()
{
    init_lookup_table();
 
    int front = 1, rear = 2;
    while (front < rear) {
        State& s = st[front];
        if (memcmp(goal, s, sizeof(s)) == 0)
            return front;
        int z;
        for (z = 0; z < 9; z++) if (!s[z]) break;
        int x = z/3, y = z%3;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (legal(nx, ny)) {
                int nz = nx*3 + ny;
                State& t = st[rear];
                memcpy(t, s, sizeof(s));
                swap(t[z], t[nz]);
                if (try_to_insert(rear)) {
                    //dist[rear] = dist[front] + 1;
                    pre[rear] = front;
                    move[rear] = move_type[i];
                    rear++;
                }
            }
        }
        front ++;
    }
    return 0;
}
        
int main(void)
{   
    char str[2];
    for (int i = 0; i < 9; i++) {
        scanf("%s", str);
        st[1][i] = (str[0] == 'x') ? 0 : str[0]-'0';
        goal[i] = (i+1)%9; 
    } 
    //dist[1] = 0;
 
    int step = BFS();
    vector<char> res;
    while (step != 1) { 
        res.push_back(move[step]);
        step = pre[step];
    }   
    for (int i = res.size()-1; i >= 0; i--)
        printf("%c", res[i]);
    printf("\n");
        
    return 0;
}</span>
