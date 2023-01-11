#include <iostream>
#include <cstring>
#include <queue>
#define MAX(a,b) (a > b ? a : b)
using namespace std;

typedef pair<int,int> point;
char a;
int r, c;
int mat[60][60];
bool vis[60][60];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ans = 0;
void bfs(int _x, int _y){
    queue <pair<point,int> > q;
    q.push(make_pair(make_pair(_x,_y),0));
    pair<point,int> cur;

    memset(vis,0,sizeof(vis));
    vis[_x][_y] = true;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int dist = cur.second;
        for(int k = 0 ; k < 4 ;k++){
            if(mat[x + dx[k]][y + dy[k]] == 1 && !vis[x + dx[k]][y + dy[k]]){
                q.push(make_pair(make_pair(x + dx[k],y + dy[k]),dist + 1));
                vis[x + dx[k]][y + dy[k]] = true;
            }
        }
    }
    
    ans = MAX(ans,cur.second);
}

int main(){
    cin >> r >> c;
    for(int i = 1 ; i <= r ;i++){
        for(int j = 1 ; j <= c ;j++){
            cin >> a;
            if(a == 'W')
                mat[i][j] = 0;
            else if(a == 'L')
                mat[i][j] = 1;
        }
    }
    
    for(int i = 1 ; i <= r ;i++){
        for(int j = 1 ; j <= c ;j++){
            if(mat[i][j] == 1){
                bfs(i,j);
            }
        }
    }
    cout << ans;  
}