#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct _point{
    int x;
    int y;
}point;

vector <point> cloud;
vector <point> rained;
vector <pair<int,int> > dir;
int mat[51][51];
bool vis[51][51];
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int a, b, ep,ans = 0;
int N,M;

void move_cloud(){
    vector<point> ret;
    for(int i = 0 ; i < cloud.size(); i++){
        point cur = cloud[i];
        cloud[i].x = (cloud[i].x + dx[dir[ep].first] * dir[ep].second) % N;
        if(cloud[i].x < 0) cloud[i].x += N;
        cloud[i].y = (cloud[i].y + dy[dir[ep].first] * dir[ep].second) % N;
        if(cloud[i].y < 0) cloud[i].y += N;
    }
}

void rain(){
    memset(vis,false,sizeof(vis));
    rained.clear();
    for(point cur : cloud){
        mat[cur.x][cur.y] += 1;
        vis[cur.x][cur.y] = true;
        rained.push_back(cur);
    }
}

void copy_water(){
    for(point cur : rained){
        for(int k = 2 ; k <= 8; k += 2){
            if(cur.x + dx[k] >= 0 && cur.x + dx[k] < N && cur.y + dy[k] >= 0 && cur.y + dy[k] < N){
                if(mat[cur.x + dx[k]][cur.y + dy[k]]){
                    mat[cur.x][cur.y] += 1;
                }
            }
        }
    }
}

void change_cloud(){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            if(!vis[i][j] && mat[i][j] >= 2){
                mat[i][j] -= 2;
                point newp;
                newp.x = i;
                newp.y = j;
                cloud.push_back(newp);
            }
        }
    }
}

void simul(){
    move_cloud();
    rain();
    cloud.clear();
    copy_water();
    change_cloud();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0 ; i < M ;i++){
        cin >> a >> b;
        dir.push_back({a,b});
    }
    point cur;
    cur.x = N-1; cur.y = 0; cloud.push_back(cur);
    cur.x = N-1; cur.y = 1; cloud.push_back(cur);
    cur.x = N-2; cur.y = 0; cloud.push_back(cur);
    cur.x = N-2; cur.y = 1; cloud.push_back(cur);
    for(ep = 0 ; ep < dir.size(); ep++){
        simul();
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            if(mat[i][j])
                ans+= mat[i][j];
        }
    }
    cout << ans;
    return 0;
}