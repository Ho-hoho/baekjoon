#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

int N, M, res = INF;
int mat[1010][1010];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dist[1010][1010][2]; 

class Info{
    public : 
    int x;
    int y;
    int cost;
    int coin;
    Info (int _x, int _y, int _cost, int _coin){
        x = _x;
        y = _y;
        cost = _cost;
        coin = _coin;
    }
    
};

bool operator< (const Info& s1, const Info& s2){
    return s1.cost > s2.cost;
}

void solve(){
    priority_queue <Info> pq;
    dist[1][1][0] = 1;
    pq.push(Info(1,1,1,0));
    while(!pq.empty()){
        Info cur = pq.top(); pq.pop();
        if(cur.x == N && cur.y == M){
            res =  cur.cost;
            break;
        }
        //cout << cur.x << " " << cur.y << "\n";
        for(int k = 0 ; k < 4;k++){
            int nx = dx[k] + cur.x;
            int ny = dy[k] + cur.y;
            if(mat[nx][ny] == 0 && dist[nx][ny][cur.coin] > cur.cost + 1){
                dist[nx][ny][cur.coin] = cur.cost + 1;
                pq.push(Info(nx,ny,cur.cost + 1,cur.coin));
            }
            else if(mat[nx][ny] == 1 && cur.coin == 0 && dist[nx][ny][1] > cur.cost + 1){
                dist[nx][ny][1] = cur.cost + 1;
                pq.push(Info(nx,ny,cur.cost + 1,1));
            }
        }
    }
}

int main (){
    cin >> N >> M;
    cout << "@@@@@@\n";
    for(int i  = 0 ; i <= N + 1; i++){
        for(int j = 0 ; j <= M + 1; j++){
            if( i == 0 || i == N + 1 || j == 0 || j == M + 1)
                mat[i][j] = 2;
            else
                scanf("%1d",&mat[i][j]);
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
        }
    }
    solve();
    if(res != INF)
        cout << res;
    else
        cout << -1;
}