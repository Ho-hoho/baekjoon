#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MIN(a,b) a > b ? b : a 
typedef pair<int,pair<int,int> > point;
int N,a,cnt = 1,ans = 987654321;
int mat[110][110];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[110][110];

void dfs(int x, int y){
    mat[x][y] = cnt;
    for(int k = 0 ; k < 4 ; k++){
        if(mat[x + dx[k]][y + dy[k]] > 0 && !vis[x + dx[k]][y + dy[k]]){
            vis[x + dx[k]][y + dy[k]] = true;
            dfs(x + dx[k],y + dy[k]);
        }
    }
}

void bfs(int x, int y, int land){
    priority_queue < point, vector<point>, greater<point> > q;
    q.push(make_pair(0,make_pair(x,y)));
    memset(vis,false,sizeof(vis));
    vis[x][y] = true;
    while(!q.empty()){
        int curdis = q.top().first;
        int curx = q.top().second.first;
        int cury = q.top().second.second;
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
            if(mat[curx + dx[k]][cury + dy[k]] != -1 && !vis[curx + dx[k]][cury + dy[k]]){
                if(mat[curx + dx[k]][cury + dy[k]] == 0){
                    vis[curx + dx[k]][cury + dy[k]] = true;
                    q.push(make_pair(curdis + 1, make_pair(curx + dx[k],cury + dy[k])));
                }
                else if(mat[curx + dx[k]][cury + dy[k]] != land){
                    ans = MIN(ans,curdis);
                    return;
                }
            }
            
        }
    }

}

int main (){
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> a;
            mat[i][j] = a;
        } 
    }
    for(int i = 0 ; i <= N + 1; i++){
        mat[i][0] = -1;
        mat[0][i] = -1;
        mat[N+1][i] = -1;
        mat[i][N+1] = -1;
    }

    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            if(mat[i][j] > 0 && !vis[i][j]){
                vis[i][j] = true;
                dfs(i,j);
                cnt++;
            }
        }
    }
    
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            if(mat[i][j] > 0){
                bfs(i,j,mat[i][j]);
            }
        }
    }
    cout << ans;
}