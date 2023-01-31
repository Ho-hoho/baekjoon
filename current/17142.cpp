#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MIN(a,b) a > b ? b : a;
using namespace std;
typedef pair<int,int> point;

int N , M;
int zcnt=0,vcnt=0,ans = 987654321;
int mat[51][51];
int vis[51][51];
int dx[4]= {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector <point> virus;
vector <point> actv;

void bfs(){
    int tick=0, cnt=0;
    queue <point> q;
    
    memset(vis,-1,sizeof(vis));
    for(auto i : actv){
        q.push(i);
        vis[i.first][i.second] = 0;
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
            if(x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < N){
                if(vis[x + dx[k]][y + dy[k]] == -1){
                    if(mat[x + dx[k]][y + dy[k]] == 0){
                        q.push(make_pair(x + dx[k],y + dy[k]));
                        vis[x + dx[k]][y + dy[k]] = vis[x][y] + 1;
                        tick = vis[x][y] + 1;
                        cnt++;
                    }
                    else if(mat[x + dx[k]][y + dy[k]] == 2){
                        q.push(make_pair(x + dx[k],y + dy[k]));
                        vis[x + dx[k]][y + dy[k]] = vis[x][y] + 1;
                    }
                }
            }
        }
    }
    if(cnt == zcnt)
        ans = MIN(ans,tick);
    return;
    
}

void chooseVirus(int idx, int num){
    if(num > M || idx > vcnt)
        return ;
    if(num == M){
        bfs();
        return;
    }
    actv.push_back(virus[idx]);
    chooseVirus(idx + 1, num + 1);
    actv.pop_back();
    chooseVirus(idx + 1,num);
}

int main (){
    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 0)
                zcnt++;
            else if (mat[i][j] == 2)
                virus.push_back(make_pair(i,j));
        }
    }
    vcnt = virus.size();
    chooseVirus(0,0);
    if(ans == 987654321)
        cout << -1;
    else
        cout << ans;
}