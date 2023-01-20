#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> point;
int N, M,cnt = 0,t = 0, tcnt = 0;
int mat[110][110];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[110][110];
queue <point> q;

void bfs(){
    q.push(make_pair(0,0));
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ;j++)
            vis[i][j] = false;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4 ;k++){
            if(curx + dx[k] >= 0 && curx + dx[k] < N && cury + dy[k] >= 0 && cury + dy[k] < M){
                if (mat[curx + dx[k]][cury + dy[k]] == 0 && !vis[curx + dx[k]][cury + dy[k]]){
                    q.push(make_pair(curx + dx[k],cury + dy[k]));
                    vis[curx + dx[k]][cury + dy[k]] = true;
                }
                else if(mat[curx + dx[k]][cury + dy[k]] == 1 && !vis[curx + dx[k]][cury + dy[k]]){
                    vis[curx + dx[k]][cury + dy[k]] = true;
                    mat[curx + dx[k]][cury + dy[k]] = 0;
                    tcnt++;
                }
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            cin >> mat[i][j];
            if(mat[i][j])
                cnt++;
        }
    }
    while(++t){
        bfs();
        if(cnt == tcnt)
            break;
        cnt -= tcnt;
        tcnt = 0;
    }
    cout << t << "\n" << cnt;
}